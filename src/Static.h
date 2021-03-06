#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "Surface.cpp"
#include "Socket.h"
#define AJUSTE 5
using namespace std;

class Static{
protected:
	int id;
	SDL_Rect botton_pos;
	SDL_Rect converted_pos;
	std::shared_ptr<Surface> botton_surface;
	int team;
public:
	Static();
	//GET ID
	int get_id();
	SDL_Rect* getpos();
	SDL_Rect* get_converted_pos(int x,int y);
	//Obtiene size y
	int h_size();
	//Obtiene size x
	int v_size();
	//Obtiene y(esquina izquierda arriba)
	int y_pos();
	//Obtiene y(esquina izquierda arriba)
	int x_pos();
	int mine();
	bool is_inside_screen(int x, int y, int size_x, int size_y);
	bool click_is_inside_static(int x, int y);
	SDL_Surface* getsurf();
	~Static();
	
};

