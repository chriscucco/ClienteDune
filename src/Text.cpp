#include "Text.h"


Text::Text(SDL_Renderer* r,std::string t ,int size_x, int size_y, int x, int y, int iterations){
	this->renderer=r;
	this->botton_pos.w=size_x;
	this->botton_pos.h=size_y;
	this->botton_pos.x=x;
	this->botton_pos.y=y;
	this->text=t;
	this->repeats=iterations;
	this->has_to_actualize=true;
}


SDL_Rect* Text::getpos(){
	return (&(this->botton_pos));
}

void Text::modify_value(int i){
	this->value=i;
	this->has_to_actualize=true;
}

int Text::get_remains(){
	return this->repeats;
}


void Text::modify_texture(){
	if (this->repeats>0){
		std::shared_ptr<Surface> s(new Surface('t',this->text));
		this->surf=s;
	} else {
		std::string num=std::to_string(this->value);
		std::string t=this->text+num;
		std::shared_ptr<Surface> s(new Surface('t',t));
		this->surf=s;
	}
}

SDL_Surface* Text::get_surface(){
	if(has_to_actualize){
		this->modify_texture();
		this->has_to_actualize=false;
	}
	return this->surf->get_surface();
}


Text::~Text(){}