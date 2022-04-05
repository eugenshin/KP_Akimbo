#pragma once
#include "..\..\define\Define.h"
class maps:public object
{
	String map[N];
	vector<vector<int>> sp;//spawn place. доступные места для появления противника
	Texture t1;
	Sprite s1;
	void testsp();//вычисляет на карте подходящие места для появления противника
public:
	void draw(RenderWindow& wnd) override;
	char getTile(int i, int j);
	void lvl1();
	vector<vector<int>> getSP();
};