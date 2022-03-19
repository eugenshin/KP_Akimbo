#pragma once
#include "..\header\hero.h"
#define HEROFILE "src/hero.png"
using namespace sf;
hero::hero(int x, int y)
{
	t.loadFromFile(HEROFILE);
	s.setTexture(t);
	s.setPosition(x, y);
}

Sprite hero::getS()
{
	return s;
}

void hero::move(float time, int w, int h)
{
	int x = s.getPosition().x,
		y = s.getPosition().y;
	float move = ms * time;
	if ((Keyboard::isKeyPressed(Keyboard::Right)) && (x + SS[0] + move < w)) {
		s.move(move, 0);
	}
	if ((Keyboard::isKeyPressed(Keyboard::Left)) && (x - move > 0)) {
		s.move(-move, 0);
	}
	if ((Keyboard::isKeyPressed(Keyboard::Up)) && (y - move > 0)) {
		s.move(0, -move);
	}
	if ((Keyboard::isKeyPressed(Keyboard::Down)) && (y + SS[1] + move < h)) {
		s.move(0, move);
	}
}

float hero::getAT()
{
	return at;
}

float hero::getBS()
{
	return bs;
}

void hero::onmaptest(int h, int w)
{
	int x = s.getPosition().x,
		y = s.getPosition().y;
	if (x < 0)
		s.setPosition(0, y);
	if (y < 0)
		s.setPosition(x, 0);
	if (x > h - SS[0])
		s.setPosition(h - SS[0], y);
	if (y > w - SS[1])
		s.setPosition(x, w - SS[1]);
}

void hero::setpos(int x, int y)
{
	s.setPosition(x, y);
}