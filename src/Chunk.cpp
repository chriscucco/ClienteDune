#ifndef CHUNK_CPP_
#define CHUNK_CPP_

#include "Chunk.h"


Chunk::Chunk(std::string path){
	this->m=Mix_LoadWAV( path.c_str());
	if(m== NULL){
		throw SDLerror();
	}
}

Mix_Chunk* Chunk::get_music(){
	return this->m;
}


Chunk::~Chunk(){
	Mix_FreeChunk(this->m);
	this->m=NULL;
}


#endif