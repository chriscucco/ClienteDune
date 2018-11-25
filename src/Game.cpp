#include "Game.h"
#define CENTRODECONSTRUCCION 0
#define TRAMPADEAIRE 1
#define REFINERIA 2
#define SILO 3
#define FABRICALIGERA 4
#define FABRICAPESADA 5
#define CUARTELATREIDES 6
#define CUARTELHARKONNEN 7
#define CUARTELORDOS 8
#define PALACIO 9
#define INFANTERIALIGERA 10
#define INFANTERIAPESADA  11
#define FREMEN 12
#define SARDAUKAR 13
#define TRIKE 14
#define RAIDER 15
#define TANQUE 16
#define SONICTANK 17
#define DESVIADOR 18
#define DEVASTADOR 19
#define COSECHADORA 20
#define ROCA 30
#define DUNA  31
#define ESPECIAFUERTE 32
#define ESPECIASUAVE 33
#define CIMA  34
#define PRECIPICIO 35
#define GUSANO 50
#define EXPLOSIONFUERTE 51
#define EXPLOSIONTANQUE 52
#define EXPLOSIONPERSONAJE 53

void Game::init_buttons(){
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	int Width = DM.w;
	int Height = DM.h;
	std::shared_ptr<Button> b1(new Button_CentroDeConstruccion(CENTRODECONSTRUCCION,this->button_size_x,this->button_size_y,(Width/2)-(this->button_size_x*5),0,this->master->get_button_centrodeconstruccion_surface()));
	std::shared_ptr<Button> b2(new Button_CuartelAtreides(CUARTELATREIDES,this->button_size_x,this->button_size_y,(Width/2)-(this->button_size_x*4),0,this->master->get_button_cuartelatreides_surface()));
	std::shared_ptr<Button> b3(new Button_CuartelHarkonnen(CUARTELHARKONNEN,this->button_size_x,this->button_size_y,(Width/2)-(this->button_size_x*3),0,this->master->get_button_cuartelharkonnen_surface()));
	std::shared_ptr<Button> b4(new Button_CuartelOrdos(CUARTELORDOS,this->button_size_x,this->button_size_y,(Width/2)-(this->button_size_x*2),0,this->master->get_button_cuartelordos_surface()));
	std::shared_ptr<Button> b5(new Button_FabricaLigera(FABRICALIGERA,this->button_size_x,this->button_size_y,(Width/2)-(this->button_size_x),0,this->master->get_button_fabricaligera_surface()));
	std::shared_ptr<Button> b6(new Button_FabricaPesada(FABRICAPESADA,this->button_size_x,this->button_size_y,(Width/2),0,this->master->get_button_fabricapesada_surface()));
	std::shared_ptr<Button> b7(new Button_Palacio(PALACIO,this->button_size_x,this->button_size_y,(Width/2)+(this->button_size_x),0,this->master->get_button_palacio_surface()));
	std::shared_ptr<Button> b8(new Button_Refineria(REFINERIA,this->button_size_x,this->button_size_y,(Width/2)+(this->button_size_x*2),0,this->master->get_button_refineria_surface()));
	std::shared_ptr<Button> b9(new Button_Silo(SILO,this->button_size_x,this->button_size_y,(Width/2)+(this->button_size_x*3),0,this->master->get_button_silo_surface()));
	std::shared_ptr<Button> b10(new Button_TrampaDeAire(TRAMPADEAIRE,this->button_size_x,this->button_size_y,(Width/2)+(this->button_size_x*4),0,this->master->get_button_trampadeaire_surface()));
	std::shared_ptr<Button> b11(new Button_Cosechadora(COSECHADORA,this->button_size_x,this->button_size_y,(Width-this->button_size_x-5),(Height/2-this->button_size_y*6),this->master->get_button_cosechadora_surface()));
	std::shared_ptr<Button> b12(new Button_Desviador(DESVIADOR,this->button_size_x,this->button_size_y,(Width-this->button_size_x-5),(Height/2-this->button_size_y*5),this->master->get_button_desviador_surface()));
	std::shared_ptr<Button> b13(new Button_Devastador(DEVASTADOR,this->button_size_x,this->button_size_y,(Width-this->button_size_x-5),(Height/2-this->button_size_y*4),this->master->get_button_devastador_surface()));
	std::shared_ptr<Button> b14(new Button_Raider(RAIDER,this->button_size_x,this->button_size_y,(Width-this->button_size_x-5),(Height/2-this->button_size_y*3),this->master->get_button_raider_surface()));
	std::shared_ptr<Button> b15(new Button_SonicTank(SONICTANK,this->button_size_x,this->button_size_y,(Width-this->button_size_x-5),(Height/2-this->button_size_y*2),this->master->get_button_sonictank_surface()));
	std::shared_ptr<Button> b16(new Button_Tanque(TANQUE,this->button_size_x,this->button_size_y,(Width-this->button_size_x-5),(Height/2-this->button_size_y),this->master->get_button_tanque_surface()));
	std::shared_ptr<Button> b17(new Button_Trike(TRIKE,this->button_size_x,this->button_size_y,(Width-this->button_size_x-5),(Height/2),this->master->get_button_trike_surface()));
	std::shared_ptr<Button> b18(new Button_Fremen(FREMEN,this->button_size_x,this->button_size_y,(Width-this->button_size_x-5),(Height/2+this->button_size_y),this->master->get_button_fremen_surface()));
	std::shared_ptr<Button> b19(new Button_InfanteriaLigera(INFANTERIALIGERA,this->button_size_x,this->button_size_y,(Width-this->button_size_x-5),(Height/2+this->button_size_y*2),this->master->get_button_infanterialigera_surface()));
	std::shared_ptr<Button> b20(new Button_InfanteriaPesada(INFANTERIAPESADA,this->button_size_x,this->button_size_y,(Width-this->button_size_x-5),(Height/2+this->button_size_y*3),this->master->get_button_infanteriapesada_surface()));
	std::shared_ptr<Button> b21(new Button_Sardaukar(SARDAUKAR,this->button_size_x,this->button_size_y,(Width-this->button_size_x-5),(Height/2+this->button_size_y*4),this->master->get_button_sardaukar_surface()));
	this->buttons.push_back(b1);
	this->buttons.push_back(b2);
	this->buttons.push_back(b3);
	this->buttons.push_back(b4);
	this->buttons.push_back(b5);
	this->buttons.push_back(b6);
	this->buttons.push_back(b7);
	this->buttons.push_back(b8);
	this->buttons.push_back(b9);
	this->buttons.push_back(b10);
	this->buttons.push_back(b11);
	this->buttons.push_back(b12);
	this->buttons.push_back(b13);
	this->buttons.push_back(b14);
	this->buttons.push_back(b15);
	this->buttons.push_back(b16);
	this->buttons.push_back(b17);
	this->buttons.push_back(b18);
	this->buttons.push_back(b19);
	this->buttons.push_back(b20);
	this->buttons.push_back(b21);
}

