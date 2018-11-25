#include "Button.cpp"


class Button_FabricaLigera : public Button{
public:
	Button_FabricaLigera(int i,int size_x, int size_y,int x,int y, std::shared_ptr<Surface> s);
	~Button_FabricaLigera();
	
};