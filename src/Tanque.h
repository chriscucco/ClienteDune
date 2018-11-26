#include "Vehicle.cpp"

class Tanque : public Vehicle{
public:
	Tanque(int id,int size_x, int size_y, int x, int y, int team,std::vector<std::shared_ptr<Surface>> s);
	~Tanque();
};

