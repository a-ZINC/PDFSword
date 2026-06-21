#include"PDFSplit.h"

PDFSplit::PDFSplit(const char* pfn, std::vector<Book>& c, int mpp) : pdfFileName(pfn), chapters(c), maxPdfPage(mpp) {
	inpdf.processFile(pdfFileName);
	pages = QPDFPageDocumentHelper(inpdf).getAllPages();
}

void PDFSplit::process() {
	std::filesystem::path curr_dir = std::filesystem::current_path();
	std::filesystem::path new_folder_path = curr_dir / "Book";

	if (std::filesystem::create_directory(new_folder_path)) {
		std::cout << "Success! Created folder at: " << new_folder_path << std::endl;
	}
	else {
		std::cout << "Folder already exists or could not be created." << std::endl;
	}
	for (int i = 0; i < chapters.size(); i++) {
		Book& book = chapters[i];
		int diff = book.end - book.start;
		int numberOfSubparts = (diff / maxPdfPage) + 1;
		for (int sub = 0; sub < numberOfSubparts; sub++) {
			std::cout << "Started processing chapter: " << i << ", subpart: " << sub << "\n";
			processByChapter(i, sub, book, numberOfSubparts, new_folder_path);
		}
	}
}

void PDFSplit::processByChapter(int chapterNumber, int subparts, Book& book, int totalSubparts, std::filesystem::path root) {
	int newStart = book.start + (subparts * maxPdfPage);
	int newEnd = book.end - ((totalSubparts - 1 - subparts) * maxPdfPage);
	std::string outfileName = std::to_string(chapterNumber) + std::string("_") + book.chapter + std::string("_") + std::to_string(subparts + 1) + ".pdf";
	std::string outPath = (root / outfileName).string();
	QPDF outpdf;
	outpdf.emptyPDF();
	std::cout << "starting" << std::endl;
	while (newStart < newEnd) {
		QPDFPageDocumentHelper(outpdf).addPage(pages[newStart++], false);
	}
	std::cout << "Done" << outfileName <<std::endl;
	try {
		QPDFWriter outpdfw(outpdf, outPath.c_str());
		outpdfw.write();
		std::cout << "write done" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "QPDF ERROR: " << e.what() << std::endl;
	}
}