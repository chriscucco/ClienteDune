#include "Warrior.cpp"

class Sardaukar : public Warrior{
public:
	Sardaukar(int id,int size_x, int size_y, int x, int y, int team,std::vector<std::shared_ptr<Surface>> v1,std::vector<std::shared_ptr<Surface>> v2);
	~Sardaukar();
};

