#pragma once
#include "define/Define.h"

int main() {
	vector<bullet> bts;//������ ����
	RenderWindow wnd(VideoMode(Width, Height), "Akimbo");//����
	hero hero(100, 100);//��������, �����
	maps level;//�������, �����
	level.lvl1();//�������� 1-��� ������
	game_menu gm;//������ - ����
	int n = 0;//bullet vector size
	Clock clock;//game timer
	bool pause = 0,//���������� �����
		lmbp = 0;//left mouse button pressed
	while (wnd.isOpen()) {
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		Event event;
		while (wnd.pollEvent(event)) {
			lmbp = 0;
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Tab)
					pause = !pause;
			if (event.type == Event::Closed)
				wnd.close();
			if (event.type == Event::MouseButtonPressed)
				if (event.key.code == Mouse::Left)
					if (gm.mp(&wnd, hero.getSP()))
						hero.rescale();
		}
		wnd.clear(Color::Green);
		wnd.draw(hero.getS());
		level.draw(&wnd);
		for (int i = 0; i < n; i++) {
			bts[i].ttr();
			wnd.draw(bts[i].getS());
		}
		if (pause) {
			gm.show(&wnd, hero.getSP());
		}
		else {
			hero.move(time, level);
			n += hero.shooting(&bts);//��������
			for (int i = 0; i < n; i++) {
				if (bts[i].move(time, level)) {//�������� ��������
					bts.erase(bts.begin() + i);//�������� ������� � ������ ������������
					i--;
					n--;
				}
			}
		}
		wnd.display();
	}
	return 0;
}