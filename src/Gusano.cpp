#include "Gusano.h"


Gusano::Gusano(int size_x, int size_y, int x, int y,std::vector<std::shared_ptr<Surface>> s){
	this->botton_pos.w=size_x;
	this->botton_pos.h=size_y;
	this->botton_pos.x=x;
	this->botton_pos.y=y;
	this->botton_surface=s;
	this->current_path=0;
	this->iterative=0;
	this->let_pass=2;
}

Gusano::~Gusano(){}


