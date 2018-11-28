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



Texture::Texture(SDL_Renderer* renderer, SDL_Surface* surface,int id){
	this->texture=nullptr;
	this->texture=SDL_CreateTextureFromSurface(renderer, surface);
	if (this->texture==nullptr){
        std::cerr << "Error al cargar la textura"<< std::endl;
        throw SDLerror();
    } 
    this->parser_color(id);
}

void Texture::parser_color(int id){
	int r=0;
	int g=0;
	int b=0;
	switch	(id){
		case 1:
			r=200;
			g=0;
			b=0;
			break;
		case 2:
			r=0;
			g=200;
			b=0;
			break;
		case 3:
			r=0;
			g=0;
			b=200;
			break;
		case 4:
			r=200;
			g=0;
			b=200;
			break;
		case 5:
			r=0;
			g=200;
			b=200;
			break;
		case 6:
			r=200;
			g=200;
			b=0;
			break;
	}
	SDL_SetTextureColorMod(this->texture,r,g,b);
}

SDL_Texture* Texture::get_texture(){
	return this->texture;
}


Texture::~Texture(){
	SDL_DestroyTexture(this->texture);
}


#endif