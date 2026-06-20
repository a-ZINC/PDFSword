#pragma once

#include<vector>
#include<string>

template<typename T>
struct CSVMapper {
    static T map(std::vector<std::string>& rows);
};

