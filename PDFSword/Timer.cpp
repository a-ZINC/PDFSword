#include "Timer.h"

Timer::Timer() : start(std::chrono::high_resolution_clock::now()), diff(std::chrono::duration<double>(0)) {}
Timer::~Timer() {
	end = std::chrono::high_resolution_clock::now();
	diff = end - start;
	std::cout << "Scope Based Timer: " << diff.count() << "s\n";
}

void Timer::mark() {
	tickStart = std::chrono::high_resolution_clock::now();
};
void Timer::unmark(std::string name) {
	tickEnd = std::chrono::high_resolution_clock::now();
	tickDiff = tickEnd - tickStart;
	std::cout << "[" << name << "]: " << tickDiff.count() << "s\n";
}


