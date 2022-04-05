#pragma once
#include "..\..\define\Define.h"
class enemy:public object
{
	static constexpr float DMS = 0.00005;//default move speed
	static constexpr int DHP = 1;//default health points
	float ms;//move speed
	int hp;//health points
	char moving;//текущее направление движения
	int px, py;//previous x, y
	char route_building(maps level, int ex, int ey, int hx, int hy);//построение маршрута
public:
	enemy(vector<vector<int>> sp, int ls);
	void move(float time, maps level, Vector2f heropos);
	void draw(RenderWindow& wnd) override;
	Vector2f getPos();
	int hit(vector<bullet>* bts);
	bool isdead();
};