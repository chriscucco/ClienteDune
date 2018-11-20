#include <string>

//Excepcion que se lanza cuando hay un problema de conexión en la creación 
//de los sockets, tanto cliente como servidor.
class SocketParameterError : public std::exception{
private:
	std::string t;

public:
	SocketParameterError();
	std::string what();
	~SocketParameterError();
};

