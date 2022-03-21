#pragma once
#include "..\..\define\Define.h"
using namespace sf;

bullet::bullet(int x, int y, float dx, float dy)
{
	spdx = dx;
	spdy = dy;
	t.loadFromFile(BULLETFILE);
	s.setScale(2, 2);
	s.setPosition(x, y);
}

void bullet::setpos(int x, int y)
{
	s.setPosition(x, y);
}

Sprite bullet::getS()
{
	return s;
}

void bullet::move(float time)
{
	s.move(spdx * time, spdy * time);
}

void bullet::ttr()
{
	s.setTexture(t);
}