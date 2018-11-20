#include "Sardaukar.h"


Sardaukar::Sardaukar(int id,int size_x, int size_y, int x, int y, int team){
	this->id=id;
	this->botton_pos.w=size_x;
	this->botton_pos.h=size_y;
	this->botton_pos.x=x;
	this->botton_pos.y=y;
	std::shared_ptr<Surface> s1(new Surface("imgs/Sardaukar/Movible/Arriba/1.png"));
	std::shared_ptr<Surface> s2(new Surface("imgs/Sardaukar/Movible/Arriba/2.png"));
	std::shared_ptr<Surface> s3(new Surface("imgs/Sardaukar/Movible/Derecha/1.png"));
	std::shared_ptr<Surface> s4(new Surface("imgs/Sardaukar/Movible/Derecha/2.png"));
	std::shared_ptr<Surface> s5(new Surface("imgs/Sardaukar/Movible/Abajo/1.png"));
	std::shared_ptr<Surface> s6(new Surface("imgs/Sardaukar/Movible/Abajo/2.png"));
	std::shared_ptr<Surface> s7(new Surface("imgs/Sardaukar/Movible/Izquierda/1.png"));
	std::shared_ptr<Surface> s8(new Surface("imgs/Sardaukar/Movible/Izquierda/2.png"));
	this->botton_surface.push_back(s1);
	this->botton_surface.push_back(s2);
	this->botton_surface.push_back(s3);
	this->botton_surface.push_back(s4);
	this->botton_surface.push_back(s5);
	this->botton_surface.push_back(s6);
	this->botton_surface.push_back(s7);
	this->botton_surface.push_back(s8);
	std::shared_ptr<Surface> s10(new Surface("imgs/Sardaukar/Ataque/Arriba/0.png"));
	std::shared_ptr<Surface> s11(new Surface("imgs/Sardaukar/Ataque/Arriba/1.png"));
	std::shared_ptr<Surface> s12(new Surface("imgs/Sardaukar/Ataque/Arriba/2.png"));
	std::shared_ptr<Surface> s13(new Surface("imgs/Sardaukar/Ataque/Arriba/3.png"));
	std::shared_ptr<Surface> s14(new Surface("imgs/Sardaukar/Ataque/Derecha/0.png"));
	std::shared_ptr<Surface> s15(new Surface("imgs/Sardaukar/Ataque/Derecha/1.png"));
	std::shared_ptr<Surface> s16(new Surface("imgs/Sardaukar/Ataque/Derecha/2.png"));
	std::shared_ptr<Surface> s17(new Surface("imgs/Sardaukar/Ataque/Derecha/3.png"));
	std::shared_ptr<Surface> s18(new Surface("imgs/Sardaukar/Ataque/Abajo/0.png"));
	std::shared_ptr<Surface> s19(new Surface("imgs/Sardaukar/Ataque/Abajo/1.png"));
	std::shared_ptr<Surface> s20(new Surface("imgs/Sardaukar/Ataque/Abajo/2.png"));
	std::shared_ptr<Surface> s21(new Surface("imgs/Sardaukar/Ataque/Abajo/3.png"));
	std::shared_ptr<Surface> s22(new Surface("imgs/Sardaukar/Ataque/Izquierda/0.png"));
	std::shared_ptr<Surface> s23(new Surface("imgs/Sardaukar/Ataque/Izquierda/1.png"));
	std::shared_ptr<Surface> s24(new Surface("imgs/Sardaukar/Ataque/Izquierda/2.png"));
	std::shared_ptr<Surface> s25(new Surface("imgs/Sardaukar/Ataque/Izquierda/3.png"));
	this->attack_surfaces.push_back(s10);
	this->attack_surfaces.push_back(s11);
	this->attack_surfaces.push_back(s12);
	this->attack_surfaces.push_back(s13);
	this->attack_surfaces.push_back(s14);
	this->attack_surfaces.push_back(s15);
	this->attack_surfaces.push_back(s16);
	this->attack_surfaces.push_back(s17);
	this->attack_surfaces.push_back(s18);
	this->attack_surfaces.push_back(s19);
	this->attack_surfaces.push_back(s20);
	this->attack_surfaces.push_back(s21);
	this->attack_surfaces.push_back(s22);
	this->attack_surfaces.push_back(s23);
	this->attack_surfaces.push_back(s24);
	this->attack_surfaces.push_back(s25);
	this->current_path=2;
	this->team=team;
	this->is_attacking=false;
}

Sardaukar::~Sardaukar(){}

