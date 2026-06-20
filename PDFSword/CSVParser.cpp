#include "CSVParser.h"

CSVParser::CSVParser() {
}

CSVParser& CSVParser::getCSVParser() {
	static CSVParser csvParser;
	return csvParser;
};

template<typename T>
std::vector<T> CSVParser::parse(std::string fileName) {
	std::ifstream inFile(fileName);
	std::string line;
	std::vector<T> rows;

	rows.reserve(100);
	if (inFile.is_open()) {
		while (std::getline(inFile, line)) {
			std::stringstream ss(line);
			std::string element;
			std::vector<std::string> row;
			while (std::getline(ss, element, ',')) {
				row.emplace_back(std::move(element));
			}
			rows.emplace_back(CSVMapper<T>::map(row));
		}
		inFile.close();
	}
	else {
		std::cerr << "File could'nt be opened!\n";
	}
	return rows;
};

template<typename T>
void CSVParser::print(std::vector<T>& rows) const {
	int count = 0;
	for (T& r : rows) {
		std::cout << r;
		std::cout << "\n";
		if (++count > 0) {
			break;
		}
	}
}

template std::vector<Book> CSVParser::parse<Book>(std::string fileName);
template std::vector<std::vector<std::string>> CSVParser::parse<std::vector<std::string>>(std::string fileName);

template void CSVParser::print<Book>(std::vector<Book>& rows) const;
//template void CSVParser::print<std::vector<std::string>>(std::vector<std::vector<std::string>>& rows) const;