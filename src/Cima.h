#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "Surface.cpp"
#include "Terrain.cpp"

class Cima : public Terrain{
public:
	Cima(int id,int size_x, int size_y, int x, int y);
	~Cima();
};