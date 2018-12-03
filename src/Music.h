#include <SDL2/SDL_mixer.h>
#include <string>
#include <stdio.h>
#include <string>
#include "SDLerror.cpp"

class Music{
private:
	Mix_Music* m{NULL};
public:
	Music(std::string path);
	Mix_Music* get_music();
	~Music();
	
};