int Game::give_id(){
	return this->my_id;
}


Game::Game(SDL_Renderer *r,SDL_Texture *t,SDL_Texture *w,SDL_Texture *l,Socket* skt, int id, int button_x, int button_y, int x, int y){
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	int Width = DM.w;
	this->my_id=id;
	this->renderer=r;
	this->background=t;
	this->win_background=w;
	this->loose_background=l;
	this->s=skt;
	this->button_size_x=button_x;
	this->button_size_y=button_y;
	this->size_x=x;
	this->size_y=y;
	this->init_buttons();
	std::shared_ptr<Text> energy_pointer(new Text(this->renderer,"Energia: ",150,50,(Width/5)-150,0,0));
	std::shared_ptr<Text> money_pointer(new Text(this->renderer,"Dinero: $",150,50,((Width/5)*4),0,0));
	this->energy=energy_pointer;
	this->money=money_pointer;
}


void Game::add_notice(int i){
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	int w = DM.w;
	int h = DM.h;
	std::string t;
	switch (i){
		case CENTRODECONSTRUCCION:
			t="Centro De Construccion";
			break;
		case TRAMPADEAIRE:
			t="Trampa de aire";
			break;
		case REFINERIA:
			t="Refineria";
			break;
		case SILO:
			t="Silo";
			break;
		case FABRICALIGERA:
			t="Fabrica Ligera";
			break;
		case FABRICAPESADA:
			t="Fabrica Pesada";
			break;
		case CUARTELATREIDES:
			t="Cuartel Atreides";
			break;
		case CUARTELHARKONNEN:
			t="Cuartel Harkonnen";
			break;
		case CUARTELORDOS:
			t="Cuartel Ordos";
			break;
		case PALACIO:
			t="Palacio";
			break;
		case INFANTERIALIGERA:
			t="Infanteria Ligera";
			break;
		case INFANTERIAPESADA:
			t="Infanteria Pesada";
			break;
		case FREMEN:
			t="Fremen";
			break;
		case SARDAUKAR:
			t="Sardaukar";
			break;
		case TRIKE:
			t="Trike";
			break;
		case RAIDER:
			t="Raider";
			break;
		case TANQUE:
			t="Tanque";
			break;
		case SONICTANK:
			t="SonicTank";
			break;
		case DESVIADOR:
			t="Desviador";
			break;
		case DEVASTADOR:
			t="Devastador";
			break;
		case COSECHADORA:
			t="Cosechadora";
			break;
	}
	std::string messaje="No se pudo crear el objeto:     ";
	messaje+=t;
	std::shared_ptr<Text> msj(new Text(this->renderer,messaje,500,50,(w/2)-250,(h-120),120));
	this->notice=msj;
}


