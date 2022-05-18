#ifndef __SETTING_H__
#define __SETTING_H__


/*初始化*/
//设置窗口大小
void SetWindowSize(void);
//隐藏光标
void HideCursor(void);
//调用 SetWindowSize、HideCursor 函数，进行初始化
void Initialize(void);


/*打印主界面*/
void MainInterface(void);


/*选择功能*/
int SelectFunction(void);


/*运行所需*/
//移动光标到坐标（x, y）
void GotoXY(int x, int y);
//显示光标
void DisplayCursor(void);


#endif