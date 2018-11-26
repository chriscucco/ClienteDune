#include "Static.cpp"


class TrampaDeAire : public Static{
public:
	TrampaDeAire(int id,int size_x, int size_y, int x, int y, int team,std::shared_ptr<Surface> s);
	~TrampaDeAire();
};

