#pragma once
#include <iostream>
#include <ctime>
using namespace std;

#include "Snack.h"
#include "fruit.h"
#include "Others.h"


//#define map_Width 40
//#define map_Height 30

class SnackGame
{
private:
	Snack* snack;
	Fruit* fruit;
	int score;

public:

	SnackGame();
	~SnackGame();

	//设置小蛇
	void SetSnack(Snack* snack);

	//获取小蛇
	Snack* GetSnack();

	//设置果实
	void SetFruit(Fruit* fruit);

	//获取果实
	Fruit* GetFruit();

	//设置分数
	void SetScore(int score);

	//获取分数
	int GetScore();

	//开始游戏界面
	void BegainGame();

	//结束游戏界面
	void EndGame();

	//创建地图
	void Create_Map();

	//初始化一条小蛇
	void Create_Snack();

	//创建果实
	void Create_Fruit();

	//判断蛇是否撞墙
	bool IfHitWall();

	//是否吃到水果
	bool IfBite_Fruit();

	//小蛇移动
	//向上移动
	int Move_Up();

	//向下移动
	int Move_Down();

	//向左移动
	int Move_Left();

	//向右移动
	int Move_Right();

	//小蛇移动
	int Move_Snack(char direction);

	//控制小蛇移动
	void Control_Move();

};


