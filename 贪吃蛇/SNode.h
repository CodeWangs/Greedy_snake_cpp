#pragma once
#include <iostream>
#include <string.h>
using namespace std;


//������
class Node
{
protected:
	int n_x;
	int n_y;
	string n_data = "��";
	Node* next;

public:
	Node(int x,int y);
	Node();
	~Node();

	//���ýڵ�X����
	void SetX(int x);

	//��ȡ�ڵ�X����
	int GetX();

	//���ýڵ�Y����
	void SetY(int y);

	//��ȡ�ڵ�Y����
	int GetY();

	//���ýڵ�� next�ڵ�
	void SetNodeNext(Node *node);

	//��ȡ�ڵ�� next�ڵ�
	Node* GetNodeNext();

	//��ӡ�ڵ���ַ�
	void Printf_Node();



};