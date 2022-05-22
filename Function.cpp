#include "Constant.h"
#include "Function.h"

#include <iostream>
#include <conio.h>
#include <tuple>
#include <cstdio>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

//各个功能
void (*pt[kNum])(void) =
{
	Add, Subtract, Multify, Divide, Digit, Circle,
	LeapYear, Grade,
	OddNumber, EvenNumber, MultipleOfThree, DividedByThreeAndFive, Narcissus,
	Max, MaxAndMin,
	Sort, Matrix, Diagonal, CountWords,
	StaticList, DynamicList, SortByGrade, AddGrade,
	Exit
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
	int value1, value2;
	cout << "请输入两个数：";
	scanf_s("%d%d", &value1, &value2);
	int result = value1 + value2;
	printf("加法结果的十进制是：%d\n", result);
	printf("加法结果的八进制是：%o\n", result);
	printf("加法结果的十六进制是：%x\n", result);
	return;
}

void Subtract(void)
{
	int value1, value2;
	cout << "请输入两个数：";
	scanf_s("%d%d", &value1, &value2);
	int result = value1 - value2;
	printf("减法结果的十进制是：%d\n", result);
	printf("减法结果的八进制是：%o\n", result);
	printf("减法结果的十六进制是：%x\n", result);
	return;
}

void Multify(void)
{
	float value1, value2;
	cout << "请输入两个数：";
	scanf_s("%f%f", &value1, &value2);
	float result = value1 * value2;
	printf("乘法结果的小数形式是：%f\n", result);
	printf("乘法结果的指数形式是：%e\n", result);
	return;
}

void Divide(void)
{
	float value1, value2;
	cout << "请输入两个数：";
	scanf_s("%f%f", &value1, &value2);
	if (value2 == (float)0)
	{
		printf("除数为0，无法进行除法运算\n");
		return;
	}
	float result = value1 / value2;
	printf("除法结果的小数形式是：%f\n", result);
	printf("除法结果的指数形式是：%e\n", result);
	return;
}

void Digit(void)
{
	int value;
	cout << "请输入一个3位以内的正整数：";
	scanf_s("%d", &value);
	if (value <= 0)
	{
		printf("要求输入的数为正数\n");
		return;
	}
	if (value > 999)
	{
		printf("要求输入的数为3位以内的正整数\n");
		return;
	}
	int hundreds = value / 100;
	int tens = value % 100 / 10;
	int ones = value % 10;
	int digit = 3;
	if (!hundreds) --digit;
	if (!tens) --digit;
	printf("该数为%d位数，百位是%d，十位是%d，个位是%d\n", digit, hundreds, tens, ones);
	return;
}

void Circle(void)
{
	double radius;
	cout << "请输入圆的半径：";
	scanf_s("%lf", &radius);
	double result = kPI * radius * radius;
	printf("该圆面积是：%lf\n", result);
	printf("该圆面积保留两位小数的结果是：%.2lf\n", result);
	return;
}

void LeapYear(void)
{
	int year;
	cout << "请输入年份：";
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
	cout << "请输入成绩：";
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
	cout << "请输入一个数：";
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
	cout << "请输入一个数：";
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
	cout << "请输入一个数：";
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
	int value1, value2;
	cout << "请输入两个数：";
	cin >> value1 >> value2;
	for (int i = value1; i <= value2; ++i)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			cout << i << endl;
			return;
		}
	}
	cout << value1 << "和" << value2 << "之间不存在既可以被3整除又可以被5整除的数" << endl;
	return;
}

void Narcissus(void)
{
	cout << "水仙花数：" << endl;
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < 10; ++k)
			{
				int sum = 100 * i + 10 * j + k;
				if (i * i * i + j * j * j + k * k * k == sum)
				{
					cout << sum << endl;
				}
			}
		}
	}
	return;
}

int MaxSolution(int value1, int value2)
{
	return value1 >= value2 ? value1 : value2;
}

void Max(void)
{
	int value1, value2;
	cout << "请输入两个数：";
	cin >> value1 >> value2;
	cout << MaxSolution(value1, value2) << endl;
	return;
}

void MaxAndMinSolution(int* value1, int* value2)
{
	if (*value1 < *value2)
	{
		int temp = *value1;
		*value1 = *value2;
		*value2 = temp;
	}
	return;
}

void MaxAndMin(void)
{
	int value1, value2;
	cout << "请输入两个数：";
	cin >> value1 >> value2;
	MaxAndMinSolution(&value1, &value2);
	cout << "最大值：" << value1 << endl;
	cout << "最小值：" << value2 << endl;
	return;
}

void Sort(void)
{
	int arr[kCount] = {};
	cout << "请输入" << kCount << "个数：" << endl;
	for (int i = 0; i < kCount; ++i)
	{
		cin >> arr[i];
	}
	int* point = new int[kCount]();
	for (int i = 0; i < kCount - 1; ++i)
	{
		for (int j = i + 1; j < kCount; ++j)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < kCount; ++i)
	{
		point[i] = arr[i];
	}
	cout << "从小到大顺序为：" << endl;
	for (int i = 0; i < kCount; ++i)
	{
		cout << point[i] << " ";
	}
	delete[] point;
	cout << endl;
	return;
}

