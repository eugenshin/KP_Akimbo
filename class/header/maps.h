#pragma once
#include "..\..\define\Define.h"
class maps
{
	static const int N = 15;
	String map[N];
	Texture t;
	Sprite s;
public:
	void draw(RenderWindow* wnd);
	char getTile(int i, int j);
	void lvl1();
};