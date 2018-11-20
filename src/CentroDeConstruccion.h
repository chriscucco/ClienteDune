#include "Static.cpp"
#include <memory>



class CentroDeConstruccion : public Static{
public:
	CentroDeConstruccion(int id,int size_x, int size_y, int x, int y, int team);
	~CentroDeConstruccion();
};