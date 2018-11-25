#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "Surface.cpp"


class MasterSurface{
private:
	std::vector<std::shared_ptr<Surface>> trike;
public:
	MasterSurface();
	void init_trike();
	std::vector<std::shared_ptr<Surface>> get_trike_surface();
	~MasterSurface();
	
};