void Game::add_centrodeconstruccion(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Static> d(new CentroDeConstruccion(id,size_x,size_y,x,y,team,this->master->get_centrodeconstruccion_surface()));
	this->statics.push_back(d);
}


void Game::add_tomadeaire(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Static> d(new TrampaDeAire(id,size_x,size_y,x,y,team));
	this->statics.push_back(d);
}


void Game::add_refineria(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Static> d(new Refineria(id,size_x,size_y,x,y,team));
	this->statics.push_back(d);
}


void Game::add_silo(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Static> d(new Silo(id,size_x,size_y,x,y,team));
	this->statics.push_back(d);
}

	
void Game::add_fabricaligera(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Static> d(new FabricaLigera(id,size_x,size_y,x,y,team));
	this->statics.push_back(d);
}

void Game::add_sardaukar(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Moveable> m(new Sardaukar(id,size_x,size_y,x,y,team));
	this->moveables.push_back(m);
}

void Game::add_infanterialigera(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Moveable> m(new InfanteriaLigera(id,size_x,size_y,x,y,team));
	this->moveables.push_back(m);
}


void Game::add_infanteriapesada(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Moveable> m(new InfanteriaPesada(id,size_x,size_y,x,y,team));
	this->moveables.push_back(m);
}

void Game::add_fremen(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Moveable> m(new Fremen(id,size_x,size_y,x,y,team));
	this->moveables.push_back(m);
}


	
void Game::add_febricapesada(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Static> d(new FabricaPesada(id,size_x,size_y,x,y,team));
	this->statics.push_back(d);
}

	
void Game::add_cuartelatreides(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Static> d(new CuartelAtreides(id,size_x,size_y,x,y,team, this->master->get_cuartelatreides_surface()));
	this->statics.push_back(d);
}

	
void Game::add_cuartelharkonnen(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Static> d(new CuartelHarkonnen(id,size_x,size_y,x,y,team, this->master->get_cuartelharkonnen_surface()));
	this->statics.push_back(d);
}

	
void Game::add_cuartelordos(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Static> d(new CuartelOrdos(id,size_x,size_y,x,y,team, this->master->get_cuartelordos_surface()));
	this->statics.push_back(d);
}

	
void Game::add_palacio(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Static> d(new Palacio(id,size_x,size_y,x,y,team));
	this->statics.push_back(d);
}

void Game::add_desviador(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Moveable> m(new Desviador(id,size_x,size_y,x,y,team,this->master->get_desviador_surface()));
	this->moveables.push_back(m);
}

void Game::add_devastador(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Moveable> m(new Devastador(id,size_x,size_y,x,y,team,this->master->get_devastador_surface()));
	this->moveables.push_back(m);
}

void Game::add_raider(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Moveable> m(new Raider(id,size_x,size_y,x,y,team));
	this->moveables.push_back(m);
}

void Game::add_sonictank(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Moveable> m(new SonicTank(id,size_x,size_y,x,y,team));
	this->moveables.push_back(m);
}


