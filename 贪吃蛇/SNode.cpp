#include "SNode.h"

Node::Node(int x, int y)
{
	this->n_x = x;
	this->n_y = y;
	this->n_data = "■";
	this->next = NULL;
}

Node::Node()
{
	this->n_x = 0;
	this->n_y = 0;
	this->n_data = "■";
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

//设置节点X坐标
void Node::SetX(int x)
{
	this->n_x = x;
}

//获取节点X坐标
int Node::GetX()
{
	return this->n_x;
}

//设置节点Y坐标
void Node::SetY(int y)
{
	this->n_y = y;
}

//获取节点Y坐标
int Node::GetY()
{
	return this->n_y;
}

//设置节点的 next属性
void Node::SetNodeNext(Node* node)
{
	this->next = node;
}

//获取节点的 next属性
Node* Node::GetNodeNext()
{
	return next;
}

//打印节点的字符
void Node::Printf_Node()
{
	cout << this->n_data;
}



