#include "Animation.cpp"


class ExplosionFuerte : public Animation{
public:
	ExplosionFuerte(int size_x, int size_y, int x, int y,std::vector<std::shared_ptr<Surface>> v);
	~ExplosionFuerte();
};

