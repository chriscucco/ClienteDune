#include "Moveable.cpp"

class Warrior : public Moveable{
protected:
	bool is_attacking;
	std::vector<std::shared_ptr<Surface>> attack_surfaces;
	int iterator{0};
	int let_pass{3};
	int last_surface{0};
public:
	Warrior(){}
	Warrior(int id,int size_x, int size_y, int x, int y, int team){}
	virtual void modify_pos(int x, int y) override;
	virtual SDL_Surface* getsurf() override;
	virtual void attack(int x,int y) override;
	virtual void stop_attack();
	~Warrior(){}
};

