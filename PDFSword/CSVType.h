#pragma once

#include<string>
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
struct Book {
	std::string chapter;
	int start;
	int end;
};

inline std::ostream& operator<<(std::ostream& os, Book& b) {
	os << b.chapter << "," << b.start << "," << b.end;
	return os;
}

inline std::ostream& operator<<(std::ostream& os, std::vector<std::string >& b) {
	for (std::string& s : b) {
		os << s;
	}
	return os;
}