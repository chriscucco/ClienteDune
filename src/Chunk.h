#include <SDL2/SDL_mixer.h>
#include <string>
#include <stdio.h>
#include <string>
#include "SDLerror.cpp"

class Chunk{
private:
	Mix_Chunk* m{NULL};
public:
	Chunk(std::string path);
	Mix_Chunk* get_music();
	~Chunk();
	
};