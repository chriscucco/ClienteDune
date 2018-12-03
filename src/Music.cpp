#ifndef MUSIC_CPP_
#define MUSIC_CPP_

#include "Music.h"


Music::Music(std::string path){
	this->m= Mix_LoadMUS(path.c_str());
	if(m== NULL){
		throw SDLerror();
	}
}

Mix_Music* Music::get_music(){
	return this->m;
}


Music::~Music(){
	Mix_FreeMusic(this->m);
	this->m=NULL;
}


#endif