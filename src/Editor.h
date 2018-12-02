#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "Game.cpp"
#include "Timer.cpp"
#include <fstream>
#include <memory>
#include <string>
#include <vector>


class Editor{
private:
	std::shared_ptr<MasterSurface> master;
	SDL_Texture *background;
	SDL_Renderer *renderer;
	std::vector<std::shared_ptr<Static>> statics;
	std::vector<std::shared_ptr<Terrain>> terrains;
	std::vector<std::shared_ptr<Button>> buttons;
	std::shared_ptr<Button> current_button{nullptr};
	std::shared_ptr<Button> charge_button;
	Socket* s;
	int my_id;
	int size_x;
	int size_y;
	int game_size_x;
	int game_size_y;
public:
	Editor(SDL_Renderer *r,SDL_Texture *t,Socket* skt, int x, int y,std::shared_ptr<MasterSurface> master, int id);
	void init_buttons();
	void refreshscreen();
	void copystatics();
	void send_close();
	void copyterrain();
	void copybuttons();
	void add_duna(int id,int size_x, int size_y, int x, int y);
	void add_cima(int id,int size_x, int size_y, int x, int y);
	void add_especiafuerte(int id,int size_x, int size_y, int x, int y);
	void add_especiasuave(int id,int size_x, int size_y, int x, int y);
	void add_precipicio(int id,int size_x, int size_y, int x, int y);
	bool can_put_static(int x, int y, int w, int h);
	int get_pos_static(int x, int y);
	int get_pos_terrain(int x, int y);
	bool is_able(int x, int y);
	void add_roca(int id,int size_x, int size_y, int x, int y);
	std::shared_ptr<Button> search_button_by_clic(int x,int y);
	void process_clic(int x, int y);
	void add_centre(int x, int y);
	void remove_element(int x, int y);
	void insert_terrain(int x,int y,int w,int h);
	void add_terrain(int x1, int y1);
	bool clicked(int x,int y);
	void charge_map();
	void save();
	void select_map_size();
	void process_map_size(std::vector<std::shared_ptr<Button>> static_buttons,std::vector<std::shared_ptr<Button>> touchable_buttons,std::vector<std::shared_ptr<Text>> static_text);
	bool clicked_map_size(std::vector<std::shared_ptr<Button>> touchable_buttons,std::shared_ptr<Text> x_value,std::shared_ptr<Text> y_value,int x, int y);
	~Editor();
};


