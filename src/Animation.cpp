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


Animation::~Animation(){}


#endif