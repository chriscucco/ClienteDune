#include "Button.cpp"


class Button_CentroDeConstruccion : public Button{
public:
	Button_CentroDeConstruccion(int i,int size_x, int size_y,int x, int y, std::shared_ptr<Surface> s);
	~Button_CentroDeConstruccion();
};