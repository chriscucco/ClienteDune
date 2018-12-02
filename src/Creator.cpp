#include "Creator.h"

void Creator::send_close(){
	unsigned char exit='s';
	this->skt->send_msj(&exit,1);
	skt->send_int(this->my_id);
	throw EndOfGame();
}


Creator::Creator(SDL_Renderer* renderer, Texture* texture,Socket* s, int w, int h,std::shared_ptr<MasterSurface> m,int f, int id){
	this->my_id=id;
	this->fps=f;
	this->r=renderer;
	this->t=texture;
	this->skt=s;
	this->Width=w;
	this->Height=h;
	this->master=m;
	this->current_max=NULL;
	this->current_id=NULL;
	std::shared_ptr<Text> s1(new Text(r,"Seleccion de Mapa:",400,50,0,0,0));
	std::shared_ptr<Text> s2(new Text(r,"Cantidad Maxima de Jugadores",400,50,900,0,0));
	std::shared_ptr<Text> s4(new Text(r,"Dos",150,50,1000,150,0));
	std::shared_ptr<Text> s5(new Text(r,"Tres",150,50,1000,200,0));
	std::shared_ptr<Text> s6(new Text(r,"Cuatro",150,50,1000,250,0));
	std::shared_ptr<Text> s7(new Text(r,"Cinco",150,50,1000,300,0));
	std::shared_ptr<Text> s8(new Text(r,"Seis",150,50,1000,350,0));
	std::shared_ptr<Text> s9(new Text(r,"CREAR",300,100,800,500,0));
	s4->modify_id(2);
	s5->modify_id(3);
	s6->modify_id(4);
	s7->modify_id(5);
	s8->modify_id(6);
	this->static_text.push_back(s1);
	this->static_text.push_back(s2);
	this->create=s9;
	this->max_players.push_back(s4);
	this->max_players.push_back(s5);
	this->max_players.push_back(s6);
	this->max_players.push_back(s7);
	this->max_players.push_back(s8);
	int x=100;
	int y=100;
	int size_x=400;
	int size_y=50;
	unsigned char mode='p';
	this->skt->send_msj(&mode,1);
	unsigned char c;
	while(skt->recv_msj(&c,1)){
		if(c=='f'){
			break;
		} else if (c=='m'){
			unsigned int size=skt->recv_int();
			std::string text;
			skt->recv_string(size,text);
			int id=skt->recv_int();
			std::string show="Mapa: ";
			show+=text;
			std::shared_ptr<Text> tex(new Text(r,show,size_x,size_y,x,y,0));
			tex->modify_id(id);
			this->maps.push_back(tex);
			y=y+50;
		}
	}
}


void Creator::refresh_screen(){
	SDL_RenderClear(r);
	SDL_RenderCopy(r, t->get_texture(), NULL, NULL);
	for (unsigned int i=0; i < this->static_text.size(); ++i){
		Texture t(this->r,this->static_text.at(i)->get_surface(0)->get_surface(),-1);
		SDL_RenderCopy(this->r, t.get_texture(), NULL, this->static_text.at(i)->getpos());
	}
	for (unsigned int i=0; i < this->max_players.size(); ++i){
		Texture t(this->r,this->max_players.at(i)->get_surface(0)->get_surface(),-1);
		SDL_RenderCopy(this->r, t.get_texture(), NULL, this->max_players.at(i)->getpos());
	}
	for (unsigned int i=0; i < this->maps.size(); ++i){
		Texture t(this->r,this->maps.at(i)->get_surface(0)->get_surface(),-1);
		SDL_RenderCopy(this->r, t.get_texture(), NULL, this->maps.at(i)->getpos());
	}
	Texture t(this->r,this->create->get_surface(0)->get_surface(),-1);
	SDL_RenderCopy(this->r, t.get_texture(), NULL, this->create->getpos());
	if(this->current_id!=NULL){
		SDL_Rect pos;
		pos.w=this->current_id->get_h();
		pos.h=this->current_id->get_h();
		pos.x=(this->current_id->get_x()-this->current_id->get_h());
		pos.y=this->current_id->get_y();
		Texture t(this->r,this->master->get_hpointer_surface()->get_surface());
		SDL_RenderCopy(this->r, t.get_texture(), NULL, &pos);
	}
	if(this->current_max!=NULL){
		SDL_Rect pos;
		pos.w=this->current_max->get_h();
		pos.h=this->current_max->get_h();
		pos.x=(this->current_max->get_x()-this->current_max->get_h());
		pos.y=this->current_max->get_y();
		Texture t(this->r,this->master->get_hpointer_surface()->get_surface());
		SDL_RenderCopy(this->r, t.get_texture(), NULL, &pos);
	}
	SDL_RenderPresent(r);
}


