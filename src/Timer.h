#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <stdio.h>
#include <fstream>
#include <string>
#include <unistd.h>
#define MILIMETER 1000

using namespace std::chrono;

class Timer{
private:
	duration<double> dur;
	high_resolution_clock::time_point time;
	int lenght_of_frame;
public:
	Timer(int frames);
	void reset();
	bool has_to_actualize();
	~Timer();
};

