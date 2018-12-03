#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "CentroDeConstruccion.cpp"
#include "CuartelAtreides.cpp"
#include "CuartelHarkonnen.cpp"
#include "CuartelOrdos.cpp"
#include "FabricaLigera.cpp"
#include "FabricaPesada.cpp"
#include "Palacio.cpp"
#include "Refineria.cpp"
#include "Silo.cpp"
#include "TrampaDeAire.cpp"
#include "Trike.cpp"
#include "Desviador.cpp"
#include "Devastador.cpp"
#include "Tanque.cpp"
#include "SonicTank.cpp"
#include "Raider.cpp"
#include "Cosechadora.cpp"
#include "Cima.cpp"
#include "Duna.cpp"
#include "EspeciaSuave.cpp"
#include "EspeciaFuerte.cpp"
#include "Precipicio.cpp"
#include "Roca.cpp"
#include "Gusano.cpp"
#include "Timer.cpp"
#include "ExplosionTanque.cpp"
#include "ExplosionPersonaje.cpp"
#include "ExplosionFuerte.cpp"
#include "Button_CentroDeConstruccion.cpp"
#include "Button_Cosechadora.cpp"
#include "Button_CuartelAtreides.cpp"
#include "Button_CuartelHarkonnen.cpp"
#include "Button_CuartelOrdos.cpp"
#include "Button_Desviador.cpp"
#include "Button_Devastador.cpp"
#include "Button_FabricaLigera.cpp"
#include "Button_FabricaPesada.cpp"
#include "Button_Fremen.cpp"
#include "Button_InfanteriaLigera.cpp"
#include "Button_InfanteriaPesada.cpp"
#include "Button_Palacio.cpp"
#include "Button_Refineria.cpp"
#include "Button_Raider.cpp"
#include "Button_Sardaukar.cpp"
#include "Button_Silo.cpp"
#include "Button_Tanque.cpp"
#include "Button_SonicTank.cpp"
#include "Button_TrampaDeAire.cpp"
#include "Button_Trike.cpp"
#include "Button_Money.cpp"
#include "Sardaukar.cpp"
#include "Fremen.cpp"
#include "InfanteriaLigera.cpp"
#include "InfanteriaPesada.cpp"
#include "Socket.cpp"
#include "Text.cpp"
#include "Texture.cpp"
#include "Surface.cpp"
#include "MasterSurface.cpp"
#include "EndOfGame.cpp"
#include <fstream>
#include <memory>
#include <string>
#include <vector>


