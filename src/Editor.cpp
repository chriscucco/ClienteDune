#include "Editor.h"
#define CENTRODECONSTRUCCION 0
#define ROCA 30
#define DUNA 31
#define ESPECIAFUERTE 32
#define ESPECIASUAVE 33
#define CIMA 34
#define PRECIPICIO 35
#define SAVE 36
#define CANCEL 37
#define BUTTON_SIZE 50
#define CENTER_SIZE 50
#define TERRAIN_SIZE 70

Editor::Editor(SDL_Renderer *r,SDL_Texture *t,Socket* skt, int x, int y,std::shared_ptr<MasterSurface> master) : master(master){
	this->background=t;
	this->renderer=r;
	this->s=skt;
	this->size_x=x;
	this->size_y=y;
	this->init_buttons();

}


void Editor::init_buttons(){
	std::shared_ptr<Button> b1(new Button_CentroDeConstruccion(CENTRODECONSTRUCCION,BUTTON_SIZE,BUTTON_SIZE,(this->size_x/2)-(BUTTON_SIZE*4),0,this->master->get_button_centrodeconstruccion_surface()));
	std::shared_ptr<Button> b2(new Button(ROCA,BUTTON_SIZE,BUTTON_SIZE,(this->size_x/2)-(BUTTON_SIZE*3),0,this->master->get_button_roca_surface()));
	std::shared_ptr<Button> b3(new Button(DUNA,BUTTON_SIZE,BUTTON_SIZE,(this->size_x/2)-(BUTTON_SIZE*2),0,this->master->get_button_duna_surface()));
	std::shared_ptr<Button> b4(new Button(ESPECIAFUERTE,BUTTON_SIZE,BUTTON_SIZE,(this->size_x/2)-(BUTTON_SIZE),0,this->master->get_button_especiafuerte_surface()));
	std::shared_ptr<Button> b5(new Button(ESPECIASUAVE,BUTTON_SIZE,BUTTON_SIZE,(this->size_x/2),0,this->master->get_button_especiasuave_surface()));
	std::shared_ptr<Button> b6(new Button(CIMA,BUTTON_SIZE,BUTTON_SIZE,(this->size_x/2)+(BUTTON_SIZE),0,this->master->get_button_cima_surface()));
	std::shared_ptr<Button> b7(new Button(PRECIPICIO,BUTTON_SIZE,BUTTON_SIZE,(this->size_x/2)+(BUTTON_SIZE*2),0,this->master->get_button_precipicio_surface()));
	std::shared_ptr<Button> b8(new Button(SAVE,BUTTON_SIZE,BUTTON_SIZE,(this->size_x/2)+(BUTTON_SIZE*3),0,this->master->get_button_save_surface()));
	std::shared_ptr<Button> b9(new Button(CANCEL,BUTTON_SIZE,BUTTON_SIZE,(this->size_x/2)+(BUTTON_SIZE*4),0,this->master->get_button_cancel_surface()));
	this->buttons.push_back(b1);
	this->buttons.push_back(b2);
	this->buttons.push_back(b3);
	this->buttons.push_back(b4);
	this->buttons.push_back(b5);
	this->buttons.push_back(b6);
	this->buttons.push_back(b7);
	this->buttons.push_back(b8);
	this->buttons.push_back(b9);
}


void Editor::refreshscreen(){
	SDL_RenderClear(this->renderer);
	SDL_RenderCopy(this->renderer, this->background, NULL, NULL);
	copyterrain();
	copystatics();
	copybuttons();
	SDL_RenderPresent(this->renderer);
}




void Editor::copystatics(){
	unsigned int i=0;
	while(i<this->statics.size()){
		Texture t(this->renderer, this->statics.at(i)->getsurf(),this->statics.at(i)->mine());
		SDL_RenderCopy(this->renderer, t.get_texture(), NULL, this->statics.at(i)->getpos());
		i++;
	}
}



void Editor::copyterrain(){
	unsigned int i=0;
	while(i<this->terrains.size()){
			Texture t(this->renderer, this->terrains.at(i)->getsurf());
			SDL_RenderCopy(this->renderer, t.get_texture(), NULL, this->terrains.at(i)->getpos());
			i++;
		}
}


void Editor::copybuttons(){
	unsigned int i=0;
	while(i<this->buttons.size()){
		Texture t(this->renderer, this->buttons.at(i)->getsurf());
		SDL_RenderCopy(this->renderer, t.get_texture(), NULL, this->buttons.at(i)->getpos());
		i++;
	}	
	if(this->current_button!=nullptr){
		Texture t(this->renderer, this->current_button->getsurf(),0);
		SDL_RenderCopy(this->renderer, t.get_texture(), NULL, this->current_button->getpos());
	}
}


std::shared_ptr<Button> Editor::search_button_by_clic(int x,int y){
	std::shared_ptr<Button> b=NULL;
	unsigned int i=0;
	while(i<this->buttons.size()){
		if(this->buttons.at(i)->click_is_inside_button(x,y)){
			b=this->buttons.at(i);
			break;
		}
		i++;
	}
	return b;
}

void Editor::process_clic(int x, int y){
	if(this->current_button==nullptr){
		return;
	}
	if(this->current_button->get_id()==CANCEL){
		this->remove_element(x,y);
	} else if(this->current_button->get_id()==CENTRODECONSTRUCCION){
		this->add_centre(x,y);
	} else {
		this->add_terrain(x,y);
	}
}

