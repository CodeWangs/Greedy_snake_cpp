#include "Snack.h"

Snack::Snack()
{
	//��ʼ����ͷ��λ�ú��ߵĳ���
	this->s_head = new Node(SnackHeadX, SnackHeadY);
	this->s_len = 3;

	//��ʼ��һ�� s_len = 3 ��С��
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

//����С�ߵ�ͷ�ڵ�
void Snack::SetSnackHead(Node* node)
{
	this->s_head = node;
}

//��ȡС�ߵ�ͷ�ڵ�
Node* Snack::GetSnackHead()
{
	return this->s_head;
}

//����С�ߵĳ���
void Snack::SetSnackLen(int len)
{
	this->s_len = len;
}

//��ȡС�ߵĳ���
int Snack::GetSnackLen()
{
	return this->s_len;
}

//�ҵ�С�ߵ�β�ڵ�
Node* Snack::Find_SnackTail()
{
	//����һ��ָ��ͷ�ڵ��ָ��
	Node* pS_head = new Node;

	pS_head = this->s_head;
	while (pS_head != NULL)
	{
		pS_head = pS_head->GetNodeNext();
	}
	return pS_head;
}

//�Ƿ�ҧ���Լ�
bool Snack::IfBite_Self()
{
	//����һ���ڵ�ָ���������б���
	Node* pNode = new Node;
	pNode = this->s_head->GetNodeNext();

	while (pNode != NULL)//(pNode->GetNodeNext() != NULL)  ע�ⲻ��next
	{
		if (this->s_head->GetX() == pNode->GetX() && this->s_head->GetY() == pNode->GetY())
		{
			return true;
		}
		pNode = pNode->GetNodeNext();
	}

	return false;
}





