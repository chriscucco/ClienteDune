#include "Animation.cpp"


class Gusano : public Animation{

public:
	Gusano(int size_x, int size_y, int x, int y,std::vector<std::shared_ptr<Surface>> s);
	~Gusano();
};