bool Creator::run(){
	bool running = true;
	SDL_Event event;
	Timer timer(this->fps);
	while (running){
		while(SDL_PollEvent(&event)){	   
	   		switch(event.type) {
				case SDL_QUIT:
					this->send_close();
					break;
				case SDL_WINDOWEVENT:
					timer.reset();
					break;
				case SDL_MOUSEBUTTONUP:
					int x;
					int y;
					SDL_GetMouseState(&x, &y);
					running=this->clicked(x,y);
			}
		}
		this->refresh_screen();
		std::this_thread::sleep_for(std::chrono::milliseconds(timer.remain_time()));
	}
	unsigned char eme='m';
	this->skt->send_msj(&eme,1);
 	this->skt->send_int(this->current_id->get_value());
 	this->skt->send_int(this->current_max->get_value());
 	unsigned char rec;
 	while(1){
 		int recv=this->skt->recv_msj(&rec,1);
 		if(recv==0){
 			throw EndOfGame();
 		} else if(rec=='o'){
 			break;
 		}
 	}
 	this->wait_screen();
 	unsigned char i='i';
 	this->skt->send_msj(&i,1);
 	return true;
}


std::shared_ptr<Text> Creator::search_maps(int x,int y){
	std::shared_ptr<Text> t=NULL;
	for (unsigned int i=0; i<this->maps.size(); ++i){
		if(this->maps.at(i)->click_is_inside_text(x,y)){
			t=this->maps.at(i);
			break;
		}
	}
	return t;
}


std::shared_ptr<Text> Creator::search_maxplayers(int x,int y){
	std::shared_ptr<Text> t=NULL;
	for (unsigned int i=0; i<this->max_players.size(); ++i){
		if(this->max_players.at(i)->click_is_inside_text(x,y)){
			t=this->max_players.at(i);
			break;
		}
	}
	return t;
}


bool Creator::clicked(int x,int y){
	if(this->create->click_is_inside_text(x,y)){
		if((this->current_id!=NULL)&&(this->current_max!=NULL)){
			return false;
		} else {
			return true;
		}
	} else {
		std::shared_ptr<Text> t=this->search_maps(x,y);
		if(t!=NULL){
			this->current_id=t;
		} else {
			std::shared_ptr<Text> t2=this->search_maxplayers(x,y);
			if(t2!=NULL){
				this->current_max=t2;
			}
		}
		return true;
	}
}


void Creator::wait_screen(){
	Text legend(this->r,"Esperando nuevos jugadores, hace clic para iniciar",1100,80,100,200,0);
	Button b(0,500,150,400,400,this->master->get_initmatch_surface());
	bool running = true;
	SDL_Event event;
	Timer timer(this->fps);
	while (running){
		while(SDL_PollEvent(&event)){	   
	   		switch(event.type) {
				case SDL_QUIT:
					this->send_close();
					break;
				case SDL_WINDOWEVENT:
					timer.reset();
					break;
				case SDL_MOUSEBUTTONUP:
					int x;
					int y;
					SDL_GetMouseState(&x, &y);
					if(b.click_is_inside_button(x,y)){
						running=false;
					}
					break;
			}
		}
		SDL_RenderClear(this->r);
		SDL_RenderCopy(this->r, this->t->get_texture(), NULL, NULL);
		Texture text(this->r, b.getsurf());
		SDL_RenderCopy(this->r, text.get_texture(), NULL, b.getpos());
		Texture t2(this->r,legend.get_surface(0)->get_surface(),-1);
		SDL_RenderCopy(this->r, t2.get_texture(), NULL, legend.getpos());
		SDL_RenderPresent(this->r);
		std::this_thread::sleep_for(std::chrono::milliseconds(timer.remain_time()));
	}	
}


Creator::~Creator(){}