class Game{
private:
	int corner_x;
	int corner_y;
	int map_size_x;
	int map_size_y;
	std::shared_ptr<MasterSurface> master;
	int my_id;
	SDL_Texture *background;
	SDL_Texture *win_background;
	SDL_Texture *loose_background;
	SDL_Renderer *renderer;
	std::vector<std::shared_ptr<Static>> statics;
	std::vector<std::shared_ptr<Moveable>> moveables;
	std::vector<std::shared_ptr<Animation>> animated;
	std::vector<std::shared_ptr<Terrain>> terrains;
	std::vector<std::shared_ptr<Button>> buttons;
	Socket* s;
	std::vector<std::shared_ptr<Moveable>> selected;
	std::vector<std::shared_ptr<Button>> button_selected;
	int button_size_x;
	int button_size_y;
	int size_x;
	int size_y;
	std::shared_ptr<Text> energy;
	std::shared_ptr<Text> money;
	std::shared_ptr<Text> notice{nullptr};
public:
	void init_buttons();
	int give_id();
	void go_right();
	void go_left();
	void go_down();
	void go_up();
	Game(SDL_Renderer *r,SDL_Texture *t,SDL_Texture *w,SDL_Texture *l,Socket* skt, int id, int x, int y,std::shared_ptr<MasterSurface> master);
	int get_current_corner_x();
	int get_current_corner_y();
	void final_screen();
	void add_centrodeconstruccion(int id,int size_x, int size_y, int x, int y, int team);
	void add_tomadeaire(int id,int size_x, int size_y, int x, int y, int team);
	void add_refineria(int id,int size_x, int size_y, int x, int y, int team);
	void modify_energy(int i);
	void modify_money(int i);
	void add_silo(int id,int size_x, int size_y, int x, int y, int team);
	void add_fabricaligera(int id,int size_x, int size_y, int x, int y, int team);
	void add_sardaukar(int id,int size_x, int size_y, int x, int y, int team);
	void add_infanterialigera(int id,int size_x, int size_y, int x, int y, int team);
	void add_infanteriapesada(int id,int size_x, int size_y, int x, int y, int team);
	void add_fremen(int id,int size_x, int size_y, int x, int y, int team);
	void add_febricapesada(int id,int size_x, int size_y, int x, int y, int team);
	void add_cuartelatreides(int id,int size_x, int size_y, int x, int y, int team);
	void add_cuartelharkonnen(int id,int size_x, int size_y, int x, int y, int team);
	void add_cuartelordos(int id,int size_x, int size_y, int x, int y, int team);
	void add_palacio(int id,int size_x, int size_y, int x, int y, int team);
	void add_desviador(int id,int size_x, int size_y, int x, int y, int team);
	void add_notice(int i);
	void add_devastador(int id,int size_x, int size_y, int x, int y, int team);
	void add_raider(int id,int size_x, int size_y, int x, int y, int team);
	void add_sonictank(int id,int size_x, int size_y, int x, int y, int team);
	void add_cosechadora(int id,int size_x, int size_y, int x, int y, int team);
	void add_tanque(int id,int size_x, int size_y, int x, int y, int team);
	void add_trike(int id,int size_x, int size_y, int x, int y, int team);
	void add_duna(int id,int size_x, int size_y, int x, int y);
	void add_cima(int id,int size_x, int size_y, int x, int y);
	void add_especiafuerte(int id,int size_x, int size_y, int x, int y);
	void add_especiasuave(int id,int size_x, int size_y, int x, int y);
	void add_precipicio(int id,int size_x, int size_y, int x, int y);
	void add_roca(int id,int size_x, int size_y, int x, int y);
 	void free_selected();
 	void change_moveable_team(int id, int id_type, int new_team);
 	bool exist_moveable(int id);
 	void stop_attack(int id);
	Socket* get_socket();
	int get_my_id();
	void modify_texture(SDL_Texture* t);
	void finish_game(bool win);
	void add(int type,int id,int size_x, int size_y, int x, int y, int team);
	void add_static(int type,int id,int size_x, int size_y, int x, int y, int team);
	void add_terrain(int type,int id, int size_x, int size_y, int x, int y);
	void add_gusano(int size_x, int size_y,int x,int y);
	void add_big_explosion(int size_x, int size_y,int x,int y);
	void add_tank_explosion(int size_x, int size_y,int x,int y);
	void add_moveable_explosion(int size_x, int size_y,int x,int y);
	void add_animation(int type,int size_x, int size_y,int x,int y);
	void add_moveable(int type,int id,int size_x, int size_y, int x, int y,int team);
	void copystatics();
	void copyanimated();
	void copymoveables();
	void copyterrain();
	void copybuttons();
	void copypointers();
	void copytext();
	void refreshscreen();
	std::shared_ptr<Moveable> search_moveable_by_id(int id);
	std::shared_ptr<Static> search_static_by_id(int id);
	std::shared_ptr<Terrain> search_especia_by_coordinate(int x, int y);
	std::shared_ptr<Moveable> search_enemy_moveable_by_pos(int x, int y);
	std::shared_ptr<Moveable> search_my_moveable_by_pos(int x, int y);
	std::shared_ptr<Static> search_enemy_static_by_pos(int x, int y);
	std::shared_ptr<Static> search_my_static_by_pos(int x, int y);
	std::shared_ptr<Button> search_button_by_pos(int x, int y);
	bool destroy_moveable(int id);
	bool destroy_static(int id);
	bool destroy_terrain(int id);
	void destroy_unit(int id);
	void send_move(int x, int y);
	void send_attack(int id);
	bool check_if_is_something_mine(int x, int y);
	void right_click_selected(int x, int y);
	void selected_moveable(std::shared_ptr<Moveable> m);
	void selected_button(std::shared_ptr<Button> s);
	bool is_selected_sell_button();
	std::shared_ptr<Button> is_selected_unit_button();
	std::shared_ptr<Button> is_selected_building_button();
	void selected_static(std::shared_ptr<Static> s);
	void selected_nothing(int x, int y);
	void clicked(int x, int y, bool is_right_click);
    void clicked_zone(SDL_Rect pos);
    void change_sizes(int init_x, int init_y, int map_x, int map_y);
	~Game();
};


