#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "Surface.cpp"
using namespace std;

class Terrain{
protected:
	int id;
	SDL_Rect botton_pos;
	SDL_Rect converted_pos;
	std::shared_ptr<Surface> botton_surface;
	bool especia;
public:
	Terrain();	
	//Obtiene ID
	int get_id();
	SDL_Rect* getpos();
	SDL_Rect* get_converted_pos(int x,int y);
	SDL_Surface* getsurf();
	bool is_in_click(int x, int y);
	//Obtiene size_x
	int h_size();
	bool is_inside_screen(int x, int y, int size_x, int size_y);
	//Obtiene size_y
	int v_size();
	//Obtiene y(esquina izquierda arriba)
	int y_pos();
	//Obtiene x(esquina izquierda arriba)
	int x_pos();
	bool is_especia();
	~Terrain();
}; 


