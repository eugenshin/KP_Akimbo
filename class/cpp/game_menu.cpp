#pragma once
#include "..\..\define\Define.h"
using namespace sf;

game_menu::game_menu()
{
	rect.setSize(Vector2f(Width, Height));
	rect.setFillColor(Color(0,0,0,128));
	rect.setPosition(0, 0);
}

void game_menu::show(RenderWindow* wnd)
{
	wnd->draw(rect);
}
