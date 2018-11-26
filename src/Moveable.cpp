#ifndef MOVEABLE_CPP_
#define MOVEABLE_CPP_


#include "Moveable.h"

Moveable::Moveable(){}

SDL_Rect* Moveable::getpos(){
	return (&(this->botton_pos));
}

SDL_Surface* Moveable::getsurf(){
	return this->botton_surface.at(this->current_path)->get_surface();
}

int Moveable::get_id(){
	return this->id;
}

bool Moveable::is_in(SDL_Rect selected){
	bool result=false;
	int min_x=selected.x-(selected.w/2);
	int min_y=selected.y-(selected.h/2);
	int max_x=selected.x+(selected.w/2);
	int max_y=selected.y+(selected.h/2);
	int m_min_x=this->botton_pos.x;
	int m_min_y=this->botton_pos.y;
	int m_max_x=this->botton_pos.x+this->botton_pos.w;
	int m_max_y=this->botton_pos.y+this->botton_pos.h;
	if((min_x<=m_min_x)&&(min_y<=m_min_y)&&(max_x>=m_max_x)&&(max_y>=m_max_y)){
		result=true;
	}
	return result;
}


SDL_Rect* Moveable::get_converted_pos(int x,int y){
	this->converted_pos.w=this->botton_pos.w;
	this->converted_pos.h=this->botton_pos.h;
	this->converted_pos.x=this->botton_pos.x-x;
	this->converted_pos.y=this->botton_pos.y-y;
	return (&(this->converted_pos));
}


bool Moveable::is_inside_screen(int x, int y, int size_x, int size_y){
	int min_x=this->botton_pos.x;
	int min_y=this->botton_pos.y;
	int max_x=this->botton_pos.x+this->botton_pos.w;
	int max_y=this->botton_pos.x+this->botton_pos.w;
	return ((min_x<x+size_x)&&(min_y<y+size_y)&&(max_x>x)&&(max_y>y));
}


bool Moveable::is_cosechadora(){
	return false;
}



int Moveable::h_size(){
	return this->botton_pos.w;
}

int Moveable::v_size(){
	return this->botton_pos.h;
}

int Moveable::y_pos(){
	return this->botton_pos.y;
}

int Moveable::x_pos(){
	return this->botton_pos.x;
}

bool Moveable::click_is_inside_moveable(int x, int y){
	int x_from=(this->botton_pos.x+AJUSTE);
	int x_to=(this->botton_pos.x+this->botton_pos.w-AJUSTE);
	int y_from=this->botton_pos.y+AJUSTE;
	int y_to=this->botton_pos.y+this->botton_pos.h-AJUSTE;
	bool correct=((x>=x_from)&&(x<=x_to)&&(y>=y_from)&&(y<=y_to));
	return correct;
}

int Moveable::get_team(){
	return this->team;
}


void Moveable::set_id(int i){
	this->id=i;
}


void Moveable::set_team(int i){
	this->team=i;
}

void Moveable::set_w(int i){
	this->botton_pos.w=i;	
}

void Moveable::set_h(int i){
	this->botton_pos.h=i;	
}

void Moveable::set_x(int i){
	this->botton_pos.x=i;	
}

void Moveable::set_y(int i){
	this->botton_pos.y=i;	
}

	
void Moveable::add_surface(std::string text){
	std::shared_ptr<Surface>s (new Surface(text));
	this->botton_surface.push_back(s);
}


void Moveable::set_current(int i){
	this->current_path=i;
}

Moveable::~Moveable(){}
	

#endif /* MOVEABLE_CPP_ */

