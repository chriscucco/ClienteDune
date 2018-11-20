#include "SonicTank.h"

SonicTank::SonicTank(int id,int size_x, int size_y, int x, int y, int team){
	this->id=id;
	this->botton_pos.w=size_x;
	this->botton_pos.h=size_y;
	this->botton_pos.x=x;
	this->botton_pos.y=y;
	std::shared_ptr<Surface> s1(new Surface("imgs/Vehiculos/SonicTank/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/Vehiculos/SonicTank/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/Vehiculos/SonicTank/3.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/Vehiculos/SonicTank/4.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/Vehiculos/SonicTank/5.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/Vehiculos/SonicTank/6.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/Vehiculos/SonicTank/7.png"));
	std::shared_ptr<Surface> s8(new Surface("imgs/Vehiculos/SonicTank/8.png"));
	this->botton_surface.push_back(s1);
	this->botton_surface.push_back(s2);
	this->botton_surface.push_back(s3);
	this->botton_surface.push_back(s4);
	this->botton_surface.push_back(s5);
	this->botton_surface.push_back(s6);
	this->botton_surface.push_back(s7);
	this->botton_surface.push_back(s8);
	this->current_path=2;
	this->team=team;
	this->cosechadora=false;
}

SonicTank::~SonicTank(){}


