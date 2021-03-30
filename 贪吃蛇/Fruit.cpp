#include "fruit.h"

Fruit::Fruit(int x, int y)
{
	this->f_x = x;
	this->f_y = y;
	this->f_data = "●";
}

Fruit::Fruit()
{
	//添加随机数种子，利用当前系统时间生成随机数，防止每次随机数都相同
	srand((unsigned int)time(NULL));//time需要头文件

	//问题：x坐标要是偶数，因为在坐标系中 y = 2*x ，如果产生的x是奇数的话，不能判断出“蛇是否吃到果实”
	/*
		map_Width = 40
		
		目的：0-38	分析：
		2-38	
		1-19	rand() % (map_Width - 3)/2 + 1
		0-18	rand() % (map_Width - 3)/2
		0-36	rand() % (map_Width - 3)
	*/
	int z = rand() % (map_Width - 3) / 2 + 1;
	int x = 2 * z;
	//int x = rand() % (map_Width - 4) + 2;
	int y = rand() % (map_Height - 4) + 2;
	
	this->f_x = x;
	this->f_y = y;

	//this->f_x = 0;
	//this->f_y = 0;
	this->f_data = "●";
}

Fruit::~Fruit()
{

}

//设置果实X坐标
void Fruit::SetfX(int x)
{
	this->f_x = x;
}

//获取果实X坐标
int Fruit::GetfX()
{
	return this->f_x;
}

//设置果实Y坐标
void Fruit::SetfY(int y)
{
	this->f_y = y;
}

//获取果实Y坐标
int Fruit::GetfY()
{
	return this->f_y;
}

//打印果实的字符
void Fruit::Printf_Fruit()
{
	cout << this->f_data;
	//cout << "1" << endl;
}

