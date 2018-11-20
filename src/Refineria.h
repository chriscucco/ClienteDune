#include "Static.cpp"
#include <memory>


class Refineria : public Static{
public:
	Refineria(int id,int size_x, int size_y, int x, int y, int team);
	~Refineria();
};