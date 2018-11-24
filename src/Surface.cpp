#ifndef SURFACE_CPP_
#define SURFACE_CPP_

#include "Surface.h"
#include <SDL2/SDL_ttf.h>




Surface::Surface(SDL_Window* window){
	this->surface=nullptr;
	this->surface=SDL_GetWindowSurface(window);
	if (this->surface==nullptr){
		std::cerr << "Error al cargar ventana " << std::endl;
		throw SDLerror();
	}
} 


Surface::Surface(std::string path){
	this->surface=IMG_Load(path.c_str());
    if (this->surface==nullptr){
        std::cerr << "Error al cargar la imagen " << std::endl;
        throw SDLerror();
    } 
}


Surface::Surface(SDL_Surface* background, SDL_Surface* screenSurface){
	this->surface=SDL_ConvertSurface(background, screenSurface->format,0);
	 if (this->surface==nullptr){
        std::cerr << "Error al cargar la imagen " << std::endl;
        throw SDLerror();
    } 
}


Surface::Surface(char t,std::string text){
	TTF_Font* font = TTF_OpenFont("AmaticBold.ttf", 50);
	if(font==0){
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		throw SDLerror();
	}
	SDL_Color color;  
	if(t=='f'){
		color={0, 0, 0};
	} else {
		color={255,0,0};
	}
	this->surface=TTF_RenderText_Solid(font, text.c_str(), color);
	if (this->surface==nullptr){
   		std::cerr << "Error al cargar la imagen " << std::endl;
   	throw SDLerror();
   	} 
}




void Surface::scale(SDL_Surface* screenSurface, SDL_Rect* rect){
	SDL_BlitScaled(this->surface,NULL,screenSurface,rect);
}


SDL_Surface* Surface::get_surface(){
	return this->surface;
}


Surface::~Surface(){
	SDL_FreeSurface(this->surface);
}


#endif