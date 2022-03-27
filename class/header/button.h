#pragma once
#include "..\..\define\Define.h"
class button
{
	RectangleShape box;
	Texture t;
	Sprite s;
	Font font;
	Text text;
public:
	button();
	void shape(int x, int y, int w, int h, Color bc, int tx, int ty, string str, int size, Color tc);
	void shape(int x, int y, int w, int h, string path, int tx, int ty, string str, int size, Color tc);
	void draw(RenderWindow* wnd);
	Sprite getSprite();
	void change_text(string str);
};