void Game::add_cosechadora(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Moveable> m(new Cosechadora(id,size_x,size_y,x,y,team,this->master->get_cosechadora_surface()));
	this->moveables.push_back(m);
}


void Game::add_tanque(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Moveable> m(new Tanque(id,size_x,size_y,x,y,team));
	this->moveables.push_back(m);
}

void Game::add_trike(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Moveable> m(new Trike(id,size_x,size_y,x,y,team,this->master->get_trike_surface()));
	this->moveables.push_back(m);
}

void Game::add_duna(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Terrain> m(new Duna(id,size_x,size_y,x,y,this->master->get_duna_surface()));
	this->terrains.push_back(m);
}

void Game::add_cima(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Terrain> m(new Cima(id,size_x,size_y,x,y,this->master->get_cima_surface()));
	this->terrains.push_back(m);
}

void Game::add_especiafuerte(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Terrain> m(new EspeciaFuerte(id,size_x,size_y,x,y,this->master->get_especiafuerte_surface()));
	this->terrains.push_back(m);
}


void Game::add_especiasuave(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Terrain> m(new EspeciaSuave(id,size_x,size_y,x,y,this->master->get_especiasuave_surface()));
	this->terrains.push_back(m);
}


void Game::add_precipicio(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Terrain> m(new Precipicio(id,size_x,size_y,x,y,this->master->get_precipicio_surface()));
	this->terrains.push_back(m);
}


void Game::add_roca(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Terrain> m(new Roca(id,size_x,size_y,x,y,this->master->get_roca_surface()));
	this->terrains.push_back(m);
}


void Game::free_selected(){
	unsigned int size=this->selected.size();
	for (unsigned int i=0; i <size; ++i){
		this->selected.pop_back();
	}
	unsigned int but_size=this->button_selected.size();
	for (unsigned int i = 0; i < but_size; ++i){
		this->button_selected.pop_back();
	}
}


Socket* Game::get_socket(){
	return this->s;
}


int Game::get_my_id(){
	return this->my_id;
}

void Game::modify_texture(SDL_Texture* t){
	this->background=t;
}


void Game::finish_game(bool win){
	unsigned int i=0;
	while(i<this->moveables.size()){
		this->moveables.pop_back();
	}
	i=0;
	while(i<this->statics.size()){
		this->statics.pop_back();
	}
	i=0;
	while(i<this->terrains.size()){
		this->terrains.pop_back();
	}
	i=0;
	while(i<this->buttons.size()){
		this->buttons.pop_back();
	}
	i=0;
	while(i<this->animated.size()){
		this->animated.pop_back();
	}
	if(win){
		modify_texture(this->win_background);
	} else {
		modify_texture(this->loose_background);
	}
}

void Game::add(int type,int id,int size_x, int size_y, int x, int y, int team){
	if((type>=0)&&(type<=9)){
		this->add_static(type,id,size_x,size_y,x,y,team);
	} else if((type>=10)&&(type<=20)){
		this->add_moveable(type,id,size_x,size_y,x,y,team);
	}
}


void Game::add_static(int type,int id,int size_x, int size_y, int x, int y, int team){
	switch (type){
		case CENTRODECONSTRUCCION:
			this->add_centrodeconstruccion(id,size_x,size_y,x,y,team);
			break;
		case TRAMPADEAIRE:
			this->add_tomadeaire(id,size_x,size_y,x,y,team);
			break;
		case REFINERIA:
			this->add_refineria(id,size_x,size_y,x,y,team);
			break;
		case SILO:
			this->add_silo(id,size_x,size_y,x,y,team);
			break;
		case FABRICALIGERA:
			this->add_fabricaligera(id,size_x,size_y,x,y,team);
			break;
		case FABRICAPESADA:
			this->add_febricapesada(id,size_x,size_y,x,y,team);
			break;
		case CUARTELATREIDES:
			this->add_cuartelatreides(id,size_x,size_y,x,y,team);
			break;
		case CUARTELHARKONNEN:
			this->add_cuartelharkonnen(id,size_x,size_y,x,y,team);
			break;
		case CUARTELORDOS:
			this->add_cuartelordos(id,size_x,size_y,x,y,team);
			break;
		case PALACIO:
			this->add_palacio(id,size_x,size_y,x,y,team);
			break;
	}	
}

