#pragma once
#include "..\..\define\Define.h"
using namespace sf;
class bullet
{
	float spdx, spdy;
	int dmg = 1;
	Texture t;
	Sprite s;
public:
	bullet(int x, int y, float dx, float dy);
	void setpos(int x, int y);
	Sprite getS();
	void move(float time);
	void ttr();
};