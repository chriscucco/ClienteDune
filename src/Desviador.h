#include "Vehicle.cpp"

class Desviador : public Vehicle{
public:
	Desviador(int id,int size_x, int size_y, int x, int y, int team,std::vector<std::shared_ptr<Surface>> v);
	~Desviador();
};

