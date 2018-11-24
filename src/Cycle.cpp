#include "Cycle.h"


Cycle::Cycle(Game *s, std::mutex *mut){
	this->game=s;
  this->m=mut;
}


void Cycle::run(){
	unsigned char c;
   	while(this->game->get_socket()->recv_msj(&c,1)){
   		if(c=='m'){
			  int id=this->game->get_socket()->recv_int();
    	  int x=this->game->get_socket()->recv_int();
    	  int y=this->game->get_socket()->recv_int();
        Lock l(*(this->m));
    		this->game->search_moveable_by_id(id)->modify_pos(x,y);
    	}else if(c=='c'){
        int recv_type=this->game->get_socket()->recv_int();
        int recv_id=this->game->get_socket()->recv_int();
        int size_x=this->game->get_socket()->recv_int();
        int size_y=this->game->get_socket()->recv_int();
        int x=this->game->get_socket()->recv_int();
        int y=this->game->get_socket()->recv_int();
        int team=this->game->get_socket()->recv_int();
        Lock l(*(this->m));
        this->game->add(recv_type,recv_id,size_x,size_y,x,y,team);
      }else if(c=='t'){
        int recv_type=this->game->get_socket()->recv_int();
        int recv_id=this->game->get_socket()->recv_int();
        int size_x=this->game->get_socket()->recv_int();
        int size_y=this->game->get_socket()->recv_int();
        int x=this->game->get_socket()->recv_int();
        int y=this->game->get_socket()->recv_int();
        Lock l(*(this->m));
        this->game->add_terrain(recv_type,recv_id,size_x,size_y,x,y);
      }else if(c=='g'){
        int recv_type=this->game->get_socket()->recv_int();
        int size_x=this->game->get_socket()->recv_int();
        int size_y=this->game->get_socket()->recv_int();
        int x=this->game->get_socket()->recv_int();
        int y=this->game->get_socket()->recv_int();
        Lock l(*(this->m));
        this->game->add_animation(recv_type,size_x,size_y,x,y);
      }else if(c=='a'){
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
      }else if(c=='e'){
        int winner=this->game->get_socket()->recv_int();
        bool win=(winner==this->game->give_id());
        Lock l(*(this->m));
        this->game->finish_game(win);
      }else if(c=='d'){
        int id=this->game->get_socket()->recv_int();
        Lock l(*(this->m));
        this->game->destroy_unit(id);
      } else if(c=='o'){
        int new_energy=this->game->get_socket()->recv_int();
        Lock l(*(this->m));
        this->game->modify_energy(new_energy);
      } else if(c=='p'){
        int new_money=this->game->get_socket()->recv_int();
        Lock l(*(this->m));
        this->game->modify_money(new_money);
      }
	}
}

