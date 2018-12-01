#include <string>


class EndOfGame : public std::exception{
private:
	std::string t;
public:
	EndOfGame();
	std::string what();
	~EndOfGame();
};
