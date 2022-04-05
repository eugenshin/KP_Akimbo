#pragma once
#include "..\..\define\Define.h"

button::button()
{
	font.loadFromFile(FONT);
	text.setFont(font);
	text.setStyle(Text::Bold);
	text.setOutlineColor(Color::Black);
	text.setOutlineThickness(1);
	box.setOutlineColor(Color::Black);
	box.setOutlineThickness(3);
}

void button::draw(RenderWindow& wnd)
{//отрисовка button
	wnd.draw(box);
	wnd.draw(s);
	wnd.draw(text);
}

void button::change_text(string str)
{
	text.setString(str);
}

void button::move(int dx, int dy)
{
	box.move(dx, dy);
	text.move(dx, dy);
	s.move(dx, dy);
}

bool button::press(int x, int y)
{
	if (box.getSize().x != 0) {
		if ((x > box.getPosition().x) && (y > box.getPosition().y) && (x < box.getPosition().x + box.getSize().x) && (y < box.getPosition().y + box.getSize().y))
			return true;
	}
	else
		if ((x > s.getPosition().x) && (y > s.getPosition().y) && (x < s.getPosition().x + t.getSize().x * s.getScale().x) && (y < s.getPosition().y + t.getSize().y * s.getScale().y))
			return true;
	return false;
}

void button::shape(int x, int y, int w, int h, Color bc, int tx, int ty, string str, int size, Color tc)
{//метод с передачей прямоугольника
	box.setSize(Vector2f(w, h));
	box.setFillColor(bc);
	box.setPosition(x, y);
	text.setCharacterSize(size);
	text.setString(str);
	text.setColor(tc);
	text.setPosition(x + tx, y + ty);
}

void button::shape(int x, int y, int w, int h, string path, int tx, int ty, string str, int size, Color tc)
{//метод с передачей текстуры
	t.loadFromFile(path);
	s.setTexture(t);
	s.setScale((float)w / t.getSize().x, (float)h / t.getSize().y);//скалирование размера под требуемое
	s.setPosition(x, y);
	text.setCharacterSize(size);
	text.setString(str);
	text.setColor(tc);
	text.setPosition(x + tx, y + ty);
}