#include "Renderer.h"


Renderer::Renderer(SDL_Window* window){
	this->renderer=nullptr;
	this->renderer=SDL_CreateRenderer(window, 0, 0); 
    if(renderer==NULL ){
        std::cerr << "Error al crear el Render"<< std::endl;
        throw SDLerror();
    }
}

SDL_Renderer* Renderer::get_renderer(){
	return this->renderer;
}


void Renderer::clear(){
	 SDL_RenderClear(this->renderer);
}


void Renderer::copy(SDL_Texture* text){
	SDL_RenderCopy(this->renderer,text, NULL, NULL );
}


void Renderer::present(){
	SDL_RenderPresent(this->renderer);
}


Renderer::~Renderer(){
	SDL_DestroyRenderer(this->renderer);
}
