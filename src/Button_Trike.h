#include "Button.cpp"


class Button_Trike : public Button{
public:
	Button_Trike(int i,int size_x, int size_y,int x, int y, std::shared_ptr<Surface> s);
	~Button_Trike();
};

