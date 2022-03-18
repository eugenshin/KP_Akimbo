#pragma once
#include "..\..\define\Define.h"
using namespace sf;
class hero
{
	float as = 1;
	int hp = 3;
	float const ms = 0.00005;
	Texture t;
	Sprite s;
public:
	hero(int x, int y);
	void setpos(int x, int y);
	Sprite getS();
	void move(float time);
	float getAS();
};