void Game::add_terrain(int type,int id, int size_x, int size_y, int x, int y){
	switch(type){
		case ROCA:
			this->add_roca(id,size_x,size_y,x,y);
			break;
		case DUNA:
			this->add_duna(id,size_x,size_y,x,y);
			break;
		case ESPECIAFUERTE:
			this->add_especiafuerte(id,size_x,size_y,x,y);
			break;
		case ESPECIASUAVE:
			this->add_especiasuave(id,size_x,size_y,x,y);
			break;
		case CIMA:
			this->add_cima(id,size_x,size_y,x,y);
			break;
		case PRECIPICIO:
			this->add_precipicio(id,size_x,size_y,x,y);
			break;
	}
}

void Game::add_gusano(int size_x, int size_y,int x,int y){
	std::shared_ptr<Animation> a(new Gusano(size_x,size_x,x,y));
	this->animated.push_back(a);
}


void Game::add_big_explosion(int size_x, int size_y,int x,int y){
	std::shared_ptr<Animation> a(new ExplosionFuerte(size_x,size_x,x,y,this->master->get_explosionfuerte_surface()));
	this->animated.push_back(a);
}


void Game::add_tank_explosion(int size_x, int size_y,int x,int y){
	std::shared_ptr<Animation> a(new ExplosionTanque(size_x,size_x,x,y,this->master->get_explosiontanque_surface()));
	this->animated.push_back(a);
}

void Game::add_moveable_explosion(int size_x, int size_y,int x,int y){
	std::shared_ptr<Animation> a(new ExplosionPersonaje(size_x,size_x,x,y,this->master->get_explosionpersonaje_surface()));
	this->animated.push_back(a);
}


void Game::add_animation(int type,int size_x, int size_y,int x,int y){
	switch(type){
		case GUSANO:
			this->add_gusano(size_x,size_y,x,y);
			break;
		case EXPLOSIONFUERTE:
			this->add_big_explosion(size_x,size_y,x,y);
			break;
		case EXPLOSIONTANQUE:
			this->add_tank_explosion(size_x,size_y,x,y);
			break;
		case EXPLOSIONPERSONAJE:
			this->add_moveable_explosion(size_x,size_y,x,y);
			break;
	}
}


void Game::add_moveable(int type,int id,int size_x, int size_y, int x, int y,int team){
	switch (type){
		case INFANTERIALIGERA:
			this->add_infanterialigera(id,size_x,size_y,x,y,team);
			break;
		case INFANTERIAPESADA:
			this->add_infanteriapesada(id,size_x,size_y,x,y,team);
			break;
		case FREMEN:
			this->add_fremen(id,size_x,size_y,x,y,team);
			break;
		case SARDAUKAR:
			this->add_sardaukar(id,size_x,size_y,x,y,team);
			break;
		case TRIKE:
			this->add_trike(id,size_x,size_y,x,y,team);
			break;
		case RAIDER:
			this->add_raider(id,size_x,size_y,x,y,team);
			break;
		case TANQUE:
			this->add_tanque(id,size_x,size_y,x,y,team);
			break;
		case SONICTANK:
			this->add_sonictank(id,size_x,size_y,x,y,team);
			break;
		case DESVIADOR:
			this->add_desviador(id,size_x,size_y,x,y,team);
			break;
		case DEVASTADOR:
			this->add_devastador(id,size_x,size_y,x,y,team);
			break;
		case COSECHADORA:
			this->add_cosechadora(id,size_x,size_y,x,y,team);
			break;
	}
}


void Game::copystatics(){
	unsigned int i=0;
	while(i<this->statics.size()){
		Texture t(this->renderer, this->statics.at(i)->getsurf());
		SDL_RenderCopy(this->renderer, t.get_texture(), NULL, this->statics.at(i)->getpos());
		i++;
	}
}


void Game::copyanimated(){
	unsigned int i=0;
	while(i<this->animated.size()){
		if(!(this->animated.at(i)->finished())){
			Texture t(this->renderer,this->animated.at(i)->getsurf());
			SDL_RenderCopy(this->renderer, t.get_texture(), NULL, this->animated.at(i)->getpos());
			i++;
		} else {
			this->animated.erase(this->animated.begin()+i);
		}
	}
}

