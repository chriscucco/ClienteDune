#include "Cycle.h"


Cycle::Cycle(Game *s, std::mutex *mut){
	this->game=s;
  this->m=mut;
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
  Lock l(*(this->m));
  this->game->add_terrain(recv_type,recv_id,size_x,size_y,x,y);  
}


void Cycle::gusano(){
  int recv_type=this->game->get_socket()->recv_int();
  int size_x=this->game->get_socket()->recv_int();
  int size_y=this->game->get_socket()->recv_int();
  int x=this->game->get_socket()->recv_int();
  int y=this->game->get_socket()->recv_int();
  Lock l(*(this->m));
  this->game->add_animation(recv_type,size_x,size_y,x,y);
}


void Cycle::attack(){
  int id=this->game->get_socket()->recv_int();
  int id_to_attack=this->game->get_socket()->recv_int();
  SDL_Rect* pos;
  Lock l(*(this->m));
  std::shared_ptr<Moveable> m=this->game->search_moveable_by_id(id_to_attack);
  if(m!=NULL){
    pos=m->getpos();
  } else{
    std::shared_ptr<Static> s=this->game->search_static_by_id(id_to_attack);
    pos=s->getpos();
  }
  this->game->search_moveable_by_id(id)->attack(pos->x,pos->y);
}


void Cycle::end(){
  int winner=this->game->get_socket()->recv_int();
  bool win=(winner==this->game->give_id());
  Lock l(*(this->m));
  this->game->finish_game(win);
}


void Cycle::destroy_unit(){
  int id=this->game->get_socket()->recv_int();
  Lock l(*(this->m));
  this->game->destroy_unit(id);
}


void Cycle::energy(){
  int new_energy=this->game->get_socket()->recv_int();
  Lock l(*(this->m));
  this->game->modify_energy(new_energy);
}


void Cycle::money(){
  int new_money=this->game->get_socket()->recv_int();
  Lock l(*(this->m));
  this->game->modify_money(new_money);
}


void Cycle::notice(){
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
	unsigned char c;
	while(this->game->get_socket()->recv_msj(&c,1)){
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
	        this->gusano();
        	break;
      	case 'a': 
	        this->attack();
        	break;
      	case 'e': 
	        this->end();
        	break;
      	case 'd': 
	        this->destroy_unit();
        	break;
      	case 'w': 
	        this->energy();
        	break;
      	case 'p': 
	        this->money();
        	break;
	    case 'r': 
        	this->notice();
        	break;
      case 'k':
        	this->change_moveable();
        	break;
      case 's':
          this->stop_attacking();
          break;
  		}
	}
}

