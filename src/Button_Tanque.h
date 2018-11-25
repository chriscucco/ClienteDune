#include "Button.cpp"


class Button_Tanque : public Button{
public:
	Button_Tanque(int i,int size_x, int size_y, int x, int y, std::shared_ptr<Surface> s);
	~Button_Tanque();
	
};