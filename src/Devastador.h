#include "Vehicle.cpp"


class Devastador : public Vehicle{
public:
	Devastador(int id,int size_x, int size_y, int x, int y, int team,std::vector<std::shared_ptr<Surface>> v);
	~Devastador();
};

