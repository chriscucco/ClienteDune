#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "SDLerror.cpp"


class Window{
private:
    SDL_Window* window;
public:
	Window(std::string name, int w, int h);
	SDL_Window* get_window();
	~Window();
	
};

