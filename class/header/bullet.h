#pragma once
#include "..\..\define\Define.h"
#include "maps.h"
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
	bool move(float time, maps level);
	void ttr();
};