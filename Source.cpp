#pragma once
#include "define/Define.h"

int main() {
	RenderWindow wnd(VideoMode(Width, Height), "Akimbo");//окно
	hero hero;//персонаж, герой
	vector<bullet> bts;//вектор снарядов
	vector<enemy> enm;//враг
	maps level;//уровень, карта
	level.lvl1();//загрузка 1-ого уровня
	game_menu gm;//объект - меню
	Clock clock;//game timer
	bool pause = 0,
		eg = 0;//переменная паузы
	button timer,//окно таймера
		end_game,//счёт в конце игры
		ok;
	timer.shape(Width - 180, 0, 180, 40, Color(0, 255, 0, 128), 10, 2, "", 30, Color::Red);
	end_game.shape(Width / 2 - 100, Height / 2 - 50, 200, 100, Color(0, 255, 0, 255), 5, 0, "", 40, Color::Red);
	ok.shape(Width / 2 - 100, Height / 2 + 60, 200, 50, Color(0, 255, 0, 255), 80, 0, "OK", 40, Color::Red);
	srand(time(0));
	double time, timer_value = 0;//время игры в микросекундах
	int last_spawn = 0;//количество созданных врагов
	while (wnd.isOpen()) {
		double time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		//игровые события
		Event event;
		while (wnd.pollEvent(event)) {
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Escape)
					pause = !pause;//переключить паузу при нажатии escape
			if (event.type == Event::Closed)
				wnd.close();
			if (pause) {//игра на паузе
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
			if (eg) {//конец игры
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

		//отрисовка
		wnd.clear(Color::Green);//очистка окна
		level.draw(wnd);//отрисовка уровня
		hero.draw(wnd);//отрисовка героя
		timer.change_text("Time: " + to_string((int)(timer_value / 1000000)));
		timer.draw(wnd);//отрисовка таймера
		for (int i = 0; i < bts.size(); i++) {//отрисовка снарядов
			bts[i].draw(wnd);
		}
		for (int i = 0; i < enm.size(); i++) {//отрисовка врагов
			enm[i].draw(wnd);
		}

		if (eg) {//если игра окончена
			end_game.change_text("Your score\n" + to_string((int)(timer_value / 1000000)));
			end_game.draw(wnd);//отобразить счёт
			ok.draw(wnd);//отобразить "OK"
		}
		else {
			if (pause) {//если игра на паузе
				gm.show(wnd, hero);//отображать меню
			}
			else {//движение и взаимодействие объектов, если игра не на паузе
				hero.move(time, level);//движение героя
				hero.shooting(&bts);//стрельба
				if (hero.hit(&enm))//конец игры
					eg = 1;
				for (int i = 0; i < bts.size(); i++) {//поведение снарядов
					if (bts[i].move(time, level)) {//движение снарядов
						bts.erase(bts.begin() + i);//удаление снаряда в случае столкновения
						i--;
					}
				}
				for (int i = 0; i < enm.size(); i++) {//поведение врагов
					enm[i].move(time, level, hero.getpos());//движение врагов
					int k;//номер врага в векторе, по которому попал снаряд
					k = enm[i].hit(&bts);//если по врагу попал снаряд
					if (k >= 0) {//попадание по врагу
						bts.erase(bts.begin() + k);//уничтожить снаряд
						if (enm[i].isdead()) {//если враг мертв
							enm.erase(enm.begin() + i);//удалить его
							--i;
							hero.lvlup();//дать герою уровень
						}
					}
				}
				timer_value += time;//игровой таймер
				if ((int)(timer_value / 5000000) >= last_spawn) {//частота появления врагов n секунд
					enm.push_back(enemy(level.getSP(), last_spawn));
					last_spawn++;
				}
			}
		}
		wnd.display();
	}
	return 0;
}