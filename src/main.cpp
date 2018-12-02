#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <unistd.h>
#include "Surface.cpp"
#include "Window.cpp"
#include "Renderer.cpp"
#include "Texture.cpp"
#include "Cycle.cpp"
#include "Creator.cpp"
#include "Timer.cpp"
#include "Joiner.cpp"
#include "Editor.cpp"
#define ATREIDES_TEAM 101
#define HARKONNEN_TEAM 102
#define ORDOS_TEAM 103

#define FPS 20


void send_close(Socket* s, int id){
	unsigned char exit='s';
	s->send_msj(&exit,1);
	s->send_int(id);
	throw EndOfGame();
}


bool create_map(SDL_Renderer* r, Texture* t,Socket* skt, int Width, int Height, std::shared_ptr<MasterSurface> master, int id){
	Editor editor(r,t->get_texture(),skt,Width,Height,master);
	bool running = true;
	SDL_Event event;
	Timer timer(FPS);
	while (running){
		while(SDL_PollEvent(&event)){	   
	   		switch(event.type) {
				case SDL_QUIT:
					send_close(skt,id);
					break;
				case SDL_WINDOWEVENT:
					timer.reset();
					editor.refreshscreen();
					break;
				case SDL_MOUSEBUTTONUP:
					int x;
					int y;
					SDL_GetMouseState(&x, &y);
					running=editor.clicked(x,y);
				}
		} 
		editor.refreshscreen();
		std::this_thread::sleep_for(std::chrono::milliseconds(timer.remain_time()));
	}
	editor.save();
	return false;
}


bool join_game(){
	return true;
}




int first_window(Renderer *r,Texture *texture,int Width, int Height, Socket* skt,int id){
	bool selection=true;
    int result;
    Surface s1("terrain/CrearJuego.png");
    Surface s2("terrain/CrearMapa.png");
    Surface s3("terrain/UnirseAJuego.png");

    SDL_Rect botton_pos_s1;
    SDL_Rect botton_pos_s2;
    SDL_Rect botton_pos_s3;

    botton_pos_s1.w=Width/2;
    botton_pos_s1.h=Height/6;
    botton_pos_s1.x=Width/4;
    botton_pos_s1.y=Height/6;

 	botton_pos_s2.w=Width/2;
    botton_pos_s2.h=Height/6;
    botton_pos_s2.x=Width/4;
    botton_pos_s2.y=(Height/12)*5;

    botton_pos_s3.w=Width/2;
    botton_pos_s3.h=Height/6;
    botton_pos_s3.x=Width/4;
    botton_pos_s3.y=(Height/12)*8;


	SDL_Event ev;
	Timer time(FPS);
	while (selection){
		while(SDL_PollEvent(&ev)){	   
	   		switch(ev.type) {
				case SDL_QUIT:
					send_close(skt,id);
					break;
				case SDL_WINDOWEVENT:
    				r->present();
					break;
				case SDL_MOUSEBUTTONUP:
					int x;
					int y;
					SDL_GetMouseState(&x, &y);
					if((x>=Width/4)&&(x<=(Width/4)*3)){
						if((y>=Height/6)&&(y<(Height/3))){
							result=1;
							selection=false;
						} else if ((y>=(Height/12)*5)&&(y<(Height/12)*7)){
							result=2;
							selection=false;
						} else if ((y>=(Height/12)*8)&&(y<=(Height/12)*10)){
							result=3;
							selection=false;
						}
					}
			}
		}
		r->clear(); 
    	r->copy(texture->get_texture());
    	Texture t1(r->get_renderer(), s1.get_surface());
		SDL_RenderCopy(r->get_renderer(), t1.get_texture(), NULL, &botton_pos_s1);
		Texture t2(r->get_renderer(), s2.get_surface());
		SDL_RenderCopy(r->get_renderer(), t2.get_texture(), NULL, &botton_pos_s2);
		Texture t3(r->get_renderer(), s3.get_surface());
		SDL_RenderCopy(r->get_renderer(), t3.get_texture(), NULL, &botton_pos_s3);
		r->present(); 
		std::this_thread::sleep_for(std::chrono::milliseconds(time.remain_time()));
	}
	return result;
}


