#pragma once
#include "define/Define.h"

int main() {
	RenderWindow wnd(VideoMode(Width, Height), "Akimbo");//����
	hero hero;//��������, �����
	vector<bullet> bts;//������ ��������
	vector<enemy> enm;//����
	maps level;//�������, �����
	level.lvl1();//�������� 1-��� ������
	game_menu gm;//������ - ����
	Clock clock;//game timer
	bool pause = 0,
		eg = 0;//���������� �����
	button timer,//���� �������
		end_game,//���� � ����� ����
		ok;
	timer.shape(Width - 180, 0, 180, 40, Color(0, 255, 0, 128), 10, 2, "", 30, Color::Red);
	end_game.shape(Width / 2 - 100, Height / 2 - 50, 200, 100, Color(0, 255, 0, 255), 5, 0, "", 40, Color::Red);
	ok.shape(Width / 2 - 100, Height / 2 + 60, 200, 50, Color(0, 255, 0, 255), 80, 0, "OK", 40, Color::Red);
	srand(time(0));
	double time, timer_value = 0;//����� ���� � �������������
	int last_spawn = 0;//���������� ��������� ������
	while (wnd.isOpen()) {
		double time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		//������� �������
		Event event;
		while (wnd.pollEvent(event)) {
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Escape)
					pause = !pause;//����������� ����� ��� ������� escape
			if (event.type == Event::Closed)
				wnd.close();
			if (pause) {//���� �� �����
				if (event.type == Event::MouseButtonPressed)
					if (event.key.code == Mouse::Left) {
						if (gm.smp(wnd, hero))
							hero.rescale();
						if (gm.mmp(wnd, 1))
							pause = 0;
						if (gm.mmp(wnd, 2)) {
							hero.restart();
							last_spawn = 0;
							timer_value = 0;
							bts.clear();
							enm.clear();
						}
						if (gm.mmp(wnd, 3))
							wnd.close();
					}
			}
			if (eg) {//����� ����
				if (event.type == Event::MouseButtonPressed)
					if (event.key.code == Mouse::Left)
						if (ok.press(Mouse::getPosition(wnd).x, Mouse::getPosition(wnd).y)) {
							hero.restart();
							last_spawn = 0;
							timer_value = 0;
							bts.clear();
							enm.clear();
							eg = 0;
						}
			}
		}

		//���������
		wnd.clear(Color::Green);//������� ����
		level.draw(wnd);//��������� ������
		hero.draw(wnd);//��������� �����
		timer.change_text("Time: " + to_string((int)(timer_value / 1000000)));
		timer.draw(wnd);//��������� �������
		for (int i = 0; i < bts.size(); i++) {//��������� ��������
			bts[i].draw(wnd);
		}
		for (int i = 0; i < enm.size(); i++) {//��������� ������
			enm[i].draw(wnd);
		}

		if (eg) {//���� ���� ��������
			end_game.change_text("Your score\n" + to_string((int)(timer_value / 1000000)));
			end_game.draw(wnd);//���������� ����
			ok.draw(wnd);//���������� "OK"
		}
		else {
			if (pause) {//���� ���� �� �����
				gm.show(wnd, hero);//���������� ����
			}
			else {//�������� � �������������� ��������, ���� ���� �� �� �����
				hero.move(time, level);//�������� �����
				hero.shooting(&bts);//��������
				if (hero.hit(&enm))//����� ����
					eg = 1;
				for (int i = 0; i < bts.size(); i++) {//��������� ��������
					if (bts[i].move(time, level)) {//�������� ��������
						bts.erase(bts.begin() + i);//�������� ������� � ������ ������������
						i--;
					}
				}
				for (int i = 0; i < enm.size(); i++) {//��������� ������
					enm[i].move(time, level, hero.getpos());//�������� ������
					int k;//����� ����� � �������, �� �������� ����� ������
					k = enm[i].hit(&bts);//���� �� ����� ����� ������
					if (k >= 0) {//��������� �� �����
						bts.erase(bts.begin() + k);//���������� ������
						if (enm[i].isdead()) {//���� ���� �����
							enm.erase(enm.begin() + i);//������� ���
							--i;
							hero.lvlup();//���� ����� �������
						}
					}
				}
				timer_value += time;//������� ������
				if ((int)(timer_value / 5000000) >= last_spawn) {//������� ��������� ������ n ������
					enm.push_back(enemy(level.getSP(), last_spawn));
					last_spawn++;
				}
			}
		}
		wnd.display();
	}
	return 0;
}