void Matrix(void)
{
	int arr[kRow][kColumn] = {};
	cout << "请输入一个" << kRow << "×" << kColumn << "的矩阵：" << endl;
	for (int i = 0; i < kRow; ++i)
	{
		for (int j = 0; j < kColumn; ++j)
		{
			cin >> arr[i][j];
		}
	}
	cout << "转置矩阵为：" << endl;
	for (int j = 0; j < kColumn; ++j)
	{
		for (int i = 0; i < kRow; ++i)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

void Diagonal(void)
{
	int arr[kOrderMatrix][kOrderMatrix] = {};
	cout << "请输入一个" << kOrderMatrix << "阶矩阵：" << endl;
	for (int i = 0; i < kOrderMatrix; ++i)
	{
		for (int j = 0; j < kOrderMatrix; ++j)
		{
			cin >> arr[i][j];
		}
	}
	int sum = 0;
	for (int i = 0; i < kOrderMatrix; ++i)
	{
		sum += arr[i][i];
	}
	cout << "主对角线的和为：" << sum << endl;
	return;
}

void CountWords(void)
{
	string str;
	cout << "请输入一行单词：" << endl;
	getline(cin, str);
	int length = (int)str.size();
	int count = 1;
	for (int i = 0; i <= length; ++i)
	{
		if (str[i] == ' ') ++count;
	}
	cout << "这样共有" << count << "个单词" << endl;
	return;
}

void StaticList(void)
{
	struct List
	{
		int value = 0;
		List* next = nullptr;
	};
	List list[kListCount] = {};
	for (int i = 0; i < kListCount; ++i)
	{
		list[i].value = i + 1;
		if (i != kListCount - 1)
		{
			list[i].next = &list[i + 1];
		}
	}
	for (int i = 0; i < kListCount; ++i)
	{
		cout << "第" << i + 1 << "个元素：";
		cout << list[i].value << " ";
		cout << list[i].next << endl;
	}
	return;
}

void DynamicList(void)
{
	struct List
	{
		int value = 0;
		List* next = nullptr;
	};
	//设置头节点和尾节点
	List* head = new List;
	List* tail = new List;
	//将头节点指向尾节点
	head = tail;
	cout << "输入一串正整数，以负数作为结束：" << endl;
	while (true)
	{
		int value;
		cin >> value;
		if (value < 0) break;
		//创建新节点
		List* node = new List;
		//为新节点的 vlaue 赋值
		node->value = value;
		//使当前尾节点的 next 指向新节点
		tail->next = node;
		//更新尾节点，将新节点作为为节点
		tail = node;
	}
	for (List* node = head->next; node != nullptr; node = node->next)
	{
		cout << node->value << " ";
	}
	return;
}

void SortByGrade(void)
{
	struct Student
	{
		int no = 0;
		string name = "";
		int grade = 0;
	};
	Student students[kStudentNum];
	for (int i = 0; i < kStudentNum; ++i)
	{
		cin >> students[i].no;
		cin.get();
		cin >> students[i].name;
		cin >> students[i].grade;
	}
	for (int i = 0; i < kStudentNum - 1; ++i)
	{
		for (int j = i + 1; j < kStudentNum; ++j)
		{
			if (students[i].grade > students[j].grade)
			{
				Student temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < kStudentNum; ++i)
	{
		sum += students[i].grade;
	}
	double average = sum / kStudentNum;
	for (int i = 0; i < kStudentNum; ++i)
	{
		cout << "第" << i + 1 << "名学生的信息为：";
		cout << students[i].no << " " << students[i].name << " " << students[i].grade << endl;
	}
	cout << "全体学生总成绩为：" << sum << endl;
	cout << "全体学生平均成绩为：" << average << endl;
	return;
}

void AddGrade(void)
{
	//定义文件输入输出对象
	ifstream inFile;
	ofstream outFile;

	//读取文件信息
	inFile.open(kFileName);
	if (!inFile.is_open())
	{
		cout << "无法打开" << kFileName << "文件" << endl;
		exit(EXIT_FAILURE);
	}
	vector<int> arr;
	for (int i = 0; inFile.good(); ++i)
	{
		int temp;
		inFile >> temp;
		arr.push_back(temp);
	}
	if (inFile.eof())
	{
		cout << "文件读取成功" << endl;
	}
	else if (inFile.fail())
	{
		cout << "由于文件数据不匹配，文件读取意外终止" << endl;
	}
	else
	{
		cout << "由于某个未知原因，文件读取意外终止" << endl;
	}
	inFile.close();

	//执行加10操作
	for (auto it = arr.begin(); it != arr.end(); ++it)
	{
		*it += 10;
	}

	//写入文件信息
	outFile.open(kFileName);
	for (auto it = arr.begin(); it != arr.end(); ++it)
	{
		outFile << *it << " ";
	}
	outFile.close();

	return;
}

void Exit(void)
{
	exit_flag = true;
	return;
}