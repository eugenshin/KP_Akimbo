#pragma once
#include "..\..\define\Define.h"
class game_menu
{
	RectangleShape rect;
	button menu, skills, skill1, skill2, skill3, skill4, cont, restart, exit;
public:
	game_menu();
	bool smp(RenderWindow& wnd, hero& hero);//skill mouse pressed
	bool mmp(RenderWindow& wnd, int n);//menu mouse pressed
	void show(RenderWindow& wnd, hero& hero);//отобразить
};