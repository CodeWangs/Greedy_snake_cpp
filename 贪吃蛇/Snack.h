#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
#include <Windows.h>

#include "Others.h"
#include "SNode.h"

//��ͷ����ʼ����
#define SnackHeadX 20
#define SnackHeadY 8

//���̵ķ����
#define Up 72
#define Down 80
#define Left 75
#define Right 77


class Snack : public Node
{
private:
	Node* s_head;	//С�ߵ�ͷ�ڵ�
	int s_len;		//С�߳���

public:

	Snack();
	~Snack();

	//����С�ߵ�ͷ�ڵ�
	void SetSnackHead(Node* node);

	//��ȡС�ߵ�ͷ�ڵ�
	Node* GetSnackHead();

	//����С�ߵĳ���
	void SetSnackLen(int len);

	//��ȡС�ߵĳ���
	int GetSnackLen();

	//�ҵ�С�ߵ�β�ڵ�
	Node* Find_SnackTail();

	//�Ƿ�ҧ���Լ�
	bool IfBite_Self();


};