void select_team(Renderer *r,Texture *texture_team,Socket* skt, int Width, int Height, int id){
	bool selection=true;
    int team_number;
	SDL_Event ev;
	Timer time(FPS);
	while (selection){
		while(SDL_PollEvent(&ev)){	   
	   		switch(ev.type) {
				case SDL_QUIT:
					send_close(skt,id);
					break;
				case SDL_WINDOWEVENT:
    				r->present();
					break;
				case SDL_MOUSEBUTTONUP:
					int x;
					int y;
					SDL_GetMouseState(&x, &y);
					if((x>(Width/10))&&(x<((Width/10)*3))&&(y>(Height/3))&&(y<((Height/5)*4))){
						selection=false;
						team_number=ATREIDES_TEAM;
					} else if((x>((Width/10)*4))&&(x<((Width/10)*6))&&(y>(Height/3))&&(y<((Height/5)*4))){
						selection=false;
						team_number=HARKONNEN_TEAM;
					} else if((x>((Width/10)*7))&&(x<((Width/10)*9))&&(y>(Height/3))&&(y<((Height/5)*4))){
						selection=false;
						team_number=ORDOS_TEAM;
					}
					break;
			}
		}
		r->clear(); 
    	r->copy(texture_team->get_texture());
		r->present(); 
		std::this_thread::sleep_for(std::chrono::milliseconds(time.remain_time()));
	}
	skt->send_int(team_number);
	team_number++;
}


void init_game(Socket* skt,Game* s){
	unsigned int recv_type,recv_id,size_x,size_y,x,y,team;
	unsigned char c;
	while(1){
		skt->recv_msj(&c,1);
		if(c=='x'){
			break;
		} else if(c=='c'){
			recv_type=skt->recv_int();
			recv_id=skt->recv_int();
			size_x=skt->recv_int();
			size_y=skt->recv_int();
			x=skt->recv_int();
			y=skt->recv_int();
			team=skt->recv_int();
			s->add(recv_type,recv_id,size_x,size_y,x,y,team);
		} else if(c=='t'){
        	int recv_type=skt->recv_int();
        	int recv_id=skt->recv_int();
        	int size_x=skt->recv_int();
        	int size_y=skt->recv_int();
        	int x=skt->recv_int();
        	int y=skt->recv_int();
        	s->add_terrain(recv_type,recv_id,size_x,size_y,x,y);
    	} else if(c=='w'){
        	int new_energy=skt->recv_int();
        	s->modify_energy(new_energy);
    	}else if(c=='p'){
        	int new_money=skt->recv_int();
        	s->modify_money(new_money);
      	}
	}
}


