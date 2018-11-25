#include "Button_Cosechadora.h"


Button_Cosechadora::Button_Cosechadora(int i,int size_x, int size_y,int x,int y, std::shared_ptr<Surface> s){
	this->id=i;
	this->botton_pos.w=size_x;
	this->botton_pos.h=size_y;
	this->botton_pos.x=x;
	this->botton_pos.y=y;
	this->botton_surface=s;
}


Button_Cosechadora::~Button_Cosechadora(){}

