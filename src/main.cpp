#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "Surface.cpp"
#include "Window.cpp"
#include "Renderer.cpp"
#include "Texture.cpp"
#include "Cycle.cpp"
#include "Timer.cpp"

#define SCREEN_WIDTH 1365
#define SCREEN_HEIGHT 708
#define FPS 30

int main(int argc, char **argv){
try{
	Socket skt(argv[1],argv[2]);
	int id=skt.recv_int();
	if ( SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cerr << "ERROR AL INICIAR EL SDL" << std::endl;
		throw SDLerror();
	} else {
		if (! (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
			std::cerr << "ERROR AL INICIALIZAR EL MODULO DE IMAGENES PNG" << std::endl;
			throw SDLerror();
		} else if(!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" )){
			std::cerr << "ERROR AL INICIALIZAR EL MODULO DE IMAGENES PNG" << std::endl;
			throw SDLerror();
		}
	}	
    Window w("Dune",SCREEN_WIDTH,SCREEN_HEIGHT);
	Surface screenSurface(w.get_window());
    Surface init_background("terrain/Portada.png");
    Surface optimized_background(init_background.get_surface(),screenSurface.get_surface());
    Surface background("terrain/Sand.jpg");
    Surface optimized_background2(background.get_surface(), screenSurface.get_surface());	
    Surface win_background("terrain/FinalGanaste.png");
    Surface optimized_background3(win_background.get_surface(),screenSurface.get_surface());
     Surface loose_background("terrain/FinalPerdiste.png");
    Surface optimized_background4(loose_background.get_surface(),screenSurface.get_surface());
	
	SDL_Rect stretchRect; 
	stretchRect.x = 0; 
	stretchRect.y = 0; 
	stretchRect.w = SCREEN_WIDTH; 
	stretchRect.h = SCREEN_HEIGHT; 

	optimized_background.scale(screenSurface.get_surface(), &stretchRect);
    optimized_background2.scale(screenSurface.get_surface(), &stretchRect);
    optimized_background3.scale(screenSurface.get_surface(), &stretchRect);
    optimized_background4.scale(screenSurface.get_surface(), &stretchRect);
    Renderer r(w.get_window());     
    Texture texture(r.get_renderer(), optimized_background.get_surface());
    Texture texture2(r.get_renderer(), optimized_background2.get_surface());
    Texture texture3(r.get_renderer(), optimized_background3.get_surface());
    Texture texture4(r.get_renderer(), optimized_background4.get_surface());
    r.clear(); 
    r.copy(texture.get_texture());
    r.present();
 

	Game s(r.get_renderer(), texture.get_texture(), texture3.get_texture(), texture4.get_texture(),&skt,id,50,50,SCREEN_WIDTH,SCREEN_HEIGHT);
	unsigned int recv_type,recv_id,size_x,size_y,x,y,team;
	unsigned char c;
	while(1){
		skt.recv_msj(&c,1);
		if(c=='x'){
			break;
		} else if(c=='c'){
			recv_type=skt.recv_int();
			recv_id=skt.recv_int();
			size_x=skt.recv_int();
			size_y=skt.recv_int();
			x=skt.recv_int();
			y=skt.recv_int();
			team=skt.recv_int();
			s.add(recv_type,recv_id,size_x,size_y,x,y,team);
		} else if(c=='t'){
        	int recv_type=skt.recv_int();
        	int recv_id=skt.recv_int();
        	int size_x=skt.recv_int();
        	int size_y=skt.recv_int();
        	int x=skt.recv_int();
        	int y=skt.recv_int();
        	s.add_terrain(recv_type,recv_id,size_x,size_y,x,y);
    	}
	}
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
						pos.y=(y+y_before)/2;
						pos.x=((x_before+x)/2);
						s.clicked_zone(pos);
					}
				}
			} 
			if(timer.has_to_actualize()){
				Lock l(m);
				s.refreshscreen();
			}
		}
		skt.send_msj(&exit,1);
		skt.close_recv_channel();
		t.join();
	} catch (SocketParameterError& perror){
		std::cout<<perror.what()<<std::endl;
		SDL_Quit();
		return 1;
	} catch (SDLerror& error){
        std::cout<<error.what()<<std::endl;
        SDL_Quit();
        return 2;
    }
	SDL_Quit();
	return 0;
}