int main(int argc, char **argv){
try{
	if ( SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cerr << "ERROR AL INICIAR EL SDL" << std::endl;
		throw SDLerror();
	}
	if (! (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		std::cerr << "ERROR AL INICIALIZAR EL MODULO DE IMAGENES PNG" << std::endl;
		throw SDLerror();
	} 
	if(!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" )){
		std::cerr << "ERROR AL INICIALIZAR EL MODULO DE IMAGENES PNG" << std::endl;
		throw SDLerror();
	}	
	if(TTF_Init()==-1){
		throw SDLerror();
	}
	std::shared_ptr<MasterSurface> master(new MasterSurface());
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	auto Width = DM.w;
	auto Height = DM.h;
    Window w("Dune",Width,Height);
    Renderer r(w.get_window());     
	Surface screenSurface(w.get_window());
    Surface init_background("terrain/Portada.png");
    Surface optimized_background(init_background.get_surface(),screenSurface.get_surface());
    Surface teamselection("terrain/teamselection.png");
    Surface team_optimized(teamselection.get_surface(),screenSurface.get_surface());
    Surface background("terrain/Sand.jpg");
    Surface optimized_background2(background.get_surface(), screenSurface.get_surface());	
    Surface win_background("terrain/FinalGanaste.png");
    Surface optimized_background3(win_background.get_surface(),screenSurface.get_surface());
    Surface loose_background("terrain/FinalPerdiste.png");
    Surface optimized_background4(loose_background.get_surface(),screenSurface.get_surface());
	SDL_Rect stretchRect; 
	stretchRect.x = 0; 
	stretchRect.y = 0; 
	stretchRect.w = Width; 
	stretchRect.h = Height; 
	optimized_background.scale(screenSurface.get_surface(), &stretchRect);
    optimized_background2.scale(screenSurface.get_surface(), &stretchRect);
    optimized_background3.scale(screenSurface.get_surface(), &stretchRect);
    optimized_background4.scale(screenSurface.get_surface(), &stretchRect);
    team_optimized.scale(screenSurface.get_surface(), &stretchRect);
    Texture texture(r.get_renderer(), optimized_background.get_surface());
    Texture texture2(r.get_renderer(), optimized_background2.get_surface());
    Texture texture3(r.get_renderer(), optimized_background3.get_surface());
    Texture texture4(r.get_renderer(), optimized_background4.get_surface());
    Texture texture_team(r.get_renderer(), team_optimized.get_surface()); 
    Socket skt(argv[1],argv[2]);
    int id=skt.recv_int();
    bool finalize=false;
//PANTALLA INICIAL
    while(!finalize){
    	int mode=first_window(&r,&texture,Width,Height,&skt,id);
    	if(mode==1){
    		Creator c(r.get_renderer(),&texture2,&skt,Width,Height,master,FPS,id);
    		finalize=c.run();
    	} else if (mode==2){
    		finalize=create_map(r.get_renderer(),&texture2,&skt,Width,Height,master,id);
    	} else if (mode==3){
    		Joiner j(r.get_renderer(),&texture2,&skt,Width,Height,master,FPS,id);
    		finalize=j.run();
    	}	
    }
    r.clear(); 
    r.copy(texture_team.get_texture());
    r.present();
    select_team(&r,&texture_team,&skt,Width,Height,id);
    r.clear(); 
    r.copy(texture.get_texture());
    r.present();
	int init_x=skt.recv_int();
	int init_y=skt.recv_int();
	int map_size_x=skt.recv_int();
	int map_size_y=skt.recv_int();
 	Game s(r.get_renderer(), texture.get_texture(), texture3.get_texture(), texture4.get_texture(),&skt,id,init_x,init_y,Width,Height,map_size_x,map_size_y,master);
	init_game(&skt,&s);
	s.modify_texture(texture2.get_texture());
	std::mutex m;
	Cycle t(&s,&m);
	s.refreshscreen();
	t.start();
	s.refreshscreen();	
	bool running = true;
	int x_before, y_before;
	bool is_right_click=false;
	SDL_Event event;
	Timer timer(FPS);
	unsigned char exit='s';
	while (running){
		while(SDL_PollEvent(&event)){	   
	   		switch(event.type) {
				case SDL_QUIT:
					running=false;
					break;
				case SDL_MOUSEBUTTONDOWN:
					SDL_GetMouseState(&x_before, &y_before);
					if(event.button.button==SDL_BUTTON_LEFT){
						is_right_click=false;
					}  else if (event.button.button==SDL_BUTTON_RIGHT){
						is_right_click=true;
					}
					break;
				case SDL_WINDOWEVENT:
					timer.reset();
					s.refreshscreen();
					break;
				case SDL_MOUSEBUTTONUP:
					int x;
					int y;
					SDL_GetMouseState(&x, &y);
					if((x<=x_before+3)&&(x>=x_before-3)&&(y<=y_before+3)&&(y>=y_before-3)){
						s.clicked(x_before,y_before,is_right_click);
					} else if (is_right_click){
						is_right_click=false;
						break;
					} else{
						SDL_Rect pos;
						if(x_before>x){
							pos.w=(x_before-x);
						} else {
							pos.w=(x-x_before);
						}
						if (y_before>y){
							pos.h=(y_before-y);
						} else {
							pos.h=(y-y_before);
						}
						pos.y=(((y+y_before)/2)+s.get_current_corner_y());
						pos.x=(((x_before+x)/2)+s.get_current_corner_x());
						s.clicked_zone(pos);
					}
				case SDL_KEYDOWN:
                	switch(event.key.keysym.sym){
                		case SDLK_UP:
                	    	s.go_up();
                    		break;
                    	case SDLK_DOWN:
                	    	s.go_down();
                    		break;
                		case SDLK_LEFT:
                    		s.go_left();
                    		break;
                		case SDLK_RIGHT:
                			s.go_right();
                    		break;
                	}
				}
			} 
			Lock l(m);
			s.refreshscreen();
			std::this_thread::sleep_for(std::chrono::milliseconds(timer.remain_time()));
		}
		skt.send_msj(&exit,1);
		skt.send_int(id);
		skt.close_recv_channel();
		t.join();
	} catch (SocketParameterError& perror){
		std::cout<<perror.what()<<std::endl;
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
		return 1;
	} catch (SDLerror& error){
        std::cout<<error.what()<<std::endl;
        TTF_Quit();
		IMG_Quit();
        SDL_Quit();
        return 2;
    } catch (EndOfGame& error){
        std::cout<<error.what()<<std::endl;
        TTF_Quit();
		IMG_Quit();
        SDL_Quit();
        return 2;
    }
    TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	return 0;
}

