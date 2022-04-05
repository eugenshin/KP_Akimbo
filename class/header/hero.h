#pragma once
#include "..\..\define\Define.h"

class hero:public object
{
	vector<int> sp;//skill points - ���� ������
	static constexpr float DAT = 800,//default attack time - ������� ����� �����
		DBS = 0.0003,//default bullet speed - ������� �������� ����
		DMS = 0.0001;//default move speed - ������� �������� ������������
	static constexpr int MAXSKILLS = 24,//������������ ������� ������
		SKILLS = 5;
	float at = DAT,//attack time - ����� �����
		bs = DBS,//bullet speed - �������� ����
		ms = DMS;//move speed - �������� ������������
	Clock clock;//shooting timer - ������ ��������
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