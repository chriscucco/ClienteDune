#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Surface.cpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

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
	int get_remains();
	SDL_Surface* get_surface();
	~Text();	
};
