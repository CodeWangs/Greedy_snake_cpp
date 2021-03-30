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
	string f_data = "●";

public:
	Fruit(int x, int y);
	Fruit();
	~Fruit();

	//设置果实X坐标
	void SetfX(int x);

	//获取果实X坐标
	int GetfX();

	//设置果实Y坐标
	void SetfY(int y);

	//获取果实Y坐标
	int GetfY();

	//打印果实的字符
	void Printf_Fruit();

};