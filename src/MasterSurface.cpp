#ifndef MASTERSURFACE_CPP_
#define MASTERSURFACE_CPP_

#include "MasterSurface.h"


MasterSurface::MasterSurface(){
	this->init_trike();
}


void MasterSurface::init_trike(){
	std::shared_ptr<Surface> s1(new Surface("imgs/Vehiculos/Trike/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/Vehiculos/Trike/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/Vehiculos/Trike/3.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/Vehiculos/Trike/4.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/Vehiculos/Trike/5.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/Vehiculos/Trike/6.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/Vehiculos/Trike/7.png"));
	std::shared_ptr<Surface> s8(new Surface("imgs/Vehiculos/Trike/8.png"));
	this->trike.push_back(s1);
	this->trike.push_back(s2);
	this->trike.push_back(s3);
	this->trike.push_back(s4);
	this->trike.push_back(s5);
	this->trike.push_back(s6);
	this->trike.push_back(s7);
	this->trike.push_back(s8);
}


std::vector<std::shared_ptr<Surface>> MasterSurface::get_trike_surface(){
	return this->trike;
}


MasterSurface::~MasterSurface(){}



#endif