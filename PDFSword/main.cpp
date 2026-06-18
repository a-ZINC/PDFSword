#include<iostream>
#include<string>
#include<qpdf/QPDF.hh>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Pdf name not provided" << std::endl;
		return 1;
	}

	const char* name = argv[1];
	std::cout << name << std::endl;

	QPDF qpdf;
	qpdf.processFile(name);
	const std::vector<QPDFObjectHandle>& pages = qpdf.getAllPages();
	if (pages.empty()) {
		std::cout << "empty" << std::endl;
		return 0;
	}
	std::cout << "out of scope" << std::endl;

	for (auto& p : pages) {
		std::string str;
		bool pageFetch = p.getJSON(0).getString(str);
		std::cout << str  << std::endl;
	}
	return 0;
}