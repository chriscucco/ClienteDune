
#ifndef WARRIOR_CPP_
#define WARRIOR_CPP_
#include "Warrior.h"


void Warrior::modify_pos(int x, int y){
	this->is_attacking=false;
	if(x>this->botton_pos.x){
		if(this->current_path==2){
			this->current_path=3;
		} else {
			this->current_path=2;
		}
	} else if(x<this->botton_pos.x){
		if(this->current_path==6){
			this->current_path=7;
		} else {
			this->current_path=6;
		}
	} else if(y<this->botton_pos.y){
		if(this->current_path==0){
			this->current_path=1;
		} else {
			this->current_path=0;
		}
	} else if(y>this->botton_pos.y){
		if(this->current_path==4){
			this->current_path=5;
		} else {
			this->current_path=4;
		}
	}
	this->botton_pos.x=x;
	this->botton_pos.y=y;
}

SDL_Surface* Warrior::getsurf(){
	bool has_to_actualize=false;
	if(!this->is_attacking){
		return this->botton_surface.at(this->current_path)->get_surface();
	} else {
		if(this->iterator==this->let_pass){
			this->iterator=0;
			if((this->current_path==3)||(this->current_path==7)||(this->current_path==11)||(this->current_path==15)){
				has_to_actualize=true;
			}
			int actual=this->current_path;
			if(has_to_actualize){
				this->current_path=this->current_path-3;
			} else {
				this->current_path++;
			}
			return this->attack_surfaces.at(actual)->get_surface();
		} else {
			this->iterator++;
			return this->attack_surfaces.at(this->current_path)->get_surface();
		}
	}
} 


void Warrior::attack(int x,int y){
	this->is_attacking=true;
	if(x>this->botton_pos.x){
		this->current_path=4;
	} else if(x<this->botton_pos.x){
		this->current_path=12;
	} else if(y<this->botton_pos.y){
		this->current_path=0;
	} else {
		this->current_path=8;
	}
}
	

#endif
