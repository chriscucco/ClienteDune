#include "Warrior.cpp"

class InfanteriaPesada : public Warrior{
public:
	InfanteriaPesada(int id,int size_x, int size_y, int x, int y, int team,std::vector<std::shared_ptr<Surface>> v1,std::vector<std::shared_ptr<Surface>> v2);
	~InfanteriaPesada();
};

