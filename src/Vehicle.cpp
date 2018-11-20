
#ifndef VEHICLE_CPP_
#define VEHICLE_CPP_

#include "Vehicle.h"



void Vehicle::modify_pos(int x, int y){
	if(x>this->botton_pos.x){
		if(y>this->botton_pos.y){
			this->current_path=3;
		} else if (y<this->botton_pos.y){
			this->current_path=1;
		} else {
			this->current_path=2;
		}
	} else if (x<this->botton_pos.x){
		if(y>this->botton_pos.y){
			this->current_path=5;
		} else if (y<this->botton_pos.y){
			this->current_path=7;
		} else {
			this->current_path=6;
		}
	} else {
		if(y>this->botton_pos.y){
			this->current_path=4;
		} else if (y<this->botton_pos.y){
			this->current_path=0;
		} 
	}
	this->botton_pos.x=x;
	this->botton_pos.y=y;
}

bool Vehicle::is_cosechadora(){
	return this->cosechadora;
}


#endif