void Game::copymoveables(){
	unsigned int i=0;
	while(i<this->moveables.size()){
		Texture t(this->renderer, this->moveables.at(i)->getsurf());
		SDL_RenderCopy(this->renderer, t.get_texture(), NULL, this->moveables.at(i)->getpos());
		i++;
	}		
}


void Game::copyterrain(){
	unsigned int i=0;
	while(i<this->terrains.size()){
		Texture t(this->renderer, this->terrains.at(i)->getsurf());
		SDL_RenderCopy(this->renderer, t.get_texture(), NULL, this->terrains.at(i)->getpos());
		i++;
	}	
}


void Game::copytext(){
	Texture t(this->renderer,this->energy->get_surface());
	SDL_RenderCopy(this->renderer, t.get_texture(),NULL,this->energy->getpos());
	Texture t2(this->renderer,this->money->get_surface());
	SDL_RenderCopy(this->renderer, t2.get_texture(),NULL,this->money->getpos());
	if(this->notice!=nullptr){
		if(this->notice->get_remains()>0){
			this->notice->printed();
			Texture t3(this->renderer, this->notice->get_surface());
			SDL_RenderCopy(this->renderer,t3.get_texture(),NULL,this->notice->getpos());
		} else {
			this->notice=nullptr;
		}
	}

}



void Game::copybuttons(){
	unsigned int i=0;
	while(i<this->buttons.size()){
		Texture t(this->renderer, this->buttons.at(i)->getsurf());
		SDL_RenderCopy(this->renderer, t.get_texture(), NULL, this->buttons.at(i)->getpos());
		i++;
	}	
}



void Game::modify_money(int i){
	this->money->modify_value(i);
}

void Game::modify_energy(int i){
	this->energy->modify_value(i);
}

	
void Game::refreshscreen(){
	SDL_RenderClear(this->renderer);
	SDL_RenderCopy(this->renderer, this->background, NULL, NULL);
	copybuttons();
	copyterrain();
	copystatics();
	copymoveables();
	copyanimated();
	copybuttons();
	copytext();
	SDL_RenderPresent(this->renderer);
}

std::shared_ptr<Moveable> Game::search_moveable_by_id(int id){
	unsigned int i=0;
	bool found=false;
	while ((!found)&&(i<this->moveables.size())){
		if(this->moveables.at(i)->get_id()==id){
			found=true;
		}
		i++;
	}
	return (this->moveables.at(i-1));	
}

std::shared_ptr<Static> Game::search_static_by_id(int id){
	unsigned int i=0;
	bool found=false;
	while ((!found)&&(i<this->statics.size())){
		if(this->statics.at(i)->get_id()==id){
			found=true;
		}
		i++;
	}
	return (this->statics.at(i-1));	
}


std::shared_ptr<Terrain> Game::search_especia_by_coordinate(int x, int y){
	unsigned int i;
	bool found=false;
	for (i=0; i<this->terrains.size(); ++i){
		if((this->terrains.at(i)->is_especia())&&(this->terrains.at(i)->is_in_click(x,y))){
			found=true;
			break;
		}
	}
	if(found){
		return this->terrains.at(i);
	} else {
		return NULL;
	}
}
	

std::shared_ptr<Moveable> Game::search_enemy_moveable_by_pos(int x, int y){
	std::shared_ptr<Moveable> m=NULL;
	for (unsigned int i=0; i<this->moveables.size(); ++i){
		if((this->moveables.at(i)->click_is_inside_moveable(x,y))&&(this->moveables.at(i)->get_team()!=this->my_id)){
			m=this->moveables.at(i);
			break;
		}
	}
	return m;
}

std::shared_ptr<Moveable> Game::search_my_moveable_by_pos(int x, int y){
	std::shared_ptr<Moveable> m=NULL;
	for (unsigned int i=0; i<this->moveables.size(); ++i){
		if((this->moveables.at(i)->click_is_inside_moveable(x,y))&&(this->moveables.at(i)->get_team()==this->my_id)){
			m=this->moveables.at(i);
			break;
		}
	}
	return m;
}

