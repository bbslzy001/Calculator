#include "Constant.h"
#include "Function.h"

#include <iostream>
#include <conio.h>
#include <tuple>
#include <cstdio>

using namespace std;

//函数指针，指向各个功能
void (*pt[kNum])(void) =
{
	Add, Subtract, Multify, Divide, Digit, Circle,
	LeapYear, Grade,
	OddNumber, EvenNumber, MultipleOfThree, DividedByThreeAndFive, Narcissus,
	Max, MaxAndMin
};

//结束程序判断
bool exit_flag = false;

void Wait(void)
{
	cin.clear();
	cout << endl << "按任何键返回主界面" << endl;
	ignore = _getch();
	return;
}

void Add(void)
{
	int a, b;
	scanf_s("%d%d", &a, &b);
	int res = a + b;
	printf("加法结果的十进制是：%d\n", res);
	printf("加法结果的八进制是：%o\n", res);
	printf("加法结果的十六进制是：%x\n", res);
	return;
}

void Subtract(void)
{
	int a, b;
	scanf_s("%d%d", &a, &b);
	int res = a - b;
	printf("减法结果的十进制是：%d\n", res);
	printf("减法结果的八进制是：%o\n", res);
	printf("减法结果的十六进制是：%x\n", res);
	return;
}

void Multify(void)
{
	float a, b;
	scanf_s("%f%f", &a, &b);
	float res = a * b;
	printf("乘法结果的小数形式是：%f\n", res);
	printf("乘法结果的指数形式是：%e\n", res);
	return;
}

void Divide(void)
{
	float a, b;
	scanf_s("%f%f", &a, &b);
	if (b == (float)0)
	{
		printf("除数为0，无法进行除法运算\n");
		return;
	}
	float res = a / b;
	printf("除法结果的小数形式是：%f\n", res);
	printf("除法结果的指数形式是：%e\n", res);
	return;
}

void Digit(void)
{
	int a;
	scanf_s("%d", &a);
	if (a <= 0)
	{
		printf("要求输入的数为正数\n");
		return;
	}
	if (a > 999)
	{
		printf("要求输入的数为3位以内的正整数\n");
		return;
	}
	int hundreds = a / 100;
	int tens = a % 100 / 10;
	int ones = a % 10;
	int digit = 3;
	if (!hundreds) --digit;
	if (!tens) --digit;
	printf("该数为%d位数，百位是%d，十位是%d，个位是%d\n", digit, hundreds, tens, ones);
	return;
}

void Circle(void)
{
	double r;
	scanf_s("%lf", &r);
	double res = kPI * r * r;
	printf("该圆面积是：%lf\n", res);
	printf("该圆面积保留两位小数的结果是：%.2lf\n", res);
	return;
}

void LeapYear(void)
{
	int year;
	scanf_s("%d", &year);
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		printf("%d是闰年\n", year);
	}
	else
	{
		printf("%d是平年\n", year);
	}
	return;
}

void Grade(void)
{
	int grade;
	cin >> grade;
	if (grade < 0 || grade>100)
	{
		cout << "成绩输入错误" << endl;
		return;
	}
	switch (grade / 10)
	{
	case 10:
	case 9:
		cout << "优秀" << endl; break;
	case 8:
		cout << "良" << endl; break;
	case 7:
		cout << "中" << endl; break;
	case 6:
		cout << "及格" << endl; break;
	default:
		cout << "不及格" << endl;
	}
	return;
}

void OddNumber(void)
{
	int num;
	cin >> num;
	int sum = 0;
	for (int i = 1; i <= num; i += 2)
	{
		sum += i;
	}
	cout << "从 1 到 " << num << " 之间的奇数和为：" << sum << endl;
	return;
}

void EvenNumber(void)
{
	int num;
	cin >> num;
	int sum = 0;
	int i = 0;
	while (i <= num)
	{
		sum += i;
		i += 2;
	}
	cout << "从 1 到 " << num << " 之间的偶数和为：" << sum << endl;
	return;
}

void MultipleOfThree(void)
{
	int num;
	cin >> num;
	int i = 3;
	cout << "从 1 到 " << num << " 之间所有3的倍数为：" << endl;
	if (num >= 3)
	{
		do
		{
			cout << i << endl;
		} while ((i += 3) <= num);
	}
	else
	{
		cout << "无" << endl;
	}
	return;
}

void DividedByThreeAndFive(void)
{

}

void Narcissus(void)
{

}

void Max(void)
{

}

void MaxAndMin(void)
{

}