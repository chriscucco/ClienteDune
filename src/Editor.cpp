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
#define CHARGE_BUTTON 38
#define BUTTON_SIZE 50
#define CHARGE_BUTTON_SIZE_X 150
#define CENTER_SIZE 50
#define TERRAIN_SIZE 70

#define MAX_X_MAP 9000
#define MAX_Y_MAP 7000
#define MIN_X_MAP 2000
#define MIN_Y_MAP 1000
#define BUTTON_CREATE 5
#define XUP_1 1
#define XUP_10 10
#define XUP_100 100
#define XUP_1000 1000
#define XDOWN_1 2
#define XDOWN_10 20
#define XDOWN_100 200
#define XDOWN_1000 2000
#define YUP_1 3
#define YUP_10 30
#define YUP_100 300
#define YUP_1000 3000
#define YDOWN_1 4
#define YDOWN_10 40
#define YDOWN_100 400
#define YDOWN_1000 4000

bool Editor::clicked_map_size(std::vector<std::shared_ptr<Button>> touchable_buttons, std::shared_ptr<Text> x_value, std::shared_ptr<Text> y_value,int x, int y){
	int id=0;
	for (unsigned int i=0; i<touchable_buttons.size(); ++i){
		if(touchable_buttons.at(i)->click_is_inside_button(x,y)){
			id=touchable_buttons.at(i)->get_id();
		}
	}
	bool cont=true;
	int actual_x=x_value->get_value();
	int actual_y=y_value->get_value();
	switch(id){
		case 0:
			break;
		case XUP_1:
			if(actual_x<=MAX_X_MAP-1){
				x_value->modify_value(actual_x+1);
			}
			break;
		case XUP_10:
			if(actual_x<=MAX_X_MAP-10){
				x_value->modify_value(actual_x+10);
			}
			break;
		case XUP_100:
			if(actual_x<=MAX_X_MAP-100){
				x_value->modify_value(actual_x+100);
			}
			break;
		case XUP_1000:
			if(actual_x<=MAX_X_MAP-1000){
				x_value->modify_value(actual_x+1000);
			}
			break;
		case XDOWN_1:
			if(actual_x>=1+MIN_X_MAP){
				x_value->modify_value(actual_x-1);
			}
			break;
		case XDOWN_10:
			if(actual_x>=10+MIN_X_MAP){
				x_value->modify_value(actual_x-10);
			}
			break;
		case XDOWN_100:
			if(actual_x>=100+MIN_X_MAP){
				x_value->modify_value(actual_x-100);
			}
			break;
		case XDOWN_1000:
			if(actual_x>=1000+MIN_X_MAP){
				x_value->modify_value(actual_x-1000);
			}
			break;
		case YUP_1:
			if(actual_y<=MAX_Y_MAP-1){
				y_value->modify_value(actual_y+1);
			}
			break;
		case YUP_10:
			if(actual_y<=MAX_Y_MAP-10){
				y_value->modify_value(actual_y+10);
			}
			break;
		case YUP_100:
			if(actual_y<=MAX_Y_MAP-100){
				y_value->modify_value(actual_y+100);
			}
			break;
		case YUP_1000:
			if(actual_y<=MAX_Y_MAP-1000){
				y_value->modify_value(actual_y+1000);
			}
			break;
		case YDOWN_1:
			if(actual_y>=1+MIN_Y_MAP){
				y_value->modify_value(actual_y-1);
			}
			break;
		case YDOWN_10:
			if(actual_y>=10+MIN_Y_MAP){
				y_value->modify_value(actual_y-10);
			}
			break;
		case YDOWN_100:
			if(actual_y>=100+MIN_Y_MAP){
				y_value->modify_value(actual_y-100);
			}
			break;
		case YDOWN_1000:
			if(actual_y>=1000+MIN_Y_MAP){
				y_value->modify_value(actual_y-1000);
			}
			break;
		case BUTTON_CREATE:
			this->game_size_x=actual_x;
			this->game_size_y=actual_y;
			this->kx_reductor=((float)this->size_x/(float)actual_x);
			this->ky_reductor=((float)this->size_y/(float)actual_y);
			this->kx_amplify=((float)actual_x/(float)this->size_x);
			this->ky_amplify=((float)actual_y/(float)this->size_y);
			cont=false;
	}
	return cont;
}





void Editor::send_close(){
	unsigned char exit='s';
	this->s->send_msj(&exit,1);
	this->s->send_int(this->my_id);
	throw EndOfGame();
}


Editor::Editor(SDL_Renderer *r,SDL_Texture *t,Socket* skt, int x, int y,std::shared_ptr<MasterSurface> master, int id) : master(master){
	this->background=t;
	this->renderer=r;
	this->s=skt;
	this->size_x=x;
	this->size_y=y;
	this->my_id=id;
	this->init_buttons();
	this->select_map_size();
}


