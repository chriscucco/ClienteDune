#ifndef ENDOFGAME_CPP_
#define ENDOFGAME_CPP_
#include "EndOfGame.h"


EndOfGame::EndOfGame(){
	this->t="Fin del juego";
}


std::string EndOfGame::what(){
	return this->t;
}


EndOfGame::~EndOfGame(){}


#endif /* EndOfGame_CPP_ */
