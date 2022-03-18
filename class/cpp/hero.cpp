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

void hero::move(float time)
{
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		s.move(ms * time, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		s.move(-ms * time, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		s.move(0, -ms * time);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		s.move(0, ms * time);
	}
}

float hero::getAS()
{
	return as;
}

void hero::setpos(int x, int y)
{
	s.setPosition(x, y);
}