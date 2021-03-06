#ifndef BUTTON_CPP_
#define BUTTON_CPP_

#include "Button.h"

Button::Button(){}

Button::Button(int i,int size_x, int size_y,int x, int y, std::shared_ptr<Surface> s){
	this->id=i;
	this->botton_pos.w=size_x;
	this->botton_pos.h=size_y;
	this->botton_pos.x=x;
	this->botton_pos.y=y;
	this->botton_surface=s;
}
	
	
SDL_Rect* Button::getpos(){
	return (&(this->botton_pos));
}

int Button::get_id(){
	return this->id;
}


bool Button::click_is_inside_button(int x, int y){
	int x_from=(this->botton_pos.x);
	int x_to=(this->botton_pos.x+this->botton_pos.w);
	int y_from=this->botton_pos.y;
	int y_to=this->botton_pos.y+this->botton_pos.h;
	bool correct=((x>=x_from)&&(x<=x_to)&&(y>=y_from)&&(y<=y_to));
	return correct;
}


SDL_Surface* Button::getsurf(){
	return this->botton_surface->get_surface();
}

Button::~Button(){}

#endif 