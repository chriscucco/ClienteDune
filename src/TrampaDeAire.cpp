#include "TrampaDeAire.h"
#include <memory>



TrampaDeAire::TrampaDeAire(int id,int size_x, int size_y, int x, int y, int team, std::shared_ptr<Surface> s){
	this->id=id;
	this->botton_pos.w=size_x;
	this->botton_pos.h=size_y;
	this->botton_pos.x=x;
	this->botton_pos.y=y;
	this->team=team;
	this->botton_surface=s;
}

TrampaDeAire::~TrampaDeAire(){}