std::shared_ptr<Static> Game::search_enemy_static_by_pos(int x, int y){
	std::shared_ptr<Static> s=NULL;
	for (unsigned int i=0; i<this->statics.size(); ++i){
		if((this->statics.at(i)->click_is_inside_static(x,y))&&(this->statics.at(i)->mine()!=this->my_id)){
			s=this->statics.at(i);
			break;
		}
	}
	return s;
}


std::shared_ptr<Static> Game::search_my_static_by_pos(int x, int y){
	std::shared_ptr<Static> s=NULL;
	for (unsigned int i=0; i<this->statics.size(); ++i){
		if((this->statics.at(i)->click_is_inside_static(x,y))&&(this->statics.at(i)->mine()==this->my_id)){
			s=this->statics.at(i);
			break;
		}
	}
	return s;
}

std::shared_ptr<Button> Game::search_button_by_pos(int x, int y){
	std::shared_ptr<Button> b=NULL;
	for (unsigned int i=0; i<this->buttons.size(); ++i){
		if(this->buttons.at(i)->click_is_inside_button(x,y)){
			b=this->buttons.at(i);
			break;
		}
	}
	return b;
}


bool Game::destroy_moveable(int id){
	bool found=false;
	unsigned int i;
	for (i=0; i<this->moveables.size(); ++i){
		if(this->moveables.at(i)->get_id()==id){
			found=true;
			break;
		}
	}
	if(found){
		std::shared_ptr<Moveable> m=this->moveables.at(i);
		int size_moveable_x=m->h_size();
		int size_moveable_y=m->v_size();
		int x=m->x_pos();
		int y=m->y_pos();
		this->add_animation(52,size_moveable_x,size_moveable_y,x,y);
		this->moveables.erase(this->moveables.begin()+i);
		bool found_selected=false;
		unsigned int j;
		for (j=0; j < this->selected.size(); ++j){
			if(this->selected.at(j)->get_id()==id){
				found_selected=true;
				break;
			}
		}
		if(found_selected){
			this->selected.erase(this->selected.begin()+j);
		}
	}
	return found;
}


bool Game::destroy_static(int id){
	bool found=false;
	unsigned int i;
	for (i=0; i<this->statics.size(); ++i){
		if(this->statics.at(i)->get_id()==id){
			found=true;
			break;
		}
	}
	if(found){
		std::shared_ptr<Static> m=this->statics.at(i);
		int size_static_x=m->h_size();
		int size_static_y=m->v_size();
		int x=m->x_pos();
		int y=m->y_pos();
		this->add_animation(51,size_static_x,size_static_y,x,y);
		this->statics.erase(this->statics.begin()+i);
	}
	return found;
}


bool Game::destroy_terrain(int id){
	bool found=false;
	unsigned int i;
	for (i=0; i<this->terrains.size(); ++i){
		if(this->terrains.at(i)->get_id()==id){
			found=true;
			break;
		}
	}
	if(found){
		std::shared_ptr<Terrain> m=this->terrains.at(i);
		int size_static_x=m->h_size();
		int size_static_y=m->v_size();
		int x=m->x_pos();
		int y=m->y_pos();
		this->add_animation(53,size_static_x,size_static_y,x,y);
		this->terrains.erase(this->terrains.begin()+i);
	}
	return found;
}



void Game::destroy_unit(int id){
	bool is_moveable=this->destroy_moveable(id);
	if(!is_moveable){
		bool is_static=this->destroy_static(id);
		if(!is_static){
			this->destroy_terrain(id);
		}
	}
}


void Game::send_move(int x, int y){
	unsigned char mode='m';
	for (unsigned int i=0; i<this->selected.size(); ++i){
		if(this->selected.at(i)->is_cosechadora()){
			std::shared_ptr<Terrain> t=this->search_especia_by_coordinate(x,y);
			if (t!=NULL){
				mode='a';
				this->s->send_msj(&mode,1);
				this->s->send_int(this->selected.at(i)->get_id());
				this->s->send_int(t->get_id());
			} else{
				this->s->send_msj(&mode,1);
				this->s->send_int(this->selected.at(i)->get_id());
				this->s->send_int(x);
				this->s->send_int(y);
			}
		} else {
			this->s->send_msj(&mode,1);
			this->s->send_int(this->selected.at(i)->get_id());
			this->s->send_int(x);
			this->s->send_int(y);
		}
	}
}


