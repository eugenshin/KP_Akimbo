#pragma once
#include "..\..\define\Define.h"

game_menu::game_menu()
{
	rect.setSize(Vector2f(Width, Height));
	rect.setFillColor(Color(0,0,0,128));
	rect.setPosition(0, 0);
	menu.shape(Width / 2 - 400, Height / 2 - 300, 300, 600, Color(102, 204, 102, 255), 45, 0, "Menu", 100, Color(0, 153, 0, 255));
	skills.shape(Width / 2 - 80, Height / 2 - 300, 480, 600, Color(102, 204, 102, 255), 20, 0, "", 50, Color(0, 153, 0, 255));
	int d = 80;//расстояния между кнопками
	skill1.shape(Width / 2 - 60, Height / 2 - 150, 50, 50, PLUS, 70, 0, "", 20, Color::Green);
	skill4 = skill3 = skill2 = skill1;
	skill2.move(0, d);
	skill3.move(0, 2 * d);
	skill4.move(0, 3 * d);
	cont.shape(Width / 2 - 360, Height / 2 - 170, 220, 80, Color(51, 204, 51, 255), 15, 8, "Continue", 50, Color(0, 153, 0, 255));
	d = 100;
	exit = restart = cont;
	restart.move(0, d);
	restart.change_text("Restart");
	exit.move(0, 2 * d);
	exit.change_text("Exit");
}

bool game_menu::smp(RenderWindow& wnd, hero& hero)
{
	float mx = Mouse::getPosition(wnd).x, my = Mouse::getPosition(wnd).y;
	if(skill1.press(mx, my))
		return hero.useskill(1);
	if(skill2.press(mx, my))
		return hero.useskill(2);
	if(skill3.press(mx, my))
		return hero.useskill(3);
	if(skill4.press(mx, my))
		return hero.useskill(4);
}

bool game_menu::mmp(RenderWindow& wnd, int n)
{
	switch (n) {
	case 1:
		return cont.press(Mouse::getPosition(wnd).x, Mouse::getPosition(wnd).y);
		break;
	case 2:
		return restart.press(Mouse::getPosition(wnd).x, Mouse::getPosition(wnd).y);
		break;
	case 3:
		return exit.press(Mouse::getPosition(wnd).x, Mouse::getPosition(wnd).y);
		break;
	}
	return 0;
}

void game_menu::show(RenderWindow& wnd, hero& hero)
{
	skills.change_text("You have " + to_string(hero.getSP(0)) + " unused\nskill point");
	if (hero.getSP(1) < hero.getMAXSKILLS())
		skill1.change_text("Level " + to_string(hero.getSP(1)) + "\nIncrease movement speed");
	else
		skill1.change_text(to_string(hero.getSP(1)) + " - max level\nIncrease movement speed");
	if (hero.getSP(2) < hero.getMAXSKILLS())
		skill2.change_text("Level " + to_string(hero.getSP(2)) + "\nIncrease attack speed");
	else
		skill2.change_text(to_string(hero.getSP(2)) + " - max level\nIncrease attack speed");
	if (hero.getSP(3) < hero.getMAXSKILLS())
		skill3.change_text("Level " + to_string(hero.getSP(3)) + "\nIncrease bullet size");
	else
		skill3.change_text(to_string(hero.getSP(3)) + " - max level\nIncrease bullet size");
	if (hero.getSP(4) < hero.getMAXSKILLS())
		skill4.change_text("Level " + to_string(hero.getSP(4)) + "\nIncrease bullet damage");
	else
		skill4.change_text(to_string(hero.getSP(4)) + " - max level\nIncrease bullet damage");
	wnd.draw(rect);
	menu.draw(wnd);
	skills.draw(wnd);
	skill1.draw(wnd);
	skill2.draw(wnd);
	skill3.draw(wnd);
	skill4.draw(wnd);
	cont.draw(wnd);
	restart.draw(wnd);
	exit.draw(wnd);
}