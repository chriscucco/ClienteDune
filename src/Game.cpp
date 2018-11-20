#include "Game.h"

void Game::init_buttons(){
	std::shared_ptr<Button> b1(new Button_CentroDeConstruccion(60,this->button_size_x,this->button_size_y,500,0));
	std::shared_ptr<Button> b2(new Button_CuartelAtreides(61,this->button_size_x,this->button_size_y,550,0));
	std::shared_ptr<Button> b3(new Button_CuartelHarkonnen(62,this->button_size_x,this->button_size_y,600,0));
	std::shared_ptr<Button> b4(new Button_CuartelOrdos(63,this->button_size_x,this->button_size_y,650,0));
	std::shared_ptr<Button> b5(new Button_FabricaLigera(64,this->button_size_x,this->button_size_y,700,0));
	std::shared_ptr<Button> b6(new Button_FabricaPesada(65,this->button_size_x,this->button_size_y,750,0));
	std::shared_ptr<Button> b7(new Button_Palacio(66,this->button_size_x,this->button_size_y,800,0));
	std::shared_ptr<Button> b8(new Button_Refineria(67,this->button_size_x,this->button_size_y,850,0));
	std::shared_ptr<Button> b9(new Button_Silo(68,this->button_size_x,this->button_size_y,900,0));
	std::shared_ptr<Button> b10(new Button_TrampaDeAire(69,this->button_size_x,this->button_size_y,950,0));
	std::shared_ptr<Button> b11(new Button_Cosechadora(70,this->button_size_x,this->button_size_y,1315,100));
	std::shared_ptr<Button> b12(new Button_Desviador(71,this->button_size_x,this->button_size_y,1315,150));
	std::shared_ptr<Button> b13(new Button_Devastador(72,this->button_size_x,this->button_size_y,1315,200));
	std::shared_ptr<Button> b14(new Button_Raider(73,this->button_size_x,this->button_size_y,1315,250));
	std::shared_ptr<Button> b15(new Button_SonicTank(74,this->button_size_x,this->button_size_y,1315,300));
	std::shared_ptr<Button> b16(new Button_Tanque(75,this->button_size_x,this->button_size_y,1315,350));
	std::shared_ptr<Button> b17(new Button_Trike(76,this->button_size_x,this->button_size_y,1315,400));
	std::shared_ptr<Button> b18(new Button_Fremen(77,this->button_size_x,this->button_size_y,1315,450));
	std::shared_ptr<Button> b19(new Button_InfanteriaLigera(78,this->button_size_x,this->button_size_y,1315,500));
	std::shared_ptr<Button> b20(new Button_InfanteriaPesada(79,this->button_size_x,this->button_size_y,1315,550));
	std::shared_ptr<Button> b21(new Button_Sardaukar(80,this->button_size_x,this->button_size_y,1315,600));
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
}


void Game::add_centrodeconstruccion(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Static> d(new CentroDeConstruccion(id,size_x,size_y,x,y,team));
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
	std::shared_ptr<Static> d(new CuartelAtreides(id,size_x,size_y,x,y,team));
	this->statics.push_back(d);
}

	
void Game::add_cuartelharkonnen(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Static> d(new CuartelHarkonnen(id,size_x,size_y,x,y,team));
	this->statics.push_back(d);
}

	
void Game::add_cuartelordos(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Static> d(new CuartelOrdos(id,size_x,size_y,x,y,team));
	this->statics.push_back(d);
}

	
void Game::add_palacio(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Static> d(new Palacio(id,size_x,size_y,x,y,team));
	this->statics.push_back(d);
}

void Game::add_desviador(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Moveable> m(new Desviador(id,size_x,size_y,x,y,team));
	this->moveables.push_back(m);
}

void Game::add_devastador(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Moveable> m(new Devastador(id,size_x,size_y,x,y,team));
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
	std::shared_ptr<Moveable> m(new Cosechadora(id,size_x,size_y,x,y,team));
	this->moveables.push_back(m);
}


void Game::add_tanque(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Moveable> m(new Tanque(id,size_x,size_y,x,y,team));
	this->moveables.push_back(m);
}

void Game::add_trike(int id,int size_x, int size_y, int x, int y, int team){
	std::shared_ptr<Moveable> m(new Trike(id,size_x,size_y,x,y,team));
	this->moveables.push_back(m);
}

void Game::add_duna(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Terrain> m(new Duna(id,size_x,size_y,x,y));
	this->terrains.push_back(m);
}

void Game::add_cima(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Terrain> m(new Cima(id,size_x,size_y,x,y));
	this->terrains.push_back(m);
}

void Game::add_especiafuerte(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Terrain> m(new EspeciaFuerte(id,size_x,size_y,x,y));
	this->terrains.push_back(m);
}


void Game::add_especiasuave(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Terrain> m(new EspeciaSuave(id,size_x,size_y,x,y));
	this->terrains.push_back(m);
}


void Game::add_precipicio(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Terrain> m(new Precipicio(id,size_x,size_y,x,y));
	this->terrains.push_back(m);
}


