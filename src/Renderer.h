#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "SDLerror.cpp"

class Renderer{
private:
	SDL_Renderer* renderer;
public:
	Renderer(SDL_Window* window);
	SDL_Renderer* get_renderer();
	void clear();
	void copy(SDL_Texture* text);
	void present();
	~Renderer();
};

