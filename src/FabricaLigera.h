#include "Static.cpp"
#include <memory>



class FabricaLigera : public Static{
public:
	FabricaLigera(int id,int size_x, int size_y, int x, int y, int team, std::shared_ptr<Surface> s);
	~FabricaLigera();
};

