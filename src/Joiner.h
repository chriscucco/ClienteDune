#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "Music.cpp"
#include <stdio.h>
#include <iostream>
#include "Timer.cpp"
#include "Game.cpp"
#include <fstream>
#include <memory>
#include <string>
#include <vector>

class Joiner{
private:
	int my_id;
	SDL_Renderer* r;
	Texture* t;
	Socket* skt;
	int Width;
	int Height;
	int fps;
	std::shared_ptr<MasterSurface> master;
	std::vector<std::shared_ptr<Text>> static_text;
	std::vector<std::shared_ptr<Text>> matchs;
	std::shared_ptr<Text> current_match;
	std::shared_ptr<Text> join;	
public:
	Joiner(SDL_Renderer* renderer, Texture* texture,Socket* s, int w, int h,std::shared_ptr<MasterSurface> m,int f,int id);
	void send_close();
	void refresh_screen();
	bool run();
	std::shared_ptr<Text> search_matchs(int x,int y);
	bool clicked(int x,int y);
	bool wait_screen(Music* music);
	~Joiner();
};