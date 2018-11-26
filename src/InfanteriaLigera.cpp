#include "InfanteriaLigera.h"



InfanteriaLigera::InfanteriaLigera(int id,int size_x, int size_y, int x, int y, int team,std::vector<std::shared_ptr<Surface>> v1,std::vector<std::shared_ptr<Surface>> v2){
	this->id=id;
	this->botton_pos.w=size_x;
	this->botton_pos.h=size_y;
	this->botton_pos.x=x;
	this->botton_pos.y=y;
	this->botton_surface=v1;
	this->attack_surfaces=v2;
	this->current_path=2;
	this->team=team;
	this->is_attacking=false;
}

InfanteriaLigera::~InfanteriaLigera(){}


