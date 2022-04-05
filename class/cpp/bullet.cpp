#pragma once
#include "..\..\define\Define.h"

Vector2f bullet::getPos()
{
	return s.getPosition();
}

bullet::bullet(int x, int y, float dx, float dy, int skill3, int skill4)
{
	spdx = dx;
	spdy = dy;
	bs = DBS + skill3 * 2;
	dmg = DBD + skill4;
	t.loadFromFile(BULLETFILE);
	s.setScale((float)bs / t.getSize().x, (float)bs / t.getSize().y);//скалирование размера под требуемое
	s.setPosition(x, y);
}

void bullet::draw(RenderWindow& wnd)
{
	s.setTexture(t);
	wnd.draw(s);
}

bool bullet::move(float time, maps level)
{
	s.move(spdx * time, spdy * time);
	float x = s.getPosition().x,
		y = s.getPosition().y;
	if ((x + bs > Width) || (x < 0) || (y + bs > Height) || (y < 0)) {
		return 1;//столкновение снарядов со стеной
	}
	if ((level.getTile((int)(x / TS), (int)(y / TS)) == '1') || (level.getTile((int)((x + bs - 1) / TS), (int)(y / TS)) == '1') || (level.getTile((int)((x + bs - 1) / TS), (int)((y + bs - 1) / TS)) == '1') || (level.getTile((int)(x / TS), (int)((y + bs - 1) / TS)) == '1')) {
		return 1;//столкновение снарядов с объектами на карте
	}
	return 0;
}

int bullet::getdmg()
{
	return dmg;
}

int bullet::getbs()
{
	return bs;
}

int bullet::getDBS()
{
	return DBS;
}