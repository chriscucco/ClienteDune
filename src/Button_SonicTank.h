#include "Button.cpp"


class Button_SonicTank : public Button{
public:
	Button_SonicTank(int i,int size_x, int size_y, int x, int y, std::shared_ptr<Surface> s);
	~Button_SonicTank();
};