void Game::send_attack(int id){
	unsigned char c='a';
	for (unsigned int i = 0; i < this->selected.size(); ++i){
		this->s->send_msj(&c,1);
		this->s->send_int(this->selected.at(i)->get_id());
		this->s->send_int(id);
	}
}


bool Game::check_if_is_something_mine(int x, int y){
	bool found=false;
	std::shared_ptr<Moveable> m=this->search_my_moveable_by_pos(x,y);
	if(m!=NULL){
		found=true;
	} else {
		std::shared_ptr<Static> s=this->search_my_static_by_pos(x,y);
		if (s!=NULL){
			found=true;
		}
	}
	return found;
}

void Game::right_click_selected(int x, int y){
	if(this->selected.size()<0){
		return;
	}
	std::shared_ptr<Moveable> m=this->search_enemy_moveable_by_pos(x,y);
	if(m!=NULL){
		this->send_attack(m->get_id());
	} else {
		std::shared_ptr<Static> s=this->search_enemy_static_by_pos(x,y);
		if(s!=NULL){
			this->send_attack(s->get_id());
		} else {
			bool is_something_mine=this->check_if_is_something_mine(x,y);
			if(!is_something_mine){
				this->send_move(x,y);
			}
		}
	}
}

void Game::selected_moveable(std::shared_ptr<Moveable> m){
	this->free_selected();
	this->selected.push_back(m);
}


void Game::selected_button(std::shared_ptr<Button> s){
	this->free_selected();
	this->button_selected.push_back(s);
}

	
std::shared_ptr<Button> Game::is_selected_unit_button(){
	std::shared_ptr<Button> b=NULL;
	for (unsigned int i=0; i<this->button_selected.size(); ++i){
		int id=this->button_selected.at(i)->get_id();
		if((id>=10)&&(id<=20)){
			b=this->button_selected.at(i);
			break;
		}
	}
	return b;
}


std::shared_ptr<Button> Game::is_selected_building_button(){
	std::shared_ptr<Button> b=NULL;
	for (unsigned int i=0; i<this->button_selected.size(); ++i){
		int id=this->button_selected.at(i)->get_id();
		if((id>=0)&&(id<=9)){
			b=this->button_selected.at(i);
			break;
		}
	}
	return b;
}


void Game::selected_static(std::shared_ptr<Static> s){
	std::shared_ptr<Button> b=this->is_selected_unit_button();
	if(b!=NULL){
		unsigned char c='u';
		this->s->send_msj(&c,1);
		this->s->send_int(b->get_id());
		this->s->send_int(s->get_id());
		this->s->send_int(this->my_id);
	}
	this->free_selected();
}

void Game::selected_nothing(int x, int y){
	std::shared_ptr<Button> b=this->is_selected_building_button();
	if(b!=NULL){
		unsigned char c='e';
		this->s->send_msj(&c,1);
		this->s->send_int(this->my_id);
		this->s->send_int(b->get_id());
		this->s->send_int(x);
		this->s->send_int(y);
	}
	this->free_selected();
}


void Game::clicked(int x, int y, bool is_right_click){
	if(is_right_click){
		this->right_click_selected(x,y);
	} else {
		std::shared_ptr<Moveable> m=this->search_my_moveable_by_pos(x,y);
		if(m!=NULL){
			this->selected_moveable(m);
		} else {
			std::shared_ptr<Static> s=this->search_my_static_by_pos(x,y);
			if(s!=NULL){
				this->selected_static(s);
			} else {
				std::shared_ptr<Button> b=this->search_button_by_pos(x,y);
				if(b!=NULL){
					this->selected_button(b);
				} else {
					this->selected_nothing(x,y);
				}
			}
		}
	}
}


void Game::clicked_zone(SDL_Rect pos){
   	this->free_selected();
	for (unsigned int i = 0; i < this->moveables.size(); ++i){
	if((this->moveables.at(i)->get_team()==this->my_id)){
			if(this->moveables.at(i)->is_in(pos)){
				this->selected.push_back(this->moveables.at(i));
			}
		}
	}
}


Game::~Game(){}



