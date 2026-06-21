#include<iostream>
#include<string>
#include<qpdf/QPDF.hh>
#include"CSVParser.h"
#include"Timer.h"
#include"PDFSplit.h"

int main(int argc, char* argv[]) {
	Timer t;
	if (argc < 3) {
		std::cout << "Invalid arguments" << std::endl;
		return 1;
	}

	const char* csvFilePath = argv[1];
	std::cout << csvFilePath << std::endl;

	const char* pdfFilePath = argv[2];
	std::cout << pdfFilePath << std::endl;

	int maxChapterSize = std::atoi(argv[3]);

	t.mark();
	CSVParser& csvParser = CSVParser::getCSVParser();
	std::vector<Book> rows = csvParser.parse<Book>(csvFilePath);
	t.unmark("CSV PARSING");

	t.mark();
	csvParser.print(rows);
	t.unmark("CSV PRINT");

	PDFSplit pdfProcessor(pdfFilePath, rows, maxChapterSize);
	std::cout << "intiated" << std::endl;
	t.mark();
	pdfProcessor.process();
	t.unmark("PDF SPLIT");
	
	return 0;
}