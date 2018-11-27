#include "Button.cpp"


class Button_Money : public Button{
public:
	Button_Money(int i,int size_x, int size_y,int x, int y, std::shared_ptr<Surface> s);
	~Button_Money();
	
};