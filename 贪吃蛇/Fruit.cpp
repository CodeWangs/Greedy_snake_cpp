#include "fruit.h"

Fruit::Fruit(int x, int y)
{
	this->f_x = x;
	this->f_y = y;
	this->f_data = "��";
}

Fruit::Fruit()
{
	//�����������ӣ����õ�ǰϵͳʱ���������������ֹÿ�����������ͬ
	srand((unsigned int)time(NULL));//time��Ҫͷ�ļ�

	//���⣺x����Ҫ��ż������Ϊ������ϵ�� y = 2*x �����������x�������Ļ��������жϳ������Ƿ�Ե���ʵ��
	/*
		map_Width = 40
		
		Ŀ�ģ�0-38	������
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
	this->f_data = "��";
}

Fruit::~Fruit()
{

}

//���ù�ʵX����
void Fruit::SetfX(int x)
{
	this->f_x = x;
}

//��ȡ��ʵX����
int Fruit::GetfX()
{
	return this->f_x;
}

//���ù�ʵY����
void Fruit::SetfY(int y)
{
	this->f_y = y;
}

//��ȡ��ʵY����
int Fruit::GetfY()
{
	return this->f_y;
}

//��ӡ��ʵ���ַ�
void Fruit::Printf_Fruit()
{
	cout << this->f_data;
	//cout << "1" << endl;
}

