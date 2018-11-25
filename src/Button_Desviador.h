#include "Button.cpp"



class Button_Desviador : public Button{
public:
	Button_Desviador(int i,int size_x, int size_y,int x, int y,std::shared_ptr<Surface> s);
	~Button_Desviador();
};

