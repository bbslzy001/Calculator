#include "Constant.h"
#include "Function.h"
#include "Setting.h"

extern void (*pt[kNum])(void);
extern bool exit_flag;

int main(void)
{
	Initialize();
	while (true)
	{
		MainInterface();
		(*(pt[SelectFunction()]))();
		if (exit_flag) break;
		Wait();
	}
	return 0;
}