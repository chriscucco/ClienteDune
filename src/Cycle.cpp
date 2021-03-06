#include "Cycle.h"


Cycle::Cycle(Game *s, std::mutex *mut, bool* running){
	this->game=s;
  this->m=mut;
  this->b=running;
}


void Cycle::move(){
  int id=this->game->get_socket()->recv_int();
  int x=this->game->get_socket()->recv_int();
  int y=this->game->get_socket()->recv_int();
  Lock l(*(this->m));
  this->game->search_moveable_by_id(id)->modify_pos(x,y);
}


void Cycle::create(){
  int recv_type=this->game->get_socket()->recv_int();
  int recv_id=this->game->get_socket()->recv_int();
  int size_x=this->game->get_socket()->recv_int();
  int size_y=this->game->get_socket()->recv_int();
  int x=this->game->get_socket()->recv_int();
  int y=this->game->get_socket()->recv_int();
  int team=this->game->get_socket()->recv_int();
  x-=size_x/2;
  y-=size_y/2;
  Lock l(*(this->m));
  this->game->add(recv_type,recv_id,size_x,size_y,x,y,team);
}


void Cycle::terrain(){
  int recv_type=this->game->get_socket()->recv_int();
  int recv_id=this->game->get_socket()->recv_int();
  int size_x=this->game->get_socket()->recv_int();
  int size_y=this->game->get_socket()->recv_int();
  int x=this->game->get_socket()->recv_int();
  int y=this->game->get_socket()->recv_int();
  x-=size_x/2;
  y-=size_y/2;
  Lock l(*(this->m));
  this->game->add_terrain(recv_type,recv_id,size_x,size_y,x,y);  
}


void Cycle::gusano(Mix_Chunk* music){
  Mix_PlayChannel( -1, music, 0 );
  int recv_type=this->game->get_socket()->recv_int();
  int size_x=this->game->get_socket()->recv_int();
  int size_y=this->game->get_socket()->recv_int();
  int x=this->game->get_socket()->recv_int();
  int y=this->game->get_socket()->recv_int();
  x-=size_x/2;
  y-=size_y/2;
  Lock l(*(this->m));
  this->game->add_animation(recv_type,size_x,size_y,x,y);
}


void Cycle::attack(Mix_Chunk* music){
  Mix_PlayChannel( -1, music, 0 );
  int id=this->game->get_socket()->recv_int();
  int id_to_attack=this->game->get_socket()->recv_int();
  SDL_Rect positions;
  Lock l(*(this->m));
  std::shared_ptr<Moveable> enemy=this->game->search_moveable_by_id(id_to_attack);
  if(enemy!=NULL){
    positions.x=enemy->x_pos();
    positions.y=enemy->y_pos();
    positions.w=enemy->h_size();
    positions.h=enemy->v_size();
  } else{
    std::shared_ptr<Static> enemy=this->game->search_static_by_id(id_to_attack);
    positions.x=enemy->x_pos();
    positions.y=enemy->y_pos();
    positions.w=enemy->h_size();
    positions.h=enemy->v_size();
  }
  this->game->search_moveable_by_id(id)->attack(positions.x,positions.y);
}


void Cycle::end(){
  int winner=this->game->get_socket()->recv_int();
  bool win=(winner==this->game->give_id());
  unsigned char ese='s';
  this->game->get_socket()->send_msj(&ese,1);
  this->game->get_socket()->send_int(this->game->give_id());
  Lock l(*(this->m));
  this->game->finish_game(win);
}


void Cycle::destroy_unit(Mix_Chunk* m){
  Mix_PlayChannel( -1, m, 0 );
  int id=this->game->get_socket()->recv_int();
  Lock l(*(this->m));
  this->game->destroy_unit(id);
}


void Cycle::energy(){
  int new_energy=this->game->get_socket()->recv_int();
  Lock l(*(this->m));
  this->game->modify_energy(new_energy);
}


void Cycle::money(Mix_Chunk* m){
  Mix_PlayChannel( -1, m, 0 );
  int new_money=this->game->get_socket()->recv_int();
  Lock l(*(this->m));
  this->game->modify_money(new_money);
}


void Cycle::notice(Mix_Chunk* m){
  Mix_PlayChannel( -1, m, 0 );
  int type=this->game->get_socket()->recv_int();
  Lock l(*(this->m));
  this->game->add_notice(type);
}


void Cycle::change_moveable(){
  int id=this->game->get_socket()->recv_int();
  int type_id=this->game->get_socket()->recv_int();
  int new_team=this->game->get_socket()->recv_int();
  Lock l(*(this->m));
  this->game->change_moveable_team(id,type_id,new_team);
}

void Cycle::stop_attacking(){
  int id=this->game->get_socket()->recv_int();
  this->game->stop_attack(id);
}


void Cycle::run(){
try{
  Chunk atack("music/atack.wav");
  Chunk explote("music/explote.wav");
  Chunk money("music/money.wav");
  Chunk reject("music/reject.wav");
  Chunk gusano("music/gusano.wav");
	unsigned char c;
  int recv;
	while(1){
    recv=this->game->get_socket()->recv_msj(&c,1);
    if(recv==0){
      throw EndOfGame();
    }
    switch(c){
    	  case 'm': 
	        this->move();
        	break;
      	case 'c': 
	        this->create();
        	break;
      	case 't': 
	        this->terrain();
        	break;
      	case 'g': 
	        this->gusano(gusano.get_music());
        	break;
      	case 'a': 
	        this->attack(atack.get_music());
        	break;
      	case 'e': 
	        this->end();
        	break;
      	case 'd': 
	        this->destroy_unit(explote.get_music());
        	break;
      	case 'w': 
	        this->energy();
        	break;
      	case 'p': 
	        this->money(money.get_music());
        	break;
	    case 'r': 
        	this->notice(reject.get_music());
        	break;
      case 'k':
        	this->change_moveable();
        	break;
      case 's':
          this->stop_attacking();
          break;
  		}
	}
} catch (EndOfGame& error){
  std::cerr<<error.what()<<std::endl;
  (*(this->b))=false;
}
}

