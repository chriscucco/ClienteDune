#include "Vehicle.cpp"

class Cosechadora : public Vehicle{
public:
	Cosechadora(int id,int size_x, int size_y, int x, int y, int team,  std::vector<std::shared_ptr<Surface>> v);
	~Cosechadora();
};

