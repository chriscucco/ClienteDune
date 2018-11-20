#include "Button_CuartelHarkonnen.h"



Button_CuartelHarkonnen::Button_CuartelHarkonnen(int i,int size_x, int size_y,int x,int y){
	this->id=i;
	this->botton_pos.w=size_x;
	this->botton_pos.h=size_y;
	this->botton_pos.x=x;
	this->botton_pos.y=y;
	std::shared_ptr<Surface> s1(new Surface("imgs/Botones/CuartelHarkonnen.png"));
	this->botton_surface=s1;
}


Button_CuartelHarkonnen::~Button_CuartelHarkonnen(){}
