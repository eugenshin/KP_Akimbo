#pragma once
#include "..\..\define\Define.h"
using namespace sf;
class hero
{
	const float DAT = 800,//default attack time
		DBS = 0.0001,//default bullet speed
		DMS = 0.00005,//default move speed
		DHP = 3,//default health points
		SS[2] = { 32, 32 };//Sprite Size
	float at = DAT,//attack time
		bs = DBS,//bullet speed
		ms = DMS,//move speed
		hp = DHP;//health points
	Texture t;
	Sprite s;
public:
	hero(int x, int y);
	void setpos(int x, int y);
	Sprite getS();
	void move(float time, int w, int h);
	float getAT();
	float getBS();
	void onmaptest(int h, int w);
};