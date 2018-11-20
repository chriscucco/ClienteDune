#ifndef STATIC_CPP_
#define STATIC_CPP_

#include "Static.h"


Static::Static(){}

	
int Static::get_id(){
	return this->id;
}


SDL_Rect* Static::getpos(){
	return (&(this->botton_pos));
}

	
int Static::h_size(){
	return this->botton_pos.w;
}


int Static::v_size(){
	return this->botton_pos.h;
}


int Static::y_pos(){
	return this->botton_pos.y;
}


int Static::x_pos(){
	return this->botton_pos.x;
}


int Static::mine(){
	return this->team;
}


bool Static::click_is_inside_static(int x, int y){
	int x_from=(this->botton_pos.x+AJUSTE);
	int x_to=(this->botton_pos.x+this->botton_pos.w-AJUSTE);
	int y_from=this->botton_pos.y+AJUSTE;
	int y_to=this->botton_pos.y+this->botton_pos.h-AJUSTE;
	bool correct=((x>=x_from)&&(x<=x_to)&&(y>=y_from)&&(y<=y_to));
	return correct;
}


SDL_Surface* Static::getsurf(){
	return this->botton_surface->get_surface();
}


Static::~Static(){}


#endif 