#include "Warrior.cpp"

class Fremen : public Warrior{
public:
	Fremen(int id,int size_x, int size_y, int x, int y, int team, std::vector<std::shared_ptr<Surface>> v1, std::vector<std::shared_ptr<Surface>> v2);
	~Fremen();
};