void Editor::process_map_size(std::vector<std::shared_ptr<Button>> static_buttons,std::vector<std::shared_ptr<Button>> touchable_buttons,std::vector<std::shared_ptr<Text>> static_text){
	std::shared_ptr<Text> x_value(new Text(this->renderer," ",150,150,300,(this->size_y/3)*2,0));
	std::shared_ptr<Text> y_value(new Text(this->renderer," ",150,150,300+(this->size_x/2),(this->size_y/3)*2,0));
	x_value->modify_value(MIN_X_MAP);
	y_value->modify_value(MIN_Y_MAP);
	bool running = true;
	SDL_Event event;
	Timer timer(20);
	while (running){
		while(SDL_PollEvent(&event)){	   
	   		switch(event.type) {
				case SDL_QUIT:
					this->send_close();
					break;
				case SDL_MOUSEBUTTONUP:
					int x;
					int y;
					SDL_GetMouseState(&x, &y);
					running=this->clicked_map_size(touchable_buttons,x_value,y_value,x,y);
				case SDL_WINDOWEVENT:
					timer.reset();
					break;
			}
		}
		SDL_RenderClear(this->renderer);
		SDL_RenderCopy(this->renderer, this->background, NULL, NULL);
		for (unsigned int i=0; i<static_text.size(); ++i){
			Texture t2(this->renderer,static_text.at(i)->get_surface(0)->get_surface(),-1);
			SDL_RenderCopy(this->renderer, t2.get_texture(), NULL, static_text.at(i)->getpos());
		}
		for (unsigned int i=0; i<touchable_buttons.size(); ++i){
			Texture t2(this->renderer,touchable_buttons.at(i)->getsurf());
			SDL_RenderCopy(this->renderer, t2.get_texture(), NULL, touchable_buttons.at(i)->getpos());
		}
		for (unsigned int i=0; i<static_buttons.size(); ++i){
			Texture t2(this->renderer,static_buttons.at(i)->getsurf());
			SDL_RenderCopy(this->renderer, t2.get_texture(), NULL, static_buttons.at(i)->getpos());
		}
		Texture x_size(this->renderer,x_value->get_value_surface()->get_surface(),-1);
		SDL_RenderCopy(this->renderer, x_size.get_texture(), NULL, x_value->getpos());
		Texture y_size(this->renderer,y_value->get_value_surface()->get_surface(),-1);
		SDL_RenderCopy(this->renderer, y_size.get_texture(), NULL, y_value->getpos());
		SDL_RenderPresent(this->renderer);
		std::this_thread::sleep_for(std::chrono::milliseconds(timer.remain_time()));
	}
}





