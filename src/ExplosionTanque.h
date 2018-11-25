#include "Animation.cpp"


class ExplosionTanque : public Animation{

public:
	ExplosionTanque(int size_x, int size_y, int x, int y,std::vector<std::shared_ptr<Surface>> v);
	~ExplosionTanque();
};

