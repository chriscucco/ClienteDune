#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "SDLerror.cpp"


class Surface{
private:
	SDL_Surface* surface;
	TTF_Font* font{nullptr};
public:
	Surface(SDL_Window* window);
	Surface(std::string path);
	Surface(char t,std::string text);
	Surface(SDL_Surface* background, SDL_Surface* screenSurface);
	void scale(SDL_Surface* screenSurface, SDL_Rect* rect);
	SDL_Surface* get_surface();
	~Surface();
};

