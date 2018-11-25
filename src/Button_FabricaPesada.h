#include "Button.cpp"


class Button_FabricaPesada : public Button{
public:
	Button_FabricaPesada(int i,int size_x, int size_y,int x,int y,std::shared_ptr<Surface> s);
	~Button_FabricaPesada();
};

