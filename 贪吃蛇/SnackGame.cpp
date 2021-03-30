#include "SnackGame.h"

SnackGame::SnackGame()
{
	this->snack = new Snack;
	this->fruit = new Fruit;
	this->score = 0;
}

SnackGame::~SnackGame()
{
	if (this->snack != NULL)
	{
		delete this->snack;
		this->snack = NULL;
	}

	if (this->fruit)
	{
		delete this->fruit;
		this->fruit = NULL;
	}
}

//����С��
void SnackGame::SetSnack(Snack* snack)
{
	this->snack = snack;
}

//��ȡС��
Snack* SnackGame::GetSnack()
{
	return this->snack;
}

//���ù�ʵ
void SnackGame::SetFruit(Fruit* fruit)
{
	this->fruit = fruit;
}

//��ȡ��ʵ
Fruit* SnackGame::GetFruit()
{
	return this->fruit;
}

//���÷���
void SnackGame::SetScore(int score)
{
	this->score = score;
}

//��ȡ����
int SnackGame::GetScore()
{
	return this->score;
}


//��ʼ��Ϸ����
void SnackGame::BegainGame()
{
	cout << "��ӭ����̰���ߴ���ս������" << endl;
	cout << "1  -->  ��ʼ��Ϸ" << endl;
	cout << "2  -->  ������Ϸ" << endl;
	cout << "��ѡ��";
}

//������Ϸ����
void SnackGame::EndGame()
{
	cout << "��Ϸ����������" << endl;
}

