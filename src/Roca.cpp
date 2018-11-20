#include "Roca.h"


Roca::Roca(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Surface> surf(new Surface("imgs/Terreno/Roca.png"));
	this->id=id;
	this->botton_pos.w=size_x;
	this->botton_pos.h=size_y;
	this->botton_pos.x=x;
	this->botton_pos.y=y;
	this->botton_surface=surf;
	this->especia=false;
}
	

Roca::~Roca(){}

