#include "base.h"


#ifndef _onec_
#define _onec_

class Rectangle: public Line //继承线框类
{
private:
	int length,width;//长，宽
	Text text;//文本类为其数据成员
	
public:
	Rectangle();//空构造函数
	Rectangle(int length,int width,int x,int y,int thick,char* color1,int size,char *content,char *color2);//构造函数
	Rectangle(int length,int width,int x,int y,int thick,char* color,Text T);//矩形类的构造函数，这里用到了text的深拷贝构造函数
	Rectangle(int length,int width,Line L,Text T);//矩形类的构造函数,用到基类Line的拷贝函数和text的深拷贝函数

	Rectangle(Rectangle& R);  //调用Text的拷贝构造函数
//以及对于继承类的拷贝构造函数：要在拷贝构造函数的初始化成员列表中调用基类的拷贝构造函数（该处用到了类型兼容）
	void show();

	friend class CPPage;//将CPPage设为矩形的友元类，即CPPage中的成员函数都可以访问矩形的任何成员
};


class ellipse: public Line //继承线框类
{
private:
	int radius;//半径
	Text text;//文本类为其数据成员
	
public:
	ellipse();
	ellipse(int radius,int x,int y,int thick,char* color1,int size,char *content,char *color2);//构造函数
	ellipse(int radius,int x,int y,int thick,char* color,Text T);
	ellipse(int radius,Line L,Text T);
	ellipse(ellipse& E);
	void show();

	friend class CPPage;
};

#endif 