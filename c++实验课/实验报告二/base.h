#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

#ifndef _onec 
#define _onec //防止因头文件被重复包含而造成类被重复定义的解决办法！


class CGraph //图形抽象类(虚基类)
{
private:
	char color[10];
	double thick;//线条粗细
	int type; //解释图形类型，为文件读取做准备

public:
	CGraph(int type=-1, double thick=1, char *color=NULL);//构造函数
	CGraph(CGraph& G);
	virtual void show()=0;//虚函数,提供接口
	virtual double area()=0;//返回图形面积

	friend class Rectangle;
	friend class ellipse;//设为友元类，方便访问数据成员
	friend class CRoundRect;
	friend class CPPage;
};

#endif 