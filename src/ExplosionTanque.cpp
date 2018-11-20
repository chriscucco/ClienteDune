#include "ExplosionTanque.h"


ExplosionTanque::ExplosionTanque(int size_x, int size_y, int x, int y){
	this->botton_pos.w=size_x;
	this->botton_pos.h=size_y;
	this->botton_pos.x=x;
	this->botton_pos.y=y;
	std::shared_ptr<Surface> s1(new Surface("imgs/Explosion/ExplosionTanque/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/Explosion/ExplosionTanque/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/Explosion/ExplosionTanque/3.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/Explosion/ExplosionTanque/4.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/Explosion/ExplosionTanque/5.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/Explosion/ExplosionTanque/6.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/Explosion/ExplosionTanque/7.png"));
	std::shared_ptr<Surface> s8(new Surface("imgs/Explosion/ExplosionTanque/8.png"));
	std::shared_ptr<Surface> s9(new Surface("imgs/Explosion/ExplosionTanque/9.png"));
	std::shared_ptr<Surface> s10(new Surface("imgs/Explosion/ExplosionTanque/10.png"));
	std::shared_ptr<Surface> s11(new Surface("imgs/Explosion/ExplosionTanque/11.png"));
	std::shared_ptr<Surface> s12(new Surface("imgs/Explosion/ExplosionTanque/12.png"));
	std::shared_ptr<Surface> s13(new Surface("imgs/Explosion/ExplosionTanque/13.png"));
	std::shared_ptr<Surface> s14(new Surface("imgs/Explosion/ExplosionTanque/14.png"));
	this->botton_surface.push_back(s1);
	this->botton_surface.push_back(s2);
	this->botton_surface.push_back(s3);
	this->botton_surface.push_back(s4);
	this->botton_surface.push_back(s5);
	this->botton_surface.push_back(s6);
	this->botton_surface.push_back(s7);
	this->botton_surface.push_back(s8);
	this->botton_surface.push_back(s9);
	this->botton_surface.push_back(s10);
	this->botton_surface.push_back(s11);
	this->botton_surface.push_back(s12);
	this->botton_surface.push_back(s13);
	this->botton_surface.push_back(s14);
	this->current_path=0;
	this->iterative=0;
	this->let_pass=2;
}

ExplosionTanque::~ExplosionTanque(){}


