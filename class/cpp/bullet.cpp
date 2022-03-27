#pragma once
#include "..\..\define\Define.h"

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

bool bullet::move(float time, maps level)
{
	s.move(spdx * time, spdy * time);
	float x = s.getPosition().x,
		y = s.getPosition().y;
	if ((x + BS > Width) || (x < 0) || (y + BS > Height) || (y < 0)) {
		return 1;//столкновение снарядов со стеной
	}
	if ((level.getTile((int)(x / TS), (int)(y / TS)) == '1') || (level.getTile((int)((x + BS - 1) / TS), (int)(y / TS)) == '1') || (level.getTile((int)((x + BS - 1) / TS), (int)((y + BS - 1) / TS)) == '1') || (level.getTile((int)(x / TS), (int)((y + BS - 1) / TS)) == '1')) {
		return 1;//столкновение снарядов с объектами на карте
	}
	return 0;
}

void bullet::ttr()
{
	s.setTexture(t);
}