void Editor::select_map_size(){
	std::shared_ptr<Surface> up(new Surface("imgs/CreadorMapa/Arriba.png"));
	std::shared_ptr<Surface> down(new Surface("imgs/CreadorMapa/Abajo.png"));
	std::shared_ptr<Surface> x1(new Surface("imgs/CreadorMapa/x1.png"));
	std::shared_ptr<Surface> x10(new Surface("imgs/CreadorMapa/x10.png"));
	std::shared_ptr<Surface> x100(new Surface("imgs/CreadorMapa/x100.png"));
	std::shared_ptr<Surface> x1000(new Surface("imgs/CreadorMapa/x1000.png"));
	std::shared_ptr<Surface> create(new Surface("imgs/Botones/Crear.png"));
	std::shared_ptr<Button> x_x1(new Button(0,100,100,200,this->size_y/3,x1));
	std::shared_ptr<Button> x_x10(new Button(0,100,100,300,this->size_y/3,x10));
	std::shared_ptr<Button> x_x100(new Button(0,100,100,400,this->size_y/3,x100));
	std::shared_ptr<Button> x_x1000(new Button(0,100,100,500,this->size_y/3,x1000));
	std::shared_ptr<Button> y_x1(new Button(0,100,100,(this->size_x/2)+200,this->size_y/3,x1));
	std::shared_ptr<Button> y_x10(new Button(0,100,100,(this->size_x/2)+300,this->size_y/3,x10));
	std::shared_ptr<Button> y_x100(new Button(0,100,100,(this->size_x/2)+400,this->size_y/3,x100));
	std::shared_ptr<Button> y_x1000(new Button(0,100,100,(this->size_x/2)+500,this->size_y/3,x1000));
	std::shared_ptr<Button> button_create(new Button(BUTTON_CREATE,200,100,(this->size_x-250),0,create));
	std::vector<std::shared_ptr<Button>> static_buttons;
	static_buttons.push_back(x_x1);
	static_buttons.push_back(x_x10);
	static_buttons.push_back(x_x100);
	static_buttons.push_back(x_x1000);
	static_buttons.push_back(y_x1);
	static_buttons.push_back(y_x10);
	static_buttons.push_back(y_x100);
	static_buttons.push_back(y_x1000);
	std::shared_ptr<Button> xup_x1(new Button(XUP_1,100,100,200,this->size_y/3-100,up));
	std::shared_ptr<Button> xup_x10(new Button(XUP_10,100,100,300,this->size_y/3-100,up));
	std::shared_ptr<Button> xup_x100(new Button(XUP_100,100,100,400,this->size_y/3-100,up));
	std::shared_ptr<Button> xup_x1000(new Button(XUP_1000,100,100,500,this->size_y/3-100,up));
	std::shared_ptr<Button> yup_x1(new Button(YUP_1,100,100,(this->size_x/2)+200,this->size_y/3-100,up));
	std::shared_ptr<Button> yup_x10(new Button(YUP_10,100,100,(this->size_x/2)+300,this->size_y/3-100,up));
	std::shared_ptr<Button> yup_x100(new Button(YUP_100,100,100,(this->size_x/2)+400,this->size_y/3-100,up));
	std::shared_ptr<Button> yup_x1000(new Button(YUP_1000,100,100,(this->size_x/2)+500,this->size_y/3-100,up));
	std::shared_ptr<Button> xdown_x1(new Button(XDOWN_1,100,100,200,this->size_y/3+100,down));
	std::shared_ptr<Button> xdown_x10(new Button(XDOWN_10,100,100,300,this->size_y/3+100,down));
	std::shared_ptr<Button> xdown_x100(new Button(XDOWN_100,100,100,400,this->size_y/3+100,down));
	std::shared_ptr<Button> xdown_x1000(new Button(XDOWN_1000,100,100,500,this->size_y/3+100,down));
	std::shared_ptr<Button> ydown_x1(new Button(YDOWN_1,100,100,(this->size_x/2)+200,this->size_y/3+100,down));
	std::shared_ptr<Button> ydown_x10(new Button(YDOWN_10,100,100,(this->size_x/2)+300,this->size_y/3+100,down));
	std::shared_ptr<Button> ydown_x100(new Button(YDOWN_100,100,100,(this->size_x/2)+400,this->size_y/3+100,down));
	std::shared_ptr<Button> ydown_x1000(new Button(YDOWN_1000,100,100,(this->size_x/2)+500,this->size_y/3+100,down));
	std::vector<std::shared_ptr<Button>> touchable_buttons;
	touchable_buttons.push_back(xup_x1);
	touchable_buttons.push_back(xup_x10);
	touchable_buttons.push_back(xup_x100);
	touchable_buttons.push_back(xup_x1000);
	touchable_buttons.push_back(yup_x1);
	touchable_buttons.push_back(yup_x10);
	touchable_buttons.push_back(yup_x100);
	touchable_buttons.push_back(yup_x1000);
	touchable_buttons.push_back(xdown_x1);
	touchable_buttons.push_back(xdown_x10);
	touchable_buttons.push_back(xdown_x100);
	touchable_buttons.push_back(xdown_x1000);
	touchable_buttons.push_back(ydown_x1);
	touchable_buttons.push_back(ydown_x10);
	touchable_buttons.push_back(ydown_x100);
	touchable_buttons.push_back(ydown_x1000);
	touchable_buttons.push_back(button_create);
	std::shared_ptr<Text> title(new Text(this->renderer,"Seleccionar medidas del mapa",800,50,(this->size_x/3)-400,0,0));
	std::shared_ptr<Text> title_map_x(new Text(this->renderer,"X:",50,50,50,(this->size_y/3)+25,0));
	std::shared_ptr<Text> title_map_y(new Text(this->renderer,"Y:",50,50,(this->size_x/2)+50,(this->size_y/3)+25,0));
	std::vector<std::shared_ptr<Text>> static_text;
	static_text.push_back(title);
	static_text.push_back(title_map_x);
	static_text.push_back(title_map_y);
	this->process_map_size(static_buttons,touchable_buttons,static_text);
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
	std::shared_ptr<Button> b10(new Button(CHARGE_BUTTON,CHARGE_BUTTON_SIZE_X,BUTTON_SIZE,(this->size_x-CHARGE_BUTTON_SIZE_X),0,this->master->get_button_charge_surface()));
	this->buttons.push_back(b1);
	this->buttons.push_back(b2);
	this->buttons.push_back(b3);
	this->buttons.push_back(b4);
	this->buttons.push_back(b5);
	this->buttons.push_back(b6);
	this->buttons.push_back(b7);
	this->buttons.push_back(b8);
	this->buttons.push_back(b9);
	this->charge_button=b10;

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
	Texture t2(this->renderer, this->charge_button->getsurf());
	SDL_RenderCopy(this->renderer, t2.get_texture(), NULL, this->charge_button->getpos());

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
	if(this->charge_button->click_is_inside_button(x,y)){
		this->charge_map();
		return cont;
	} else {
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
}


void Editor::charge_map(){
	//CARGAR MAPA EN MEMORIA, TE LO DEJO A VOS NACHO
}


void Editor::save(){
	//Aca esta la parte tuya nacho, quedan grabados en los vectores terrains y statics.
	//Fijate en las clases Static y Terrain, ahi estan los comandos para tener el ID, x, y, size_x, size_y
	//Lo dejo comentado
}


Editor::~Editor(){}
