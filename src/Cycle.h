#ifndef CYCLE_H_
#define CYCLE_H_

#include "Thread.cpp"
#include "Lock.cpp"
#include "Game.cpp"
#include "Chunk.cpp"
#include "Music.cpp"
#include <memory>
#include <mutex>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//Ciclo que acepta clientes a medida que van llegando, por cada uno que 
//acepta lanza un hilo, corta su ejecución lanzando la excepción EndOfCycle
class Cycle : public Thread { 
private:
	Game *game;
	std::mutex *m;
	bool* b;
	
public:
    Cycle(Game* game, std::mutex *mut, bool* running);
    void move();
	void create();
	void terrain();
	void gusano(Mix_Chunk* music);
	void attack(Mix_Chunk* m);
	void end();
	void destroy_unit(Mix_Chunk* m);
	void energy();
	void money(Mix_Chunk* m);
	void notice(Mix_Chunk* m);
	void change_moveable();
	void stop_attacking();
    virtual void run() override;
};


#endif /* CYCLE_H_ */

