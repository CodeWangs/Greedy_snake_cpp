#pragma once
#include <iostream>
#include <string.h>
using namespace std;


//蛇身结点
class Node
{
protected:
	int n_x;
	int n_y;
	string n_data = "■";
	Node* next;

public:
	Node(int x,int y);
	Node();
	~Node();

	//设置节点X坐标
	void SetX(int x);

	//获取节点X坐标
	int GetX();

	//设置节点Y坐标
	void SetY(int y);

	//获取节点Y坐标
	int GetY();

	//设置节点的 next节点
	void SetNodeNext(Node *node);

	//获取节点的 next节点
	Node* GetNodeNext();

	//打印节点的字符
	void Printf_Node();



};