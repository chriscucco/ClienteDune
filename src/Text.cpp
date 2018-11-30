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

void Text::modify_id(int i){
	this->value=i;
}

int Text::get_value(){
	return this->value;
}

bool Text::click_is_inside_text(int x, int y){
	int x_from=(this->botton_pos.x+AJUSTE);
	int x_to=(this->botton_pos.x+this->botton_pos.w-AJUSTE);
	int y_from=this->botton_pos.y+AJUSTE;
	int y_to=this->botton_pos.y+this->botton_pos.h-AJUSTE;
	bool correct=((x>=x_from)&&(x<=x_to)&&(y>=y_from)&&(y<=y_to));
	return correct;
}

int Text::get_x(){
	return this->botton_pos.x;
}


int Text::get_y(){
	return this->botton_pos.y;
}


int Text::get_w(){
	return this->botton_pos.w;
}


int Text::get_h(){
	return this->botton_pos.h;
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
		std::shared_ptr<Surface> s(new Surface('f',t));
		this->surf=s;
	}
}


void Text::printed(){
	this->repeats=this->repeats-1;
}


SDL_Surface* Text::get_surface(){
	if(has_to_actualize){
		this->modify_texture();
		this->has_to_actualize=false;
	}
	return this->surf->get_surface();
}

std::shared_ptr<Surface> Text::get_surface(int i){
	std::shared_ptr<Surface> s(new Surface('t',this->text));
	return s;
}


Text::~Text(){}