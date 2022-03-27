#pragma once
#include "..\..\define\Define.h"

game_menu::game_menu()
{
	rect.setSize(Vector2f(Width, Height));
	rect.setFillColor(Color(0,0,0,128));
	rect.setPosition(0, 0);
	menu.shape(Width / 2 - 400, Height / 2 - 300, 300, 600, Color(204, 102, 0, 255), 45, 0, "Menu", 100, Color::Red);
	skills.shape(Width / 2 - 80, Height / 2 - 300, 480, 600, Color(255, 102, 0, 255), 20, 0, "", 50, Color::Red);
	skill1.shape(Width / 2 - 60, Height / 2 - 150, 50, 50, TILE0, 70, 0, "", 20, Color::Green);
	skill2.shape(Width / 2 - 60, Height / 2 - 70, 50, 50, TILE0, 70, 0, "", 20, Color::Green);
}

bool game_menu::mp(RenderWindow* wnd, int *sp)
{
	float mx = Mouse::getPosition(*wnd).x, my = Mouse::getPosition(*wnd).y,
		bx = skill1.getSprite().getPosition().x, by = skill1.getSprite().getPosition().y;
	if ((mx > bx) && (mx < bx + 50) && (my > by) && (my < by + 50)) {
		if (*sp > 0) {
			*sp -= 1;
			*(sp+1) += 1;
			return 1;
		}
	}
	if ((mx > bx) && (mx < bx + 50) && (my > by + 80) && (my < by + 130)) {
		if (*sp > 0) {
			*sp -= 1;
			*(sp + 2) += 1;
			return 1;
		}
	}
}

void game_menu::show(RenderWindow* wnd, int *sp)
{
	skills.change_text("You have " + to_string(*sp) + " unused\nskill point");
	skill1.change_text("Level " + to_string(*(sp + 1)) + "\nIncrease movement speed");
	skill2.change_text("Level " + to_string(*(sp + 2)) + "\nIncrease attack speed");
	wnd->draw(rect);
	menu.draw(wnd);
	skills.draw(wnd);
	skill1.draw(wnd);
	skill2.draw(wnd);
}