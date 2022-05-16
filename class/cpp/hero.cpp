#pragma once
#include "..\..\define\Define.h"

int hero::getSP(int n)
{
	return sp[n];
}

bool hero::useskill(int n)
{
	if ((n > 0) && (n < SKILLS)) {
		if ((sp[0] > 0) && (sp[n] < 24)) {
			sp[0] -= 1;
			sp[n]++;
			return 1;
		}
	}
	return 0;
}

hero::hero()
{
	sp.push_back(0);//свободных очков умений
	sp.push_back(0);//очков в 1 способности
	sp.push_back(0);//очков во 2 способности
	sp.push_back(0);//очков в 3 способности
	sp.push_back(0);//очков в 4 способности
	clock.restart();
	t.loadFromFile(HEROFILE);
	s.setTexture(t);
	s.setScale(2, 2);
	s.setPosition(100, 100);
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
		move /= sqrt(2);//приравн€ть скорость по диагонал€м к скорости вдоль осей
	}
	if (KeyUp && (y - move > 0)) {//столкновение геро€ с границами карты
		if ((level.getTile((int)(x / TS), (int)((y - move) / TS)) != '1') && (level.getTile((int)((x + TS - 1) / TS), (int)((y - move) / TS)) != '1'))//столкновение геро€ с объектами на карте
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

void hero::shooting(vector<bullet>* bts)
{
	float x = s.getPosition().x,
		y = s.getPosition().y;
	int btsz = bullet::getDBS() + sp[3] * 2;//bullet size
	bool KeyW = Keyboard::isKeyPressed(Keyboard::W),//стрельба
		KeyA = Keyboard::isKeyPressed(Keyboard::A),
		KeyS = Keyboard::isKeyPressed(Keyboard::S),
		KeyD = Keyboard::isKeyPressed(Keyboard::D);
	if (clock.getElapsedTime().asMilliseconds() > at) {
		if ((KeyW + KeyA + KeyS + KeyD) == 1) {//стрельба вдоль осей
			if (KeyW)
				(*bts).push_back(bullet(x + (TS - btsz) / 2, y - btsz, 0, -bs, sp[3], sp[4]));
				if (KeyA)
					(*bts).push_back(bullet(x - btsz, y + (TS - btsz) / 2, -bs, 0, sp[3], sp[4]));
				if (KeyS)
					(*bts).push_back(bullet(x + (TS - btsz) / 2, y + TS, 0, bs, sp[3], sp[4]));
				if (KeyD)
					(*bts).push_back(bullet(x + TS, y + (TS - btsz) / 2, bs, 0, sp[3], sp[4]));
				clock.restart();
				return;
		}
		if ((KeyW + KeyA + KeyS + KeyD) == 2) {//стрельба по диагонал€м
			float dbs = bs / sqrt(2);//diagonal bullet speed
			if ((KeyW) && (KeyA))
				(*bts).push_back(bullet(x - btsz / 2, y - btsz / 2, -dbs, -dbs, sp[3], sp[4]));
			if ((KeyA) && (KeyS))
				(*bts).push_back(bullet(x - btsz / 2, y + TS - btsz / 2, -dbs, dbs, sp[3], sp[4]));
			if ((KeyS) && (KeyD))
				(*bts).push_back(bullet(x + TS - btsz / 2, y + TS - btsz / 2, dbs, dbs, sp[3], sp[4]));
			if ((KeyD) && (KeyW))
				(*bts).push_back(bullet(x + TS - btsz / 2, y - btsz / 2, dbs, -dbs, sp[3], sp[4]));
			clock.restart();
		}
	}
}

void hero::rescale()
{
	ms = DMS * (1 + sp[1] * 0.2);//перерасчЄт скорости передвижени€
	at = DAT / (1 + sp[2] * 0.1);//перерасчЄт скорости стрельбы
}

Vector2f hero::getpos()
{
	return s.getPosition();
}

void hero::lvlup()
{
	sp[0]++;
}

bool hero::hit(vector<enemy>* enm)
{
	for(int i = 0; i < enm->size(); i++) {
		if (((*enm)[i].getPos().x + TS > s.getPosition().x) && ((*enm)[i].getPos().x < s.getPosition().x + TS) && ((*enm)[i].getPos().y + TS > s.getPosition().y) && ((*enm)[i].getPos().y < s.getPosition().y + TS)) {//коснулс€ ли враг игрока?
			return 1;
		}
	}
	return 0;
}

int hero::getMAXSKILLS()
{
	return MAXSKILLS;
}

void hero::restart()
{
	s.setPosition(100, 100);
	for (int i = 0; i < SKILLS; i++)
		sp[i] = 0;
	rescale();
}

void hero::draw(RenderWindow& wnd)
{
	wnd.draw(s);
}