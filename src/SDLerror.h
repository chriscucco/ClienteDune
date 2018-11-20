#include <string>


class SDLerror : public std::exception{
private:
	std::string t;
public:
	SDLerror();
	std::string what();
	~SDLerror();
};
