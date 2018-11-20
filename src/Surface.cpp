#ifndef SURFACE_CPP_
#define SURFACE_CPP_

#include "Surface.h"


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