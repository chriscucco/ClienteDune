#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "Surface.cpp"
#define AJUSTE 5

class Moveable{
protected:
	int id;
	SDL_Rect botton_pos;
	SDL_Rect converted_pos;
	std::vector<std::shared_ptr<Surface>> botton_surface;
	int current_path;
	int team;
public:
	Moveable();
	SDL_Rect* getpos();
	SDL_Rect* get_converted_pos(int x,int y);
	virtual SDL_Surface* getsurf();
	int get_id();
	bool is_in(SDL_Rect selected);
	virtual void modify_pos(int x, int y)=0;
	virtual bool is_cosechadora();
	virtual void attack(int x,int y){}
	int h_size();
	int v_size();
	int y_pos();
	int x_pos();
	bool is_inside_screen(int x, int y, int size_x, int size_y);
	bool click_is_inside_moveable(int x, int y);
	int get_team();
	void set_id(int i);
	void set_team(int i);
	void set_w(int i);
	void set_h(int i);
	void set_x(int i);
	void set_y(int i);
	void add_surface(std::string text);
	void set_current(int i);
	virtual ~Moveable();
	
};

