#ifndef TIMER_CPP_
#define TIMER_CPP_

#include "Timer.h"
#include <chrono>
#include <thread>


Timer::Timer(int frames){
	this->time=high_resolution_clock::now();
	std::this_thread::sleep_for(std::chrono::milliseconds(30));
	high_resolution_clock::time_point current=high_resolution_clock::now();
	this->dur=duration_cast<duration<double>>(current-this->time);
}


void Timer::reset(){
	this->time=high_resolution_clock::now();
}


int Timer::remain_time(){
	high_resolution_clock::time_point current=high_resolution_clock::now();
	duration<double> actual_duration=duration_cast<duration<double>>(current-this->time);
	this->time=current;
	float sleep=(this->dur.count()-actual_duration.count());
	sleep=1000*sleep;
	return (int)sleep;
}


Timer::~Timer(){}
	
#endif