#include "Button.cpp"


class Button_Silo : public Button{
public:
	Button_Silo(int i,int size_x, int size_y, int x, int y, std::shared_ptr<Surface> s);
	~Button_Silo();
	
};