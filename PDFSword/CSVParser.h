#pragma once

#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include "CSVMapper.h"
#include "CSVType.h"

class CSVParser {
private:
	CSVParser();
public:
	static CSVParser& getCSVParser();

	template<typename T>
	std::vector<T> parse(std::string fileName);
	
	template<typename T>
	void print(std::vector<T>& rows) const;
};