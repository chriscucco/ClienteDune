#include "Button_CentroDeConstruccion.h"




Button_CentroDeConstruccion::Button_CentroDeConstruccion(int i,int size_x, int size_y,int x, int y, std::shared_ptr<Surface> s){
	this->id=i;
	this->botton_pos.w=size_x;
	this->botton_pos.h=size_y;
	this->botton_pos.x=x;
	this->botton_pos.y=y;
	this->botton_surface=s;
}


Button_CentroDeConstruccion::~Button_CentroDeConstruccion(){}
	

	