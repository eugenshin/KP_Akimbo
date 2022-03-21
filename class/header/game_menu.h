#pragma once
#include "..\..\define\Define.h"
using namespace sf;
class game_menu
{
	RectangleShape rect;
	Sprite s;
	Event event;
public:
	game_menu();
	void show(RenderWindow* wnd);
};