#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "Timer.cpp"
#include "Game.cpp"
#include <fstream>
#include <memory>
#include <string>
#include <vector>

class Creator{
private:
	SDL_Renderer* r;
	Texture* t;
	Socket* skt;
	int Width;
	int Height;
	int fps;
	std::shared_ptr<MasterSurface> master;
	std::vector<std::shared_ptr<Text>> static_text;
	std::vector<std::shared_ptr<Text>> max_players;
	std::vector<std::shared_ptr<Text>> maps;
	std::shared_ptr<Text> current_id;
	std::shared_ptr<Text> current_max;
	std::shared_ptr<Text> create;	
public:
	Creator(SDL_Renderer* renderer, Texture* texture,Socket* s, int w, int h,std::shared_ptr<MasterSurface> m, int f);
	bool run();
	void refresh_screen();
	bool clicked(int x,int y);
	std::shared_ptr<Text> search_maps(int x,int y);
	std::shared_ptr<Text> search_maxplayers(int x,int y);
	void wait_screen(int id);
	~Creator();
	
};