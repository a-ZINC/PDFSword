#pragma once

#include<vector>
#include<string>
#include<iostream>
#include"CSVType.h"
#include<qpdf/QPDF.hh>
#include<qpdf/QPDFPageDocumentHelper.hh>
#include<qpdf/QPDFWriter.hh>
#include<filesystem>

class PDFSplit {
private:
	QPDF inpdf;
	const char* pdfFileName;
	std::vector<Book> chapters;
	int maxPdfPage;
	std::vector<QPDFPageObjectHelper> pages;
public:
	PDFSplit(const char* pfn, std::vector<Book>& c, int mpp);
	void process();
	void processByChapter(int chapterNumber, int subparts, Book& book, int totalSubparts, std::filesystem::path root);
};