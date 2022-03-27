#pragma once
#include "..\..\define\Define.h"

int* hero::getSP()
{
	return sp;
}

hero::hero(int x, int y)
{
	sp = new int[3];
	*sp = 5;
	*(sp + 1) = 0;
	*(sp + 2) = 0;
	clock.restart();
	t.loadFromFile(HEROFILE);
	s.setTexture(t);
	s.setScale(2, 2);
	s.setPosition(x, y);
}

Sprite hero::getS()
{
	return s;
}

void hero::move(float time, maps level)
{
	int x = s.getPosition().x,
		y = s.getPosition().y;
	bool KeyUp = Keyboard::isKeyPressed(Keyboard::Up),
		KeyLeft = Keyboard::isKeyPressed(Keyboard::Left),
		KeyDown = Keyboard::isKeyPressed(Keyboard::Down),
		KeyRight = Keyboard::isKeyPressed(Keyboard::Right);
	float move = ms * time;
	if ((KeyUp + KeyLeft + KeyDown + KeyRight) == 2) {
		move /= sqrt(2);//приравнять скорость по диагоналям к скорости вдоль осей
	}
	if (KeyUp && (y - move > 0)) {//столкновение героя с границами карты
		if ((level.getTile((int)(x / TS), (int)((y - move) / TS)) != '1') && (level.getTile((int)((x + TS - 1) / TS), (int)((y - move) / TS)) != '1'))//столкновение героя с объектами на карте
			s.move(0, -move);
	}
	if (KeyLeft && (x - move > 0)) {
		if ((level.getTile((int)((x - move) / TS), (int)(y / TS)) != '1') && (level.getTile((int)((x - move) / TS), (int)((y + TS - 1) / TS)) != '1'))
			s.move(-move, 0);
	}
	if (KeyDown && (y + TS + move < Height)) {
		if ((level.getTile((int)(x / TS), (int)((y + TS + move) / TS)) != '1') && (level.getTile((int)((x + TS - 1) / TS), (int)((y + TS + move) / TS)) != '1'))
			s.move(0, move);
	}
	if (KeyRight && (x + TS + move < Width)) {
		if ((level.getTile((int)((x + TS + move) / TS), (int)(y / TS)) != '1') && (level.getTile((int)((x + TS + move) / TS), (int)((y + TS - 1) / TS)) != '1'))
			s.move(move, 0);
	}
}

bool hero::shooting(vector<bullet>* bts)
{
	float x = s.getPosition().x;
	float y = s.getPosition().y;
	bool KeyW = Keyboard::isKeyPressed(Keyboard::W),//стрельба
		KeyA = Keyboard::isKeyPressed(Keyboard::A),
		KeyS = Keyboard::isKeyPressed(Keyboard::S),
		KeyD = Keyboard::isKeyPressed(Keyboard::D);
	if (clock.getElapsedTime().asMilliseconds() > at) {
		if ((KeyW + KeyA + KeyS + KeyD) == 1) {//стрельба вдоль осей
			if (KeyW)
				(*bts).push_back(bullet(x + 24, y - 16, 0, -bs));
				if (KeyA)
					(*bts).push_back(bullet(x - 16, y + 24, -bs, 0));
				if (KeyS)
					(*bts).push_back(bullet(x + 24, y + TS, 0, bs));
				if (KeyD)
					(*bts).push_back(bullet(x + TS, y + 24, bs, 0));
				clock.restart();
				return true;
		}
		if ((KeyW + KeyA + KeyS + KeyD) == 2) {//стрельба по диагоналям
			float dbs = bs / sqrt(2);//diagonal bullet speed
			if ((KeyW) && (KeyA))
				(*bts).push_back(bullet(x, y, -dbs, -dbs));
			if ((KeyA) && (KeyS))
				(*bts).push_back(bullet(x, y + TS, -dbs, dbs));
			if ((KeyS) && (KeyD))
				(*bts).push_back(bullet(x + TS, y + TS, dbs, dbs));
			if ((KeyD) && (KeyW))
				(*bts).push_back(bullet(x + TS, y, dbs, -dbs));
			clock.restart();
			return true;
		}
	}
	return false;
}

void hero::rescale()
{
	ms = DMS * (1 + *(sp + 1) * 0.2);
	at = DAT / (1 + *(sp + 2) * 0.3);
}

void hero::setpos(int x, int y)
{
	s.setPosition(x, y);
}