
#include "Timer.h"


Timer::Timer(int frames){
	this->time=high_resolution_clock::now();
	this->dur=duration_cast<duration<double>>(this->time-this->time);
	this->lenght_of_frame=1000/frames;
}

void Timer::reset(){
	this->time=high_resolution_clock::now();
	this->dur=duration_cast<duration<double>>(this->time-this->time);
}

bool Timer::has_to_actualize(){
	high_resolution_clock::time_point current=high_resolution_clock::now();
	duration<double> actual_duration=duration_cast<duration<double>>(current-this->time);
	this->dur+=actual_duration;
	if((this->dur.count()*MILIMETER)>=this->lenght_of_frame){
		this->reset();
		return true;
	} else {
		this->time=current;
		return false;
	}
}


Timer::~Timer(){}
	