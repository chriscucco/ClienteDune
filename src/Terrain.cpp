#ifndef TERRAIN_CPP_
#define TERRAIN_CPP_

#include "Terrain.h"


Terrain::Terrain(){}


int Terrain::get_id(){
	return this->id;
}


SDL_Rect* Terrain::getpos(){
	return (&(this->botton_pos));
}


SDL_Surface* Terrain::getsurf(){
	return this->botton_surface->get_surface();
}


bool Terrain::is_in_click(int x, int y){
	bool result=false;
	int min_x=this->botton_pos.x;
	int min_y=this->botton_pos.y;
	int max_x=this->botton_pos.x+this->botton_pos.w;
	int max_y=this->botton_pos.y+this->botton_pos.h;
	if((min_x<=x)&&(min_y<=y)&&(max_x>=x)&&(max_y>=y)){
		result=true;
	}
	return result;
}

bool Terrain::is_inside_screen(int x, int y, int size_x, int size_y){
	int min_x=this->botton_pos.x;
	int min_y=this->botton_pos.y;
	int max_x=this->botton_pos.x+this->botton_pos.w;
	int max_y=this->botton_pos.y+this->botton_pos.h;
	return ((min_x<x+size_x)&&(min_y<y+size_y)&&(max_x>x)&&(max_y>y));
}


SDL_Rect* Terrain::get_converted_pos(int x,int y){
	this->converted_pos.w=this->botton_pos.w;
	this->converted_pos.h=this->botton_pos.h;
	this->converted_pos.x=this->botton_pos.x-x;
	this->converted_pos.y=this->botton_pos.y-y;
	return (&(this->converted_pos));
}


int Terrain::h_size(){
	return this->botton_pos.w;
}


int Terrain::v_size(){
	return this->botton_pos.h;
}


int Terrain::y_pos(){
	return this->botton_pos.y;
}


int Terrain::x_pos(){
	return this->botton_pos.x;
}


bool Terrain::is_especia(){
	return this->especia;
}


Terrain::~Terrain(){}


#endif 