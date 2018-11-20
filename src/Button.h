#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "Surface.cpp"
using namespace std;

class Button{
protected:
	SDL_Rect botton_pos;
	std::shared_ptr<Surface> botton_surface;
	int id;
public:
	Button();	
	SDL_Rect* getpos();
	int get_id();
	bool click_is_inside_button(int x, int y);
	SDL_Surface* getsurf();
	~Button();
};

 