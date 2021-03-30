#pragma once
#include <iostream>
#include <string.h>
using namespace std;
#include <ctime>

#include "Others.h"


class Fruit
{
private:
	int f_x;
	int f_y;
	string f_data = "��";

public:
	Fruit(int x, int y);
	Fruit();
	~Fruit();

	//���ù�ʵX����
	void SetfX(int x);

	//��ȡ��ʵX����
	int GetfX();

	//���ù�ʵY����
	void SetfY(int y);

	//��ȡ��ʵY����
	int GetfY();

	//��ӡ��ʵ���ַ�
	void Printf_Fruit();

};