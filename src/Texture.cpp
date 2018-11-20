#ifndef TEXTURE_CPP_
#define TEXTURE_CPP_

#include "Texture.h"

Texture::Texture(SDL_Renderer* renderer, SDL_Surface* surface){
	this->texture=nullptr;
	this->texture=SDL_CreateTextureFromSurface(renderer, surface);
	if (this->texture==nullptr){
        std::cerr << "Error al cargar la textura"<< std::endl;
        throw SDLerror();
    } 
}

SDL_Texture* Texture::get_texture(){
	return this->texture;
}


Texture::~Texture(){
	SDL_DestroyTexture(this->texture);
}


#endif