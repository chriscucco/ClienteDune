
#include "Moveable.cpp"

class Vehicle : public Moveable{
protected:
	bool cosechadora;
public:
	Vehicle(){}
	Vehicle(int id,int size_x, int size_y, int x, int y, int team){}
	virtual void modify_pos(int x, int y) override;
	virtual bool is_cosechadora() override;
	~Vehicle(){}
};

