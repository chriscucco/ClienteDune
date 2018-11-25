#include "Static.cpp"
#include <memory>



class CuartelHarkonnen : public Static{
public:
	CuartelHarkonnen(int id,int size_x, int size_y, int x, int y, int team, std::shared_ptr<Surface> s);
	~CuartelHarkonnen();
};