void Game::add_roca(int id,int size_x, int size_y, int x, int y){
	std::shared_ptr<Terrain> m(new Roca(id,size_x,size_y,x,y));
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
		case 0: 	//CICLO DE RECIBIR LOS DATOS POR SOCKET Y GUARDAR
			this->add_centrodeconstruccion(id,size_x,size_y,x,y,team);
			break;
		case 1:
			this->add_tomadeaire(id,size_x,size_y,x,y,team);
			break;
		case 2:
			this->add_refineria(id,size_x,size_y,x,y,team);
			break;
		case 3:
			this->add_silo(id,size_x,size_y,x,y,team);
			break;
		case 4:
			this->add_fabricaligera(id,size_x,size_y,x,y,team);
			break;
		case 5:
			this->add_febricapesada(id,size_x,size_y,x,y,team);
			break;
		case 6:
			this->add_cuartelatreides(id,size_x,size_y,x,y,team);
			break;
		case 7:
			this->add_cuartelharkonnen(id,size_x,size_y,x,y,team);
			break;
		case 8:
			this->add_cuartelordos(id,size_x,size_y,x,y,team);
			break;
		case 9:
			this->add_palacio(id,size_x,size_y,x,y,team);
			break;
	}	
}

void Game::add_terrain(int type,int id, int size_x, int size_y, int x, int y){
	switch(type){
		case 30:
			this->add_roca(id,size_x,size_y,x,y);
			break;
		case 31:
			this->add_duna(id,size_x,size_y,x,y);
			break;
		case 32:
			this->add_especiafuerte(id,size_x,size_y,x,y);
			break;
		case 33:
			this->add_especiasuave(id,size_x,size_y,x,y);
			break;
		case 34:
			this->add_cima(id,size_x,size_y,x,y);
			break;
		case 35:
			this->add_precipicio(id,size_x,size_y,x,y);
			break;
	}
}

void Game::add_gusano(int size_x, int size_y,int x,int y){
	std::shared_ptr<Animation> a(new Gusano(size_x,size_x,x,y));
	this->animated.push_back(a);
}


void Game::add_big_explosion(int size_x, int size_y,int x,int y){
	std::shared_ptr<Animation> a(new ExplosionFuerte(size_x,size_x,x,y));
	this->animated.push_back(a);
}


void Game::add_tank_explosion(int size_x, int size_y,int x,int y){
	std::shared_ptr<Animation> a(new ExplosionTanque(size_x,size_x,x,y));
	this->animated.push_back(a);
}

void Game::add_moveable_explosion(int size_x, int size_y,int x,int y){
	std::shared_ptr<Animation> a(new ExplosionPersonaje(size_x,size_x,x,y));
	this->animated.push_back(a);
}


void Game::add_animation(int type,int size_x, int size_y,int x,int y){
	switch(type){
		case 50:
			this->add_gusano(size_x,size_y,x,y);
			break;
		case 51:
			this->add_big_explosion(size_x,size_y,x,y);
			break;
		case 52:
			this->add_tank_explosion(size_x,size_y,x,y);
			break;
		case 53:
			this->add_moveable_explosion(size_x,size_y,x,y);
			break;
	}
}


void Game::add_moveable(int type,int id,int size_x, int size_y, int x, int y,int team){
	switch (type){
		case 10:
			this->add_infanterialigera(id,size_x,size_y,x,y,team);
			break;
		case 11:
			this->add_infanteriapesada(id,size_x,size_y,x,y,team);
			break;
		case 12:
			this->add_fremen(id,size_x,size_y,x,y,team);
			break;
		case 13:
			this->add_sardaukar(id,size_x,size_y,x,y,team);
			break;
		case 14:
			this->add_trike(id,size_x,size_y,x,y,team);
			break;
		case 15:
			this->add_raider(id,size_x,size_y,x,y,team);
			break;
		case 16:
			this->add_tanque(id,size_x,size_y,x,y,team);
			break;
		case 17:
			this->add_sonictank(id,size_x,size_y,x,y,team);
			break;
		case 18:
			this->add_desviador(id,size_x,size_y,x,y,team);
			break;
		case 19:
			this->add_devastador(id,size_x,size_y,x,y,team);
			break;
		case 20:
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

void Game::copybuttons(){
	unsigned int i=0;
	while(i<this->buttons.size()){
		Texture t(this->renderer, this->buttons.at(i)->getsurf());
		SDL_RenderCopy(this->renderer, t.get_texture(), NULL, this->buttons.at(i)->getpos());
		i++;
	}	
}

	
void Game::refreshscreen(){
	SDL_RenderClear(this->renderer);
	SDL_RenderCopy(this->renderer, this->background, NULL, NULL);
	copybuttons();
	copyterrain();
	copystatics();
	copymoveables();
	copyanimated();
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
		if((id>=70)&&(id<=80)){
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
		if((id>=60)&&(id<=69)){
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
		this->s->send_int(b->get_id()-60);
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



