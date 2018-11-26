#include "Vehicle.cpp"

class Raider : public Vehicle{
public:
	Raider(int id,int size_x, int size_y, int x, int y, int team,std::vector<std::shared_ptr<Surface>> s);
	~Raider();
};

