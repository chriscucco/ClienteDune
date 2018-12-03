#include "Joiner.h"

void Joiner::send_close(){
	unsigned char exit='s';
	this->skt->send_msj(&exit,1);
	skt->send_int(this->my_id);
	throw EndOfGame();
}

Joiner::Joiner(SDL_Renderer* renderer, Texture* texture,Socket* s, int w, int h,std::shared_ptr<MasterSurface> m,int f, int id){
	this->my_id=id;
	this->fps=f;
	this->r=renderer;
	this->t=texture;
	this->skt=s;
	this->Width=w;
	this->Height=h;
	this->master=m;
	this->current_match=NULL;
	std::shared_ptr<Text> s1(new Text(r,"Seleccion de Partida:",400,100,200,50,0));
	this->static_text.push_back(s1);
	std::shared_ptr<Text> s2(new Text(r,"Unirse",400,100,800,400,0));
	this->join=s2;
	int x=200;
	int y=150;
	int size_x=400;
	int size_y=50;
	unsigned char mode='n';
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
			std::string show="Partida: ";
			show+=std::to_string(id);
			show+=". Mapa ";
			show+=text;
			std::shared_ptr<Text> tex(new Text(r,show,size_x,size_y,x,y,0));
			tex->modify_id(id);
			this->matchs.push_back(tex);
			y=y+50;
		}
	}
}





void Joiner::refresh_screen(){
	SDL_RenderClear(r);
	SDL_RenderCopy(r, this->t->get_texture(), NULL, NULL);
	for (unsigned int i=0; i < this->static_text.size(); ++i){
		Texture t(this->r,this->static_text.at(i)->get_surface(0)->get_surface(),-1);
		SDL_RenderCopy(this->r, t.get_texture(), NULL, this->static_text.at(i)->getpos());
	}
	for (unsigned int i=0; i < this->matchs.size(); ++i){
		Texture t(this->r,this->matchs.at(i)->get_surface(0)->get_surface(),-1);
		SDL_RenderCopy(this->r, t.get_texture(), NULL, this->matchs.at(i)->getpos());
	}
	
	Texture t(this->r,this->join->get_surface(0)->get_surface(),-1);
	SDL_RenderCopy(this->r, t.get_texture(), NULL, this->join->getpos());
	if(this->current_match!=NULL){
		SDL_Rect pos;
		pos.w=this->current_match->get_h();
		pos.h=this->current_match->get_h();
		pos.x=(this->current_match->get_x()-this->current_match->get_h());
		pos.y=this->current_match->get_y();
		Texture t(this->r,this->master->get_hpointer_surface()->get_surface());
		SDL_RenderCopy(this->r, t.get_texture(), NULL, &pos);
	}
	SDL_RenderPresent(r);
}


bool Joiner::run(){
	Music music("music/ambiente4.wav");
    Mix_PlayMusic(music.get_music(),-1);
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
		if( Mix_PlayingMusic()==0){
			Mix_PlayMusic(music.get_music(),-1);
		}
		this->refresh_screen();
		std::this_thread::sleep_for(std::chrono::milliseconds(timer.remain_time()));
	}
	unsigned char jey='j';
	this->skt->send_msj(&jey,1);
 	this->skt->send_int(this->current_match->get_value());
 	unsigned char rec;
 	while(1){
 		if( Mix_PlayingMusic()==0){
			Mix_PlayMusic(music.get_music(),-1);
		}
 		int recv=this->skt->recv_msj(&rec,1);
 		if(recv==0){
 			throw EndOfGame();
 		} else if(rec=='o'){
 			break;
 		}
 	}
 	this->wait_screen(&music);
 	return true;
}



std::shared_ptr<Text> Joiner::search_matchs(int x,int y){
	std::shared_ptr<Text> t=NULL;
	for (unsigned int i=0; i<this->matchs.size(); ++i){
		if(this->matchs.at(i)->click_is_inside_text(x,y)){
			t=this->matchs.at(i);
			break;
		}
	}
	return t;
}


bool Joiner::clicked(int x,int y){
	if(this->join->click_is_inside_text(x,y)){
		if(this->current_match!=NULL){
			return false;
		} else {
			return true;
		}
	} else {
		std::shared_ptr<Text> t=this->search_matchs(x,y);
		if(t!=NULL){
			this->current_match=t;
		}
		return true;
	}
}


void Joiner::wait_screen(Music* music){
	Text legend(this->r,"Esperando el inicio de la partida",1100,80,100,200,0);
	bool running = true;
	SDL_Event event;
	Timer timer(this->fps);
	unsigned char recv;
	while (running){
		while(SDL_PollEvent(&event)){	   
	   		switch(event.type) {
				case SDL_QUIT:
					this->send_close();
					break;
				case SDL_WINDOWEVENT:
					timer.reset();
					break;
			}
		}
		if( Mix_PlayingMusic()==0){
			Mix_PlayMusic(music->get_music(),-1);
		}
		SDL_RenderClear(this->r);
		SDL_RenderCopy(this->r, this->t->get_texture(), NULL, NULL);
		Texture t2(this->r,legend.get_surface(0)->get_surface(),-1);
		SDL_RenderCopy(this->r, t2.get_texture(), NULL, legend.getpos());
		SDL_RenderPresent(this->r);
		this->skt->recv_msj(&recv,1);
		if(recv=='r'){
			unsigned char ele='l';
			this->skt->send_msj(&ele,1);
			running=false;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(timer.remain_time()));
	}
}


Joiner::~Joiner(){}

