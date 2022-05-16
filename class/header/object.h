#pragma once
#include "..\..\define\Define.h"
class object
{
protected:
	Texture t;
	Sprite s;
public:
	virtual void draw(RenderWindow& wnd) = 0;//отрисовать
};