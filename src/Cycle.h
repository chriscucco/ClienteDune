#ifndef CYCLE_H_
#define CYCLE_H_

#include "Thread.cpp"
#include "Lock.cpp"
#include "Game.cpp"
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
	
public:
    Cycle(Game* game, std::mutex *mut);
    void move();
	void create();
	void terrain();
	void gusano();
	void attack();
	void end();
	void destroy_unit();
	void energy();
	void money();
	void notice();
	void change_moveable();
	void stop_attacking();
    virtual void run() override;
};


#endif /* CYCLE_H_ */

