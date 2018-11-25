#include "Button.cpp"


class Button_InfanteriaPesada : public Button{
public:
	Button_InfanteriaPesada(int i,int size_x, int size_y,int x,int y, std::shared_ptr<Surface> s);
	~Button_InfanteriaPesada();
};
