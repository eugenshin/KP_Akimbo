#pragma once
#include "..\..\define\Define.h"
using namespace sf;
using namespace std;
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