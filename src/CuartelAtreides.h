#include "Static.cpp"
#include <memory>



class CuartelAtreides : public Static{
public:
	CuartelAtreides(int id,int size_x, int size_y, int x, int y, int team, std::shared_ptr<Surface> s);
	~CuartelAtreides();
	
};