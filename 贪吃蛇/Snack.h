#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
#include <Windows.h>

#include "Others.h"
#include "SNode.h"

//蛇头的起始坐标
#define SnackHeadX 20
#define SnackHeadY 8

//键盘的方向键
#define Up 72
#define Down 80
#define Left 75
#define Right 77


class Snack : public Node
{
private:
	Node* s_head;	//小蛇的头节点
	int s_len;		//小蛇长度

public:

	Snack();
	~Snack();

	//设置小蛇的头节点
	void SetSnackHead(Node* node);

	//获取小蛇的头节点
	Node* GetSnackHead();

	//设置小蛇的长度
	void SetSnackLen(int len);

	//获取小蛇的长度
	int GetSnackLen();

	//找到小蛇的尾节点
	Node* Find_SnackTail();

	//是否咬到自己
	bool IfBite_Self();


};