#include "EspeciaFuerte.h"


EspeciaFuerte::EspeciaFuerte(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Surface> surf(new Surface("imgs/Terreno/EspeciaFuerte.png"));
	this->id=id;
	this->botton_pos.w=size_x;
	this->botton_pos.h=size_y;
	this->botton_pos.x=x;
	this->botton_pos.y=y;
	this->botton_surface=surf;
	this->especia=true;
}
	

EspeciaFuerte::~EspeciaFuerte(){}
