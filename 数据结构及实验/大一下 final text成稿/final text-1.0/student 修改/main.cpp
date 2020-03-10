#include "score.h"

int  EditFlag = 0;
char WorkingFileName[31] = "";//班级文件名
int  DataNum = 0;//指该班级文件下有i个学生

int main(void)
{
	STUDENT **pstu;//二维指针，用于记录文件中     （pstu->class->student）
	pstu = (STUDENT **)malloc(MAXNUM*sizeof(STUDENT *));
	if (!pstu) exit (-1);
	InitList(pstu,MAXNUM);//初始化，即让pstu所指的指针数组每一个都指空
	DoMainMenu(pstu);//主菜单显示及其相关操作(包括退出系统)
	FreeMemory(pstu,MAXNUM);//释放申请的指针
	getch();
	return 0;
}

2
//      1234      黄海涛  男 24   102  68.0  76.0  79.0
//      1235        钟洛  男 25   102  68.0  76.0  88.0


5
//      1234         liu  男 22   123  77.0  67.0  82.0
//      1235       zhang  女 21   123  82.0  68.0  73.0
//      1236        wang  男 25   123  65.0  82.0  81.0


7
//      1235       zhang  男 23   123  87.0  67.0  88.0
      1236        wang  男 24   123  85.0  76.0  90.0
      1002        sewi  男 24   211  88.0  67.0  89.0
      1234         liu  女 22   123  67.0  78.0  87.0
      2112        hong  女 23   211  78.0  77.0  90.0
      2113        hong  男 24   211  77.0  58.0  89.0
      1237        hong  男 22   211  78.0  82.0  89.0
      1001         hei  女 24   211  84.0  67.0  89.0
//
//
//
//
//
//
//
