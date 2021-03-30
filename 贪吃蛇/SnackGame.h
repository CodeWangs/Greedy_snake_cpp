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

	//����С��
	void SetSnack(Snack* snack);

	//��ȡС��
	Snack* GetSnack();

	//���ù�ʵ
	void SetFruit(Fruit* fruit);

	//��ȡ��ʵ
	Fruit* GetFruit();

	//���÷���
	void SetScore(int score);

	//��ȡ����
	int GetScore();

	//��ʼ��Ϸ����
	void BegainGame();

	//������Ϸ����
	void EndGame();

	//������ͼ
	void Create_Map();

	//��ʼ��һ��С��
	void Create_Snack();

	//������ʵ
	void Create_Fruit();

	//�ж����Ƿ�ײǽ
	bool IfHitWall();

	//�Ƿ�Ե�ˮ��
	bool IfBite_Fruit();

	//С���ƶ�
	//�����ƶ�
	int Move_Up();

	//�����ƶ�
	int Move_Down();

	//�����ƶ�
	int Move_Left();

	//�����ƶ�
	int Move_Right();

	//С���ƶ�
	int Move_Snack(char direction);

	//����С���ƶ�
	void Control_Move();

};


