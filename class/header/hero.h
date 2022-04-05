#pragma once
#include "..\..\define\Define.h"

class hero:public object
{
	vector<int> sp;//skill points - очки умений
	static constexpr float DAT = 800,//default attack time - базовое время атаки
		DBS = 0.0003,//default bullet speed - базовая скорость пуль
		DMS = 0.0001;//default move speed - базовая скорость передвижения
	static constexpr int MAXSKILLS = 24,//максимальный уровень умений
		SKILLS = 5;
	float at = DAT,//attack time - время атаки
		bs = DBS,//bullet speed - скорость пуль
		ms = DMS;//move speed - скорость передвижения
	Clock clock;//shooting timer - таймер стрельбы
public:
	int getSP(int n);
	bool useskill(int n);
	hero();
	void move(float time, maps level);
	void shooting(vector<bullet>* bts);
	void rescale();
	Vector2f getpos();
	void lvlup();
	bool hit(vector<enemy>* enm);
	int getMAXSKILLS();
	void restart();
	void draw(RenderWindow& wnd) override;
};