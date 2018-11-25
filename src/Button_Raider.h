#include "Button.cpp"



class Button_Raider : public Button{
public:
	Button_Raider(int i,int size_x, int size_y, int x, int y, std::shared_ptr<Surface> s);
	~Button_Raider();
};

