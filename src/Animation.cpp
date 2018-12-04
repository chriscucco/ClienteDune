#ifndef ANIMATION_CPP_
#define ANIMATION_CPP_

#include "Animation.h"



Animation::Animation(){}


SDL_Surface* Animation::getsurf(){
	if(this->iterative>=this->let_pass){
		this->iterative=0;
		this->current_path++;
	} else {
		this->iterative++;
	}
	return this->botton_surface.at(this->current_path)->get_surface();
}


SDL_Rect* Animation::getpos(){
	return (&(this->botton_pos));
}


bool Animation::finished(){
	return (this->current_path==this->botton_surface.size()-1);
}


bool Animation::is_inside_screen(int x, int y, int size_x, int size_y){
	int min_x=this->botton_pos.x;
	int min_y=this->botton_pos.y;
	int max_x=this->botton_pos.x+this->botton_pos.w;
	int max_y=this->botton_pos.y+this->botton_pos.h;
	return ((min_x<x+size_x)&&(min_y<y+size_y)&&(max_x>x)&&(max_y>y));
}


SDL_Rect* Animation::get_converted_pos(int x,int y){
	this->converted_pos.w=this->botton_pos.w;
	this->converted_pos.h=this->botton_pos.h;
	this->converted_pos.x=this->botton_pos.x-x;
	this->converted_pos.y=this->botton_pos.y-y;
	return (&(this->converted_pos));
}


Animation::~Animation(){}


#endif