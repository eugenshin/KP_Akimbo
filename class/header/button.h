#pragma once
#include "..\..\define\Define.h"
class button:public object
{
	RectangleShape box;
	Font font;
	Text text;
public:
	button();
	void shape(int x, int y, int w, int h, Color bc, int tx, int ty, string str, int size, Color tc);
	void shape(int x, int y, int w, int h, string path, int tx, int ty, string str, int size, Color tc);
	void draw(RenderWindow& wnd) override;
	void change_text(string str);
	void move(int dx, int dy);
	bool press(int x, int y);
};