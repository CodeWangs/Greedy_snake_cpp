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

//设置小蛇
void SnackGame::SetSnack(Snack* snack)
{
	this->snack = snack;
}

//获取小蛇
Snack* SnackGame::GetSnack()
{
	return this->snack;
}

//设置果实
void SnackGame::SetFruit(Fruit* fruit)
{
	this->fruit = fruit;
}

//获取果实
Fruit* SnackGame::GetFruit()
{
	return this->fruit;
}

//设置分数
void SnackGame::SetScore(int score)
{
	this->score = score;
}

//获取分数
int SnackGame::GetScore()
{
	return this->score;
}


//开始游戏界面
void SnackGame::BegainGame()
{
	cout << "欢迎来到贪吃蛇大作战！！！" << endl;
	cout << "1  -->  开始游戏" << endl;
	cout << "2  -->  结束游戏" << endl;
	cout << "请选择：";
}

//结束游戏界面
void SnackGame::EndGame()
{
	cout << "游戏结束！！！" << endl;
}

//创建地图
void SnackGame::Create_Map()
{
	gotoxy(0, 0);
	for (int i = 0; i < map_Width; i++)
	{
		cout << "■";
	}
	cout << endl;
	for (int i = 0; i < (map_Height - 2); i++)
	{
		for (int j = 0; j < map_Width; j++)
		{
			if (j == 0 || j == (map_Width - 1))
			{
				cout << "■";
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
		cout << "■";
	}
	cout << endl;

}

//初始化一条小蛇
void SnackGame::Create_Snack()
{
	Node* Phead = new Node;//创建一个指向头节点的指针
	Snack* snack = new Snack;//创建一条小蛇
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
	//cout << "测试代码" << endl;

}

//创建果实
void SnackGame::Create_Fruit()
{
	////创建一个果实
	////Fruit* newFruit = new Fruit;
	//this->fruit = new Fruit;
	////添加随机数种子，利用当前系统时间生成随机数，防止每次随机数都相同
	//srand((unsigned int)time(NULL));//time需要头文件
	//int x = rand() % (map_Width - 4) + 2;
	//int y = rand() % (map_Height - 4) + 2;
	//gotoxy(x, y);
	////newFruit->Printf_Fruit();
	//this->fruit->Printf_Fruit();
	////问题：遗漏了要把果实的坐标也设置成产生的随机数
	////newFruit->SetfX(x);
	////newFruit->SetfY(y);
	//this->fruit->SetfX(x);
	//this->fruit->SetfY(y);
	
	//问题：在默认构造函数中，已经给this->fruit开辟空间了，问什么在这里还需要开辟空间？ 不开辟空间就不会再重新创建一个果实
	this->fruit = new Fruit;
	
	//随机产生的果实，可能在小蛇的“身上”，需要加以判断，出现这种情况则重新创建果实
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
	//此处不能释放 this->fruit 的空间，为什么？因为在析构函数中释放了？
}

//判断蛇是否撞墙
bool SnackGame::IfHitWall()
{
	if (this->snack->GetSnackHead()->GetX() == 0 || this->snack->GetSnackHead()->GetX() == (map_Width-1)*2
		|| this->snack->GetSnackHead()->GetY() == 0 || this->snack->GetSnackHead()->GetY() == map_Height-1)
	{
		return true;
	}

	return false;
}

//是否吃到水果
bool SnackGame::IfBite_Fruit()
{
	if (this->snack->GetSnackHead()->GetX() == this->fruit->GetfX() 
		&& this->snack->GetSnackHead()->GetY() == this->fruit->GetfY())
	{
		return true;
	}
	return false;
}


//小蛇移动
//向上移动（当撞墙或咬自己时返回 0）
int SnackGame::Move_Up()
{
	//创建一个新节点，指向接下来小蛇要去的位置
	Node* newnode = new Node(this->snack->GetSnackHead()->GetX(), this->snack->GetSnackHead()->GetY() - 1);
	newnode->SetNodeNext(this->snack->GetSnackHead());

	this->snack->SetSnackHead(newnode);

	//判断是否撞墙
	bool ifhitwall = this->IfHitWall();
	if (ifhitwall)
	{
		cout << "一不小心撞墙啦！" << endl;
		return 0;
	}

	//判断是否咬到自己
	bool ifbiteself = this->snack->IfBite_Self();
	if (ifbiteself)
	{
		cout << "咬到自己啦！" << endl;
		return 0;
	}

	//判断是否吃到苹果
	bool ifeat = IfBite_Fruit();
	if (!ifeat)
	{
		//如果没有吃到果实 -> 释放尾节点 -> 正常移动
		Node* p = new Node;//创建一个节点，遍历打印
		p = this->snack->GetSnackHead();
		while (p->GetNodeNext()->GetNodeNext() != NULL)
		{
			gotoxy(p->GetX(), p->GetY());
			p->Printf_Node();
			p = p->GetNodeNext();
		}
		//现在 p 指向蛇身的倒数第二个节点
		//将原来尾节点的图案覆盖掉
		gotoxy(p->GetNodeNext()->GetX(), p->GetNodeNext()->GetY());
		//gotoxy(p->GetX(), p->GetY());
		cout << "  ";

		//释放最后一个节点
		delete p->GetNodeNext();
		p->SetNodeNext(NULL);
	}
	else
	{
		//如果吃到果实 -> 不释放尾节点 -> 蛇身变长
		Node* p = new Node;//创建一个节点，遍历打印
		p = this->snack->GetSnackHead();
		while (p->GetNodeNext() != NULL)
		{
			gotoxy(p->GetX(), p->GetY());
			p->Printf_Node();
			p = p->GetNodeNext();
		}
		//现在 p 指向蛇身的倒数第二个节点
		//将原来尾节点的图案覆盖掉
		//gotoxy(p->GetNodeNext()->GetX(), p->GetNodeNext()->GetY());
		//gotoxy(p->GetX(), p->GetY());
		//cout << "  ";

		//释放最后一个节点
		//delete p->GetNodeNext();
		//p->SetNodeNext(NULL);

		//加分
		this->score += 10;
		//再创建一个果实
		this->Create_Fruit();
	}
}

//向下移动
int SnackGame::Move_Down()
{
	//创建一个新节点，指向接下来小蛇要去的位置
	Node* newnode = new Node;
	newnode->SetX(this->snack->GetSnackHead()->GetX());
	newnode->SetY(this->snack->GetSnackHead()->GetY() + 1);
	newnode->SetNodeNext(this->snack->GetSnackHead());
	this->snack->SetSnackHead(newnode);

	//判断是否撞墙
	bool ifhitwall = this->IfHitWall();
	if (ifhitwall)
	{
		cout << "一不小心撞墙啦！" << endl;
		return 0;
	}

	//判断是否咬到自己
	bool ifbiteself = this->snack->IfBite_Self();
	if (ifbiteself)
	{
		cout << "咬到自己啦！" << endl;
		return 0;
	}
	
	//判断是否吃到苹果
	bool ifeat = IfBite_Fruit();
	if (!ifeat)
	{
		//如果没有吃到果实 -> 释放尾节点 -> 正常移动
		Node* p = new Node;//创建一个节点，遍历打印
		p = this->snack->GetSnackHead();
		while (p->GetNodeNext()->GetNodeNext() != NULL)
		{
			gotoxy(p->GetX(), p->GetY());
			p->Printf_Node();
			p = p->GetNodeNext();
		}
		//现在 p 指向蛇身的倒数第二个节点
		//将原来尾节点的图案覆盖掉
		gotoxy(p->GetNodeNext()->GetX(), p->GetNodeNext()->GetY());
		cout << "  ";
		//释放最后一个节点
		delete p->GetNodeNext();
		p->SetNodeNext(NULL);
	}
	else
	{
		//如果吃到果实 -> 不释放尾节点 -> 蛇身变长
		Node* p = new Node;//创建一个节点，遍历打印
		p = this->snack->GetSnackHead();
		while (p->GetNodeNext()->GetNodeNext() != NULL)
		{
			gotoxy(p->GetX(), p->GetY());
			p->Printf_Node();
			p = p->GetNodeNext();
		}
		gotoxy(p->GetNodeNext()->GetX(), p->GetNodeNext()->GetY());

		//加分
		this->score += 10;
		//再创建一个果实
		this->Create_Fruit();

	}

}

//向左移动
int SnackGame::Move_Left()
{
	//创建一个新节点，指向接下来小蛇要去的位置
	Node* newnode = new Node;
	newnode->SetX(this->snack->GetSnackHead()->GetX() - 2);
	newnode->SetY(this->snack->GetSnackHead()->GetY());
	newnode->SetNodeNext(this->snack->GetSnackHead());
	this->snack->SetSnackHead(newnode);

	//判断是否撞墙
	bool ifhitwall = this->IfHitWall();
	if (ifhitwall)
	{
		cout << "一不小心撞墙啦！" << endl;
		return 0;
	}

	//判断是否咬到自己
	bool ifbiteself = this->snack->IfBite_Self();
	if (ifbiteself)
	{
		cout << "咬到自己啦！" << endl;
		return 0;
	}


	//判断是否吃到苹果
	bool ifeat = IfBite_Fruit();
	if (!ifeat)
	{
		//如果没有吃到果实 -> 释放尾节点 -> 正常移动
		Node* p = new Node;//创建一个节点，遍历打印
		p = this->snack->GetSnackHead();
		while (p->GetNodeNext()->GetNodeNext() != NULL)
		{
			gotoxy(p->GetX(), p->GetY());
			p->Printf_Node();
			p = p->GetNodeNext();
		}
		//现在 p 指向蛇身的倒数第二个节点
		//将原来尾节点的图案覆盖掉
		gotoxy(p->GetNodeNext()->GetX(), p->GetNodeNext()->GetY());
		cout << "  ";
		//释放最后一个节点
		delete p->GetNodeNext();
		p->SetNodeNext(NULL);
	}
	else
	{
		//如果吃到果实 -> 不释放尾节点 -> 蛇身变长
		Node* p = new Node;//创建一个节点，遍历打印
		p = this->snack->GetSnackHead();
		while (p->GetNodeNext()->GetNodeNext() != NULL)
		{
			gotoxy(p->GetX(), p->GetY());
			p->Printf_Node();
			p = p->GetNodeNext();
		}
		gotoxy(p->GetNodeNext()->GetX(), p->GetNodeNext()->GetY());

		//加分
		this->score += 10;
		//再创建一个果实
		this->Create_Fruit();

	}

}

//向右移动
int SnackGame::Move_Right()
{
	//创建一个新节点，指向接下来小蛇要去的位置
	Node* newnode = new Node;
	newnode->SetX(this->snack->GetSnackHead()->GetX() + 2);
	newnode->SetY(this->snack->GetSnackHead()->GetY());
	newnode->SetNodeNext(this->snack->GetSnackHead());
	this->snack->SetSnackHead(newnode);

	//判断是否撞墙
	bool ifhitwall = this->IfHitWall();
	if (ifhitwall)
	{
		cout << "一不小心撞墙啦！" << endl;
		return 0;
	}

	//判断是否咬到自己
	bool ifbiteself = this->snack->IfBite_Self();
	if (ifbiteself)
	{
		cout << "咬到自己啦！" << endl;
		return 0;
	}

	//判断是否吃到苹果
	bool ifeat = IfBite_Fruit();
	if (!ifeat)
	{
		//如果没有吃到果实 -> 释放尾节点 -> 正常移动
		Node* p = new Node;//创建一个节点，遍历打印
		p = this->snack->GetSnackHead();
		while (p->GetNodeNext()->GetNodeNext() != NULL)
		{
			gotoxy(p->GetX(), p->GetY());
			p->Printf_Node();
			p = p->GetNodeNext();
		}
		//现在 p 指向蛇身的倒数第二个节点
		//将原来尾节点的图案覆盖掉
		gotoxy(p->GetNodeNext()->GetX(), p->GetNodeNext()->GetY());
		cout << "  ";
		//释放最后一个节点
		delete p->GetNodeNext();
		p->SetNodeNext(NULL);
	}
	else
	{
		//如果吃到果实 -> 不释放尾节点 -> 蛇身变长
		Node* p = new Node;//创建一个节点，遍历打印
		p = this->snack->GetSnackHead();
		while (p->GetNodeNext()->GetNodeNext() != NULL)
		{
			gotoxy(p->GetX(), p->GetY());
			p->Printf_Node();
			p = p->GetNodeNext();
		}
		gotoxy(p->GetNodeNext()->GetX(), p->GetNodeNext()->GetY());

		//加分
		this->score += 10;
		//再创建一个果实
		this->Create_Fruit();

	}

}

//小蛇移动（当撞墙或咬自己时返回 0）
int SnackGame::Move_Snack(char direction = Left)
{
	//char choice = _getch();//监听键盘按键
	char choice = direction;
	int ret = 0;//函数的返回值
	switch (choice)
	{
	case Up://上
		ret = Move_Up();
		break;
	case Down://下
		ret = Move_Down();
		break;
	case Left://左
		ret = Move_Left();
		break;
	case Right://右
		ret = Move_Right();
		break;
	default:
		break;
	}
	return ret;
}

//控制小蛇移动
void SnackGame::Control_Move()
{
	char Direction = Left;//初始化小蛇向左移动
	int ret = 0;//用来接收“小蛇移动”的返回值

	while (true)
	{
		//GetAsyncKeyState函数用来判断调用时指定虚假键的状态
		if (GetAsyncKeyState(VK_UP) && Direction != Down)//如果按得是上，并且原来的移动方向不是下，则向上移动
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
		
		//问题：如何在撞墙或咬到自己的时候，要出这个循环？
		//给函数加返回值 并进行判断
		//接收返回值，判断小蛇是否移动异常，若为 0，表示异常，退出循环
		ret = this->Move_Snack(Direction);
		if (ret == 0)
		{
			break;
		}
		
		Sleep(300);
	}
}
