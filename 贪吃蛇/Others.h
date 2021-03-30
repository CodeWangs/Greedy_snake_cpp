#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

#define map_Width 40
#define map_Height 30


//控制光标的位置
void gotoxy(int x, int y);

//移动加速
void SpeedUp();

//隐藏控制台光标
void Hide_cursor();