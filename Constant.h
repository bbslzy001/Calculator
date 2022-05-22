#ifndef __CONSTANT_H__
#define __CONSTANT_H__

#include <string>

/*定义窗口大小*/
//窗口宽度
const int kWindowWidth = 100;
//窗口高度
const int kWindowHeight = 50;
//主界面信息左侧水平起始坐标
const int kInfoBoxX = kWindowWidth / 4;
//主界面信息上侧垂直起始坐标
const int kInfoBoxY = 10;


/*功能总数*/
const int kNum = 24;


/*各个函数中所用到的常量*/
//圆周率
const double kPI = 3.14;
//数组长度
const int kCount = 10;
//矩阵行
const int kRow = 3;
//矩阵列
const int kColumn = 4;
//矩阵阶数
const int kOrderMatrix = 3;
//链表长度
const int kListCount = 4;
//学生人数
const int kStudentNum = 10;
//文件名
const std::string kFileName = "my.txt";


#endif