#include <stdio.h>
#include <iostream>
using namespace std;

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
	Text(int size, char* content=NULL, char* color=NULL);//含参的构造函数
	Text(Text& T);//拷贝构造函数
	void show();
	~Text();
};


class Rectangle: public Line //继承线框类
{
private:
	int length,width;//长，宽
	Text text;//文本类为其数据成员
	
public:
	Rectangle(int length,int width,int x,int y,int thick,char* color1,int size,char *content,char *color2);//构造函数
	Rectangle(int length,int width,int x,int y,int thick,char* color,Text T);//矩形类的构造函数，这里用到了text的深拷贝构造函数
	Rectangle(int length,int width,Line L,Text T);//矩形类的构造函数,用到基类Line的拷贝函数和text的深拷贝函数

	Rectangle(Rectangle& R);  //调用Text的拷贝构造函数
//以及对于继承类的拷贝构造函数：要在拷贝构造函数的初始化成员列表中调用基类的拷贝构造函数（该处用到了类型兼容）
	void show();
};


class ellipse: public Line //继承线框类
{
private:
	int radius;//半径
	Text text;//文本类为其数据成员
	
public:
	ellipse(int radius,int x,int y,int thick,char* color,Text T);
	ellipse(ellipse& E);
	void show();
};
