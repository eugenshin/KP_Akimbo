#pragma once
#include "..\..\define\Define.h"
class bullet:public object
{
	static constexpr int DBS = 16,//default bullet size
		DBD = 5;//default bullet damage
	float spdx, spdy;//speed x, y
	int dmg,//damage
		bs;//bullet size
public:
	bullet(int x, int y, float dx, float dy, int skill3, int skill4);
	Vector2f getPos();
	void draw(RenderWindow& wnd) override;
	bool move(float time, maps level);//движение снаряда
	int getdmg();
	int getbs();
	static int getDBS();
};