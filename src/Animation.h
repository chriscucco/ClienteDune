#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "Surface.cpp"
#include <vector>


class Animation{
protected:
	SDL_Rect botton_pos;
	SDL_Rect converted_pos;
	std::vector<std::shared_ptr<Surface>> botton_surface;
	unsigned int current_path;
	unsigned int iterative;
	unsigned int let_pass;
public:
	Animation();
	SDL_Surface* getsurf();
	SDL_Rect* get_converted_pos(int x,int y);
	bool is_inside_screen(int x, int y, int size_x, int size_y);
	SDL_Rect* getpos();
	bool finished();
	~Animation();
};
