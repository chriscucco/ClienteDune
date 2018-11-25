#include "Animation.cpp"


class ExplosionPersonaje : public Animation{
public:
	ExplosionPersonaje(int size_x, int size_y, int x, int y,std::vector<std::shared_ptr<Surface>> v);
	~ExplosionPersonaje();
};