int Editor::get_pos_static(int x, int y){
	int i;
	for (i=(this->statics.size()-1); i>=0; --i){
		if(this->statics.at(i)->click_is_inside_static(x,y)){
			break;
		}
	}
	return i;
}


int Editor::get_pos_terrain(int x, int y){
	int i;
	for (i=(this->terrains.size()-1); i>=0; --i){
		if(this->terrains.at(i)->is_in_click(x,y)){
			break;
		}
	}
	return i;
}

bool Editor::is_able(int x, int y){
	unsigned int i=0;
	while(i<this->statics.size()){
		if(this->statics.at(i)->click_is_inside_static(x,y)){
			return false;
		}
		i++;
	}
	unsigned int j=0;
	while(j<this->terrains.size()){
		if((this->terrains.at(j)->is_in_click(x,y))&&(this->terrains.at(j)->get_id()==ROCA)){
			return true;
		}
		j++;
	}
	return false;
}



bool Editor::can_put_static(int x, int y, int w, int h){
	int x1=(x-(w/2));
	int x2=x;
	int x3=(x+(w/2));
	int y1=(y-(h/2));
	int y2=y;
	int y3=(y+(h/2));
	bool is_able1=this->is_able(x1,y1);
	bool is_able2=this->is_able(x1,y2);
	bool is_able3=this->is_able(x1,y3);
	bool is_able4=this->is_able(x2,y1);
	bool is_able5=this->is_able(x2,y2);
	bool is_able6=this->is_able(x2,y3);
	bool is_able7=this->is_able(x3,y1);
	bool is_able8=this->is_able(x3,y2);
	bool is_able9=this->is_able(x3,y3);

	return ((is_able1)&&(is_able2)&&(is_able3)&&(is_able4)&&(is_able5)&&(is_able6)&&(is_able7)&&(is_able8)&&(is_able9));
}



void Editor::add_centre(int x1, int y1){
	int x=x1-(CENTER_SIZE/2);
	int y=y1-(CENTER_SIZE/2);
	int w=CENTER_SIZE;
	int h=CENTER_SIZE;
	bool can_put=this->can_put_static(x,y,w,h);
	if(can_put){
		std::shared_ptr<Static> d(new CentroDeConstruccion(CENTRODECONSTRUCCION,w,h,x,y,0,this->master->get_centrodeconstruccion_surface()));
		this->statics.push_back(d);
	}
}


void Editor::remove_element(int x, int y){
	int pos=this->get_pos_static(x,y);
	if(pos>=0){
		this->statics.erase(statics.begin()+pos);
	} else {
		pos=this->get_pos_terrain(x,y);
		if(pos>=0){
			this->terrains.erase(terrains.begin()+pos);
		}
	}
}


void Editor::add_duna(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Terrain> m(new Duna(id,size_x,size_y,x,y,this->master->get_duna_surface()));
	this->terrains.push_back(m);
}


void Editor::add_cima(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Terrain> m(new Cima(id,size_x,size_y,x,y,this->master->get_cima_surface()));
	this->terrains.push_back(m);
}


void Editor::add_especiafuerte(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Terrain> m(new EspeciaFuerte(id,size_x,size_y,x,y,this->master->get_especiafuerte_surface()));
	this->terrains.push_back(m);
}


void Editor::add_especiasuave(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Terrain> m(new EspeciaSuave(id,size_x,size_y,x,y,this->master->get_especiasuave_surface()));
	this->terrains.push_back(m);
}


void Editor::add_precipicio(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Terrain> m(new Precipicio(id,size_x,size_y,x,y,this->master->get_precipicio_surface()));
	this->terrains.push_back(m);
}


void Editor::add_roca(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Terrain> m(new Roca(id,size_x,size_y,x,y,this->master->get_roca_surface()));
	this->terrains.push_back(m);
}







void Editor::insert_terrain(int x,int y,int w,int h){
	int id=this->current_button->get_id();
	switch(id){
		case ROCA:
			this->add_roca(id,w,h,x,y);
			break;
		case DUNA:
			this->add_duna(id,w,h,x,y);
			break;
		case ESPECIAFUERTE:
			this->add_especiafuerte(id,w,h,x,y);
			break;
		case ESPECIASUAVE:
			this->add_especiasuave(id,w,h,x,y);
			break;
		case CIMA:
			this->add_cima(id,w,h,x,y);
			break;
		case PRECIPICIO:
			this->add_precipicio(id,w,h,x,y);
			break;
	}
}




void Editor::add_terrain(int x1, int y1){
	int x=x1-(TERRAIN_SIZE/2);
	int y=y1-(TERRAIN_SIZE/2);
	int w=TERRAIN_SIZE;
	int h=TERRAIN_SIZE;
	this->insert_terrain(x,y,w,h);
}




bool Editor::clicked(int x,int y){
	bool cont=true;
	std::shared_ptr<Button> b=this->search_button_by_clic(x,y);
	if(b!=NULL){
		if(b->get_id()==SAVE){
			cont=false;
		} else{
			this->current_button=b;
		}
	} else {
		this->process_clic(x,y);
	}
	return cont;
}


void Editor::save(){
	//Aca esta la parte tuya nacho, quedan grabados en los vectores terrains y statics.
	//Fijate en las clases Static y Terrain, ahi estan los comandos para tener el ID, x, y, size_x, size_y
	//Lo dejo comentado
}


Editor::~Editor(){}

