#include "Snack.h"

Snack::Snack()
{
	//初始化蛇头的位置和蛇的长度
	this->s_head = new Node(SnackHeadX, SnackHeadY);
	this->s_len = 3;

	//初始化一个 s_len = 3 的小蛇
	Node* Node2 = new Node(SnackHeadX + 1, SnackHeadY);
	Node* Node3 = new Node(SnackHeadX + 2, SnackHeadY);

	this->s_head->SetNodeNext(Node2);
	Node2->SetNodeNext(Node3);
	Node3->SetNodeNext(NULL);

	
}

Snack::~Snack()
{
	if (this->s_head != NULL)
	{
		delete this->s_head;
		this->s_head = NULL;
	}
}

//设置小蛇的头节点
void Snack::SetSnackHead(Node* node)
{
	this->s_head = node;
}

//获取小蛇的头节点
Node* Snack::GetSnackHead()
{
	return this->s_head;
}

//设置小蛇的长度
void Snack::SetSnackLen(int len)
{
	this->s_len = len;
}

//获取小蛇的长度
int Snack::GetSnackLen()
{
	return this->s_len;
}

//找到小蛇的尾节点
Node* Snack::Find_SnackTail()
{
	//创建一个指向头节点的指针
	Node* pS_head = new Node;

	pS_head = this->s_head;
	while (pS_head != NULL)
	{
		pS_head = pS_head->GetNodeNext();
	}
	return pS_head;
}

//是否咬到自己
bool Snack::IfBite_Self()
{
	//创建一个节点指针用来进行遍历
	Node* pNode = new Node;
	pNode = this->s_head->GetNodeNext();

	while (pNode != NULL)//(pNode->GetNodeNext() != NULL)  注意不是next
	{
		if (this->s_head->GetX() == pNode->GetX() && this->s_head->GetY() == pNode->GetY())
		{
			return true;
		}
		pNode = pNode->GetNodeNext();
	}

	return false;
}





