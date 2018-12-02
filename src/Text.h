#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Surface.cpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define AJUSTE 5


class Text{
private:
	SDL_Renderer* renderer;
	SDL_Rect botton_pos;
	std::string text;
	int value{0};
	int repeats;
	std::shared_ptr<Surface> surf{nullptr};
	bool has_to_actualize;
public:
	Text(SDL_Renderer* r,std::string t ,int size_x, int size_y, int x, int y, int iteration);
	SDL_Rect* getpos();
	void modify_value(int i);
	void modify_texture();
	bool click_is_inside_text(int x, int y);
	void printed();
	int get_value();
	int get_remains();
	void modify_id(int i);
	SDL_Surface* get_surface();
	std::shared_ptr<Surface> get_surface(int i);
	std::shared_ptr<Surface> get_value_surface();
	int get_x();
	int get_y();
	int get_w();
	int get_h();
	~Text();	
};