//������ͼ
void SnackGame::Create_Map()
{
	gotoxy(0, 0);
	for (int i = 0; i < map_Width; i++)
	{
		cout << "��";
	}
	cout << endl;
	for (int i = 0; i < (map_Height - 2); i++)
	{
		for (int j = 0; j < map_Width; j++)
		{
			if (j == 0 || j == (map_Width - 1))
			{
				cout << "��";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < map_Width; i++)
	{
		cout << "��";
	}
	cout << endl;

}

//��ʼ��һ��С��
void SnackGame::Create_Snack()
{
	Node* Phead = new Node;//����һ��ָ��ͷ�ڵ��ָ��
	Snack* snack = new Snack;//����һ��С��
	Phead = snack->GetSnackHead();

	//cout << this->head << endl;
	//cout << Phead << endl;
	gotoxy(Phead->GetX(), Phead->GetY());
	//gotoxy(SnackHeadX, SnackHeadY);
	while (Phead != NULL)
	{
		Phead->Printf_Node();
		Phead = Phead->GetNodeNext();
	}
	//cout << "���Դ���" << endl;

}

//������ʵ
void SnackGame::Create_Fruit()
{
	////����һ����ʵ
	////Fruit* newFruit = new Fruit;
	//this->fruit = new Fruit;
	////�����������ӣ����õ�ǰϵͳʱ���������������ֹÿ�����������ͬ
	//srand((unsigned int)time(NULL));//time��Ҫͷ�ļ�
	//int x = rand() % (map_Width - 4) + 2;
	//int y = rand() % (map_Height - 4) + 2;
	//gotoxy(x, y);
	////newFruit->Printf_Fruit();
	//this->fruit->Printf_Fruit();
	////���⣺��©��Ҫ�ѹ�ʵ������Ҳ���óɲ����������
	////newFruit->SetfX(x);
	////newFruit->SetfY(y);
	//this->fruit->SetfX(x);
	//this->fruit->SetfY(y);
	
	//���⣺��Ĭ�Ϲ��캯���У��Ѿ���this->fruit���ٿռ��ˣ���ʲô�����ﻹ��Ҫ���ٿռ䣿 �����ٿռ�Ͳ��������´���һ����ʵ
	this->fruit = new Fruit;
	
	//��������Ĺ�ʵ��������С�ߵġ����ϡ�����Ҫ�����жϣ�����������������´�����ʵ
	Node *pNode = new Node;
	pNode = this->snack->GetSnackHead();
	while (pNode != NULL)
	{
		if (pNode->GetX() == this->fruit->GetfX() && pNode->GetY() == this->fruit->GetfY())
		{
			delete pNode;

			Create_Fruit();
		}
		pNode = pNode->GetNodeNext();
	}
	gotoxy(this->fruit->GetfX(), this->fruit->GetfY());
	this->fruit->Printf_Fruit();

	//delete this->fruit;
	//this->fruit = NULL;
	//�˴������ͷ� this->fruit �Ŀռ䣬Ϊʲô����Ϊ�������������ͷ��ˣ�
}

//�ж����Ƿ�ײǽ
bool SnackGame::IfHitWall()
{
	if (this->snack->GetSnackHead()->GetX() == 0 || this->snack->GetSnackHead()->GetX() == (map_Width-1)*2
		|| this->snack->GetSnackHead()->GetY() == 0 || this->snack->GetSnackHead()->GetY() == map_Height-1)
	{
		return true;
	}

	return false;
}

//�Ƿ�Ե�ˮ��
bool SnackGame::IfBite_Fruit()
{
	if (this->snack->GetSnackHead()->GetX() == this->fruit->GetfX() 
		&& this->snack->GetSnackHead()->GetY() == this->fruit->GetfY())
	{
		return true;
	}
	return false;
}


//С���ƶ�
//�����ƶ�����ײǽ��ҧ�Լ�ʱ���� 0��
int SnackGame::Move_Up()
{
	//����һ���½ڵ㣬ָ�������С��Ҫȥ��λ��
	Node* newnode = new Node(this->snack->GetSnackHead()->GetX(), this->snack->GetSnackHead()->GetY() - 1);
	newnode->SetNodeNext(this->snack->GetSnackHead());

	this->snack->SetSnackHead(newnode);

	//�ж��Ƿ�ײǽ
	bool ifhitwall = this->IfHitWall();
	if (ifhitwall)
	{
		cout << "һ��С��ײǽ����" << endl;
		return 0;
	}

	//�ж��Ƿ�ҧ���Լ�
	bool ifbiteself = this->snack->IfBite_Self();
	if (ifbiteself)
	{
		cout << "ҧ���Լ�����" << endl;
		return 0;
	}

	//�ж��Ƿ�Ե�ƻ��
	bool ifeat = IfBite_Fruit();
	if (!ifeat)
	{
		//���û�гԵ���ʵ -> �ͷ�β�ڵ� -> �����ƶ�
		Node* p = new Node;//����һ���ڵ㣬������ӡ
		p = this->snack->GetSnackHead();
		while (p->GetNodeNext()->GetNodeNext() != NULL)
		{
			gotoxy(p->GetX(), p->GetY());
			p->Printf_Node();
			p = p->GetNodeNext();
		}
		//���� p ָ������ĵ����ڶ����ڵ�
		//��ԭ��β�ڵ��ͼ�����ǵ�
		gotoxy(p->GetNodeNext()->GetX(), p->GetNodeNext()->GetY());
		//gotoxy(p->GetX(), p->GetY());
		cout << "  ";

		//�ͷ����һ���ڵ�
		delete p->GetNodeNext();
		p->SetNodeNext(NULL);
	}
	else
	{
		//����Ե���ʵ -> ���ͷ�β�ڵ� -> ����䳤
		Node* p = new Node;//����һ���ڵ㣬������ӡ
		p = this->snack->GetSnackHead();
		while (p->GetNodeNext() != NULL)
		{
			gotoxy(p->GetX(), p->GetY());
			p->Printf_Node();
			p = p->GetNodeNext();
		}
		//���� p ָ������ĵ����ڶ����ڵ�
		//��ԭ��β�ڵ��ͼ�����ǵ�
		//gotoxy(p->GetNodeNext()->GetX(), p->GetNodeNext()->GetY());
		//gotoxy(p->GetX(), p->GetY());
		//cout << "  ";

		//�ͷ����һ���ڵ�
		//delete p->GetNodeNext();
		//p->SetNodeNext(NULL);

		//�ӷ�
		this->score += 10;
		//�ٴ���һ����ʵ
		this->Create_Fruit();
	}
}

//�����ƶ�
int SnackGame::Move_Down()
{
	//����һ���½ڵ㣬ָ�������С��Ҫȥ��λ��
	Node* newnode = new Node;
	newnode->SetX(this->snack->GetSnackHead()->GetX());
	newnode->SetY(this->snack->GetSnackHead()->GetY() + 1);
	newnode->SetNodeNext(this->snack->GetSnackHead());
	this->snack->SetSnackHead(newnode);

	//�ж��Ƿ�ײǽ
	bool ifhitwall = this->IfHitWall();
	if (ifhitwall)
	{
		cout << "һ��С��ײǽ����" << endl;
		return 0;
	}

	//�ж��Ƿ�ҧ���Լ�
	bool ifbiteself = this->snack->IfBite_Self();
	if (ifbiteself)
	{
		cout << "ҧ���Լ�����" << endl;
		return 0;
	}
	
	//�ж��Ƿ�Ե�ƻ��
	bool ifeat = IfBite_Fruit();
	if (!ifeat)
	{
		//���û�гԵ���ʵ -> �ͷ�β�ڵ� -> �����ƶ�
		Node* p = new Node;//����һ���ڵ㣬������ӡ
		p = this->snack->GetSnackHead();
		while (p->GetNodeNext()->GetNodeNext() != NULL)
		{
			gotoxy(p->GetX(), p->GetY());
			p->Printf_Node();
			p = p->GetNodeNext();
		}
		//���� p ָ������ĵ����ڶ����ڵ�
		//��ԭ��β�ڵ��ͼ�����ǵ�
		gotoxy(p->GetNodeNext()->GetX(), p->GetNodeNext()->GetY());
		cout << "  ";
		//�ͷ����һ���ڵ�
		delete p->GetNodeNext();
		p->SetNodeNext(NULL);
	}
	else
	{
		//����Ե���ʵ -> ���ͷ�β�ڵ� -> ����䳤
		Node* p = new Node;//����һ���ڵ㣬������ӡ
		p = this->snack->GetSnackHead();
		while (p->GetNodeNext()->GetNodeNext() != NULL)
		{
			gotoxy(p->GetX(), p->GetY());
			p->Printf_Node();
			p = p->GetNodeNext();
		}
		gotoxy(p->GetNodeNext()->GetX(), p->GetNodeNext()->GetY());

		//�ӷ�
		this->score += 10;
		//�ٴ���һ����ʵ
		this->Create_Fruit();

	}

}

//�����ƶ�
int SnackGame::Move_Left()
{
	//����һ���½ڵ㣬ָ�������С��Ҫȥ��λ��
	Node* newnode = new Node;
	newnode->SetX(this->snack->GetSnackHead()->GetX() - 2);
	newnode->SetY(this->snack->GetSnackHead()->GetY());
	newnode->SetNodeNext(this->snack->GetSnackHead());
	this->snack->SetSnackHead(newnode);

	//�ж��Ƿ�ײǽ
	bool ifhitwall = this->IfHitWall();
	if (ifhitwall)
	{
		cout << "һ��С��ײǽ����" << endl;
		return 0;
	}

	//�ж��Ƿ�ҧ���Լ�
	bool ifbiteself = this->snack->IfBite_Self();
	if (ifbiteself)
	{
		cout << "ҧ���Լ�����" << endl;
		return 0;
	}


	//�ж��Ƿ�Ե�ƻ��
	bool ifeat = IfBite_Fruit();
	if (!ifeat)
	{
		//���û�гԵ���ʵ -> �ͷ�β�ڵ� -> �����ƶ�
		Node* p = new Node;//����һ���ڵ㣬������ӡ
		p = this->snack->GetSnackHead();
		while (p->GetNodeNext()->GetNodeNext() != NULL)
		{
			gotoxy(p->GetX(), p->GetY());
			p->Printf_Node();
			p = p->GetNodeNext();
		}
		//���� p ָ������ĵ����ڶ����ڵ�
		//��ԭ��β�ڵ��ͼ�����ǵ�
		gotoxy(p->GetNodeNext()->GetX(), p->GetNodeNext()->GetY());
		cout << "  ";
		//�ͷ����һ���ڵ�
		delete p->GetNodeNext();
		p->SetNodeNext(NULL);
	}
	else
	{
		//����Ե���ʵ -> ���ͷ�β�ڵ� -> ����䳤
		Node* p = new Node;//����һ���ڵ㣬������ӡ
		p = this->snack->GetSnackHead();
		while (p->GetNodeNext()->GetNodeNext() != NULL)
		{
			gotoxy(p->GetX(), p->GetY());
			p->Printf_Node();
			p = p->GetNodeNext();
		}
		gotoxy(p->GetNodeNext()->GetX(), p->GetNodeNext()->GetY());

		//�ӷ�
		this->score += 10;
		//�ٴ���һ����ʵ
		this->Create_Fruit();

	}

}

//�����ƶ�
int SnackGame::Move_Right()
{
	//����һ���½ڵ㣬ָ�������С��Ҫȥ��λ��
	Node* newnode = new Node;
	newnode->SetX(this->snack->GetSnackHead()->GetX() + 2);
	newnode->SetY(this->snack->GetSnackHead()->GetY());
	newnode->SetNodeNext(this->snack->GetSnackHead());
	this->snack->SetSnackHead(newnode);

	//�ж��Ƿ�ײǽ
	bool ifhitwall = this->IfHitWall();
	if (ifhitwall)
	{
		cout << "һ��С��ײǽ����" << endl;
		return 0;
	}

	//�ж��Ƿ�ҧ���Լ�
	bool ifbiteself = this->snack->IfBite_Self();
	if (ifbiteself)
	{
		cout << "ҧ���Լ�����" << endl;
		return 0;
	}

	//�ж��Ƿ�Ե�ƻ��
	bool ifeat = IfBite_Fruit();
	if (!ifeat)
	{
		//���û�гԵ���ʵ -> �ͷ�β�ڵ� -> �����ƶ�
		Node* p = new Node;//����һ���ڵ㣬������ӡ
		p = this->snack->GetSnackHead();
		while (p->GetNodeNext()->GetNodeNext() != NULL)
		{
			gotoxy(p->GetX(), p->GetY());
			p->Printf_Node();
			p = p->GetNodeNext();
		}
		//���� p ָ������ĵ����ڶ����ڵ�
		//��ԭ��β�ڵ��ͼ�����ǵ�
		gotoxy(p->GetNodeNext()->GetX(), p->GetNodeNext()->GetY());
		cout << "  ";
		//�ͷ����һ���ڵ�
		delete p->GetNodeNext();
		p->SetNodeNext(NULL);
	}
	else
	{
		//����Ե���ʵ -> ���ͷ�β�ڵ� -> ����䳤
		Node* p = new Node;//����һ���ڵ㣬������ӡ
		p = this->snack->GetSnackHead();
		while (p->GetNodeNext()->GetNodeNext() != NULL)
		{
			gotoxy(p->GetX(), p->GetY());
			p->Printf_Node();
			p = p->GetNodeNext();
		}
		gotoxy(p->GetNodeNext()->GetX(), p->GetNodeNext()->GetY());

		//�ӷ�
		this->score += 10;
		//�ٴ���һ����ʵ
		this->Create_Fruit();

	}

}

//С���ƶ�����ײǽ��ҧ�Լ�ʱ���� 0��
int SnackGame::Move_Snack(char direction = Left)
{
	//char choice = _getch();//�������̰���
	char choice = direction;
	int ret = 0;//�����ķ���ֵ
	switch (choice)
	{
	case Up://��
		ret = Move_Up();
		break;
	case Down://��
		ret = Move_Down();
		break;
	case Left://��
		ret = Move_Left();
		break;
	case Right://��
		ret = Move_Right();
		break;
	default:
		break;
	}
	return ret;
}

//����С���ƶ�
void SnackGame::Control_Move()
{
	char Direction = Left;//��ʼ��С�������ƶ�
	int ret = 0;//�������ա�С���ƶ����ķ���ֵ

	while (true)
	{
		//GetAsyncKeyState���������жϵ���ʱָ����ټ���״̬
		if (GetAsyncKeyState(VK_UP) && Direction != Down)//����������ϣ�����ԭ�����ƶ��������£��������ƶ�
		{
			Direction = Up;
		}
		else if (GetAsyncKeyState(VK_DOWN) && Direction != Up)
		{
			Direction = Down;
		}
		else if (GetAsyncKeyState(VK_LEFT) && Direction != Right)
		{
			Direction = Left;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && Direction != Left)
		{
			Direction = Right;
		}
		
		//���⣺�����ײǽ��ҧ���Լ���ʱ��Ҫ�����ѭ����
		//�������ӷ���ֵ �������ж�
		//���շ���ֵ���ж�С���Ƿ��ƶ��쳣����Ϊ 0����ʾ�쳣���˳�ѭ��
		ret = this->Move_Snack(Direction);
		if (ret == 0)
		{
			break;
		}
		
		Sleep(300);
	}
}
