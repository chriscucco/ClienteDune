#ifndef SDLERROR_CPP_
#define SDLERROR_CPP_
#include "SDLerror.h"


SDLerror::SDLerror(){
	this->t="Error en la creación de objeto SDL";
}


std::string SDLerror::what(){
	return this->t;
}


SDLerror::~SDLerror(){}


#endif /* SDLERROR_CPP_ */
