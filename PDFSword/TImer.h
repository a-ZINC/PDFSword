#pragma once

#include<chrono>
#include<iostream>
#include<string>

class Timer {
private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<double> diff;

	std::chrono::time_point<std::chrono::steady_clock> tickStart, tickEnd;
	std::chrono::duration<double> tickDiff;
public:
	Timer();
	~Timer();

	void mark();
	void unmark(std::string name);
};