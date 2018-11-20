#include "Window.h"


Window::Window(std::string name, int w, int h){
	this->window=nullptr;
	this->window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h,SDL_WINDOW_SHOWN);
	if (window == NULL){
     	std::cout <<"Error al crear la ventana"<<std::endl;
        throw SDLerror();
    }
}


SDL_Window* Window::get_window(){
	return this->window;
}


Window::~Window(){
	SDL_DestroyWindow(this->window);
}

