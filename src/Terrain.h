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
	std::shared_ptr<Surface> botton_surface;
	bool especia;
public:
	Terrain();	
	int get_id();
	SDL_Rect* getpos();
	SDL_Surface* getsurf();
	bool is_in_click(int x, int y);
	int h_size();
	int v_size();
	int y_pos();
	int x_pos();
	bool is_especia();
	~Terrain();
}; 


