#include "Constant.h"
#include "Setting.h"

#include <iostream>
#include <windows.h>  //用于窗口设置和光标设置
#include <cstdlib>  //用于sprintf、system
#include <conio.h>  //用于_getch()

using namespace std;

void SetWindowSize(void)
{
	char str[64];
	sprintf_s(str, "mode con cols=%d lines=%d", kWindowWidth, kWindowHeight);
	system(str);
	return;
}

void HideCursor(void)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);  //获取控制台光标信息
	CursorInfo.bVisible = false;  //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);  //设置控制台光标状态
	return;
}

void Initialize(void)
{
	SetWindowSize();
	HideCursor();
	return;
}

void MainInterface(void)
{
	HideCursor();
	system("cls");
	for (int i = 0; i < kNum + 7; ++i)
	{
		GotoXY(kInfoBoxX, kInfoBoxY + i);
		switch (i)
		{
		case 0:  cout << "**************************************************"; break;
		case 1:  cout << "*                                                *"; break;
		case 2:  cout << "*                 小 小 计 算 器                 *"; break;
		case 3:  cout << "*                                                *"; break;
		case 4:  cout << "**************************************************"; break;
		case 5:  cout << "* A）加法                                        *"; break;
		case 6:  cout << "* B）减法                                        *"; break;
		case 7:  cout << "* C）乘法                                        *"; break;
		case 8:  cout << "* D）除法                                        *"; break;
		case 9:  cout << "* E）判断数字的位数                              *"; break;
		case 10: cout << "* F）计算圆面积                                  *"; break;
		case 11: cout << "* G）判断闰年                                    *"; break;
		case 12: cout << "* H）成绩转换                                    *"; break;
		case 13: cout << "* I）计算从1到输入数之间的奇数和（for）          *"; break;
		case 14: cout << "* J）计算从1到输入数之间的偶数和（while)         *"; break;
		case 15: cout << "* K）输出从1到输入数之间所有3的倍数（do-while）  *"; break;
		case 16: cout << "* L）求既被3整除又被5整除的数                    *"; break;
		case 17: cout << "* M）求水仙花数                                  *"; break;
		case 18: cout << "* N）求最大值                                    *"; break;
		case 19: cout << "* O）求最大最小值                                *"; break;
		case 20: cout << "* P）冒泡排序                                    *"; break;
		case 21: cout << "* Q）矩阵转置                                    *"; break;
		case 22: cout << "* R）求对角线和                                  *"; break;
		case 23: cout << "* S）统计单词个数                                *"; break;
		case 24: cout << "* T）静态创建链表                                *"; break;
		case 25: cout << "* U）动态创建链表                                *"; break;
		case 26: cout << "* V）学生成绩排序                                *"; break;
		case 27: cout << "* W）学生成绩普涨10分                            *"; break;
		case 28: cout << "* X）退出                                        *"; break;
		case 29: cout << "**************************************************"; break;
		}
	}
	return;
}

int SelectFunction(void)
{
	char choice = ' ';
	while (true)
	{
		choice = _getch();
		if (choice != ' ') break;
	}
	DisplayCursor();
	system("cls");
	GotoXY(0, 0);
	int integer_choice = choice - 'A';
	if (integer_choice > 26) integer_choice -= 32;
	return integer_choice;
}

void GotoXY(int x, int y)
{
	COORD coordinate;
	coordinate.X = x; coordinate.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
	return;
}

void DisplayCursor(void)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);  //获取控制台光标信息
	CursorInfo.bVisible = true;  //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);  //设置控制台光标状态
	return;
}