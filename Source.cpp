#pragma once
#include "define/Define.h"
#include "class/header/hero.h"
using namespace sf;
int main() {
	const int Width = 200, Height = 200;
	vector<bullet> bts;
	RenderWindow wnd(VideoMode(Width, Height), "Akimbo");
	hero hero(100, 100);
	int n = 0;//bullet vector size
	const float DAD = 800,//default attack delay
		DBS = 0.0001;//default bullet speed
	bool shoot = 0, KeyW = 0, KeyA = 0, KeyS = 0, KeyD = 0;
	Clock clock,//game timer
		clockas;//shooting timer
	while (wnd.isOpen()) {
		if (clockas.getElapsedTime().asMilliseconds() > (DAD / hero.getAS())) {
			shoot = 1;
		}
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		Event event;
		while (wnd.pollEvent(event)) {
			if (event.type == Event::Closed) {
				wnd.close();
			}
		}
		wnd.clear(Color::Green);
		hero.move(time);
		wnd.draw(hero.getS());

		for (int i = 0; i < n; i++) {
			bts[i].move(time);
			wnd.draw(bts[i].getS());
			if ((bts[i].getS().getPosition().x > Width - 8)||(bts[i].getS().getPosition().x < 0)||(bts[i].getS().getPosition().y > Height - 8)||(bts[i].getS().getPosition().y < 0)) {
				bts.erase(bts.begin() + i);
				i--;
				n--;
			}
		}
		KeyW = Keyboard::isKeyPressed(Keyboard::W);
		KeyA = Keyboard::isKeyPressed(Keyboard::A);
		KeyS = Keyboard::isKeyPressed(Keyboard::S);
		KeyD = Keyboard::isKeyPressed(Keyboard::D);
		if (((KeyW + KeyA +KeyS + KeyD) == 1) && (shoot == 1)) {
			if (KeyW)
				bts.push_back(bullet(hero.getS().getPosition().x + 12, hero.getS().getPosition().y - 8, 0, -DBS));
			if (KeyA)
				bts.push_back(bullet(hero.getS().getPosition().x - 8, hero.getS().getPosition().y + 12, -DBS, 0));
			if (KeyS)
				bts.push_back(bullet(hero.getS().getPosition().x + 12, hero.getS().getPosition().y + 32, 0, DBS));
			if (KeyD) 
				bts.push_back(bullet(hero.getS().getPosition().x + 32, hero.getS().getPosition().y + 12, DBS, 0));
			n++;
			shoot = 0;
			clockas.restart();
		}

		for (int i = 0; i < n; i++) {
			bts[i].ttr();
		}
		wnd.display();
	}
	return 0;
}