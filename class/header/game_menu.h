#pragma once
#include "..\..\define\Define.h"
class game_menu
{
	RectangleShape rect;
	button menu, skills, skill1, skill2;
public:
	game_menu();
	bool mp(RenderWindow* wnd, int* sp);//mouse pressed
	void show(RenderWindow* wnd, int *sp);
};