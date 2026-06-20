#include"CSVMapper.h"
#include"CSVType.h"


template<>
Book CSVMapper<Book>::map(std::vector<std::string>& rows) {
	return Book{ rows[0], std::stoi(rows[1]), std::stoi(rows[2]) };
}

template<>
std::vector<std::string> CSVMapper<std::vector<std::string>>::map(std::vector<std::string>& rows) {
	return rows;
}