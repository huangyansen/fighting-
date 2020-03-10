#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#ifndef _onec 
#define _onec //防止因头文件被重复包含而造成类被重复定义的解决办法！！！！

class Line//线框
{
private:
	int x,y;//参考点，对于矩形来说是左上角的点，对于圆来说是圆心
	int thick;//粗细
	char color[10];//颜色

public:
	Line(int x=0,int y=0,int thick=0.1,char* color=NULL);//含参的构造函数
	void show();
};


class Text//文本
{
private:
	int size;//大小
	char* content;//内容，需要动态分配
	char color[10];//颜色

public:
	Text();
	Text(int size, char* content=NULL, char* color=NULL);//含参的构造函数
	Text(Text& T);//拷贝构造函数
	void show();
	~Text();
	friend class Rectangle;
	friend class CPPage;
};

#endif 