#pragma once
#include "define/Define.h"
#include "class/header/hero.h"
using namespace sf;

bool shooting(const float x, const float y,const float at, const float bs, Clock* clock, vector<bullet>* bts)
{
	bool KeyW = Keyboard::isKeyPressed(Keyboard::W),//стрельба
		KeyA = Keyboard::isKeyPressed(Keyboard::A),
		KeyS = Keyboard::isKeyPressed(Keyboard::S),
		KeyD = Keyboard::isKeyPressed(Keyboard::D);
	if (((KeyW + KeyA + KeyS + KeyD) == 1)&&((*clock).getElapsedTime().asMilliseconds() > at)) {
		if (KeyW)
			(*bts).push_back(bullet(x + 12, y - 8, 0, -bs));
		if (KeyA)
			(*bts).push_back(bullet(x - 8, y + 12, -bs, 0));
		if (KeyS)
			(*bts).push_back(bullet(x + 12, y + 32, 0, bs));
		if (KeyD)
			(*bts).push_back(bullet(x + 32, y + 12, bs, 0));
		clock->restart();
		return true;
	}
	return false;
}

int main() {
	const int Width = 200, Height = 200;
	vector<bullet> bts;
	RenderWindow wnd(VideoMode(Width, Height), "Akimbo");
	hero hero(100, 100);
	int n = 0;//bullet vector size
	Clock clock,//game timer
		stck;//shooting timer
	while (wnd.isOpen()) {
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		Event event;
		while (wnd.pollEvent(event)) {
			if (event.type == Event::Closed) {
				wnd.close();
			}
		}
		wnd.clear(Color::Green);
		hero.move(time, Width, Height);
		wnd.draw(hero.getS());

		for (int i = 0; i < n; i++) {
			bts[i].move(time);//движение снар€дов
			bts[i].ttr();//отрисовка снар€дов
			wnd.draw(bts[i].getS());
			if ((bts[i].getS().getPosition().x > Width - 8)||(bts[i].getS().getPosition().x < 0)||(bts[i].getS().getPosition().y > Height - 8)||(bts[i].getS().getPosition().y < 0)) {
				bts.erase(bts.begin() + i);//столкновение снар€дов со стеной
				i--;
				n--;
			}
		}

		n += shooting(hero.getS().getPosition().x, hero.getS().getPosition().y, hero.getAT(), hero.getBS(), &stck, &bts);//стрельба

		wnd.display();
	}
	return 0;
}