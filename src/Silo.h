#include "Static.cpp"

class Silo : public Static{
public:
	Silo(int id,int size_x, int size_y, int x, int y, int team,std::shared_ptr<Surface> s);
	~Silo();	
};

