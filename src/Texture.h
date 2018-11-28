
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "SDLerror.cpp"


class Texture{
private:
	SDL_Texture* texture;
public:
	Texture(SDL_Renderer* renderer, SDL_Surface* surface,int id);
	Texture(SDL_Renderer* renderer, SDL_Surface* surface);
	void parser_color(int id);
	SDL_Texture* get_texture();
	~Texture();	
};

