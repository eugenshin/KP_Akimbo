#pragma once
#include "define/Define.h"
using namespace sf;
using namespace std;

int main() {
	vector<bullet> bts;
	RenderWindow wnd(VideoMode(Width, Height), "Akimbo");
	hero hero(100, 100);
	maps level;
	level.lvl1();
	game_menu gm;
	int n = 0;//bullet vector size
	Clock clock;//game timer
	bool pause = 0;
	while (wnd.isOpen()) {
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		Event event;
		while (wnd.pollEvent(event)) {
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Tab) {
					pause = !pause;
				}
			}
			if (event.type == Event::Closed) {
				wnd.close();
			}
		}
		wnd.clear(Color::Green);
		wnd.draw(hero.getS());
		level.draw(&wnd);
		for (int i = 0; i < n; i++) {
			bts[i].ttr();
			wnd.draw(bts[i].getS());
		}
		if (pause) {
			gm.show(&wnd);
		}
		else {
			hero.move(time, level);
			for (int i = 0; i < n; i++) {
				bts[i].move(time);//движение снарядов
				if ((bts[i].getS().getPosition().x > Width - 16) || (bts[i].getS().getPosition().x < 0) || (bts[i].getS().getPosition().y > Height - 16) || (bts[i].getS().getPosition().y < 0)) {
					bts.erase(bts.begin() + i);//столкновение снарядов со стеной
					i--;
					n--;
				}
			}
			n += hero.shooting(&bts);//стрельба
		}
		wnd.display();
	}
	return 0;
}