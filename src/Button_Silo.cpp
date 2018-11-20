#include "Button_Silo.h"


Button_Silo::Button_Silo(int i,int size_x, int size_y, int x, int y){
	this->id=i;
	this->botton_pos.w=size_x;
	this->botton_pos.h=size_y;
	this->botton_pos.x=x;
	this->botton_pos.y=y;
	std::shared_ptr<Surface> s1(new Surface("imgs/Botones/Silo.png"));
	this->botton_surface=s1;
}


Button_Silo::~Button_Silo(){}

