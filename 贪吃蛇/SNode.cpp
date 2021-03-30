#include "SNode.h"

Node::Node(int x, int y)
{
	this->n_x = x;
	this->n_y = y;
	this->n_data = "��";
	this->next = NULL;
}

Node::Node()
{
	this->n_x = 0;
	this->n_y = 0;
	this->n_data = "��";
	this->next = NULL;
}

Node::~Node()
{
	if (this->next != NULL)
	{
		delete this->next;
		this->next = NULL;
	}
}

//���ýڵ�X����
void Node::SetX(int x)
{
	this->n_x = x;
}

//��ȡ�ڵ�X����
int Node::GetX()
{
	return this->n_x;
}

//���ýڵ�Y����
void Node::SetY(int y)
{
	this->n_y = y;
}

//��ȡ�ڵ�Y����
int Node::GetY()
{
	return this->n_y;
}

//���ýڵ�� next����
void Node::SetNodeNext(Node* node)
{
	this->next = node;
}

//��ȡ�ڵ�� next����
Node* Node::GetNodeNext()
{
	return next;
}

//��ӡ�ڵ���ַ�
void Node::Printf_Node()
{
	cout << this->n_data;
}



