#include "Vehicle.cpp"

class Trike : public Vehicle{
public:
	Trike(int id,int size_x, int size_y, int x, int y, int team, std::vector<std::shared_ptr<Surface>> v);
	~Trike();
};

