#include "base.h"
#include "derived.h"

Rectangle::Rectangle(){}

Rectangle::Rectangle(int length,int width,int x,int y,int thick,char* color1,int size,char *content,char *color2)
			:Line(x,y,thick,color1),text(size,content,color2)
{
		this->length=length;
		this->width=width;
}


Rectangle::Rectangle(int length,int width,int x,int y,int thick,char* color,Text T) 
: text(T),Line(x,y,thick,color)
//这里用到了text的深拷贝构造函数
{
		this->length=length;
		this->width=width;
}

Rectangle::Rectangle(int length,int width,Line L,Text T): text(T),Line(L)
{
		this->length=length;
		this->width=width;
}

Rectangle::Rectangle(Rectangle& R): text(R.text),Line(R)  //调用Text的拷贝构造函数
{//以及对于继承类的拷贝构造函数：要在拷贝构造函数的初始化成员列表中调用基类的拷贝构造函数
										
		this->length=R.length;
		this->width=R.width;
}

void Rectangle::show()
{
		cout<<"---------Rectangle---------\n";
		cout<<"The message of Rectangle:\n";
		cout<<"length is "<<length<<endl;
		cout<<"width is "<<width<<endl;
		Line::show();
		text.show();
		cout<<"---------------------------\n\n";
}


ellipse::ellipse(){}

ellipse::ellipse(int radius,int x,int y,int thick,char* color1,int size,char *content,char *color2) 
		:Line(x,y,thick,color1),text(size,content,color2)
{
		this->radius=radius;
}


ellipse::ellipse(int radius,int x,int y,int thick,char* color,Text T) : text(T),Line(x,y,thick,color)
{
		this->radius=radius;
}

ellipse::ellipse(int radius,Line L,Text T):Line(L),text(T)
{
		this->radius=radius;
}

ellipse::ellipse(ellipse& E): text(E.text),Line(E) 
{
		this->radius=E.radius;
}

void ellipse::show()
{
		cout<<"---------Ellipse---------\n";
		cout<<"The message of ellipse:\n";
		cout<<"radius is "<<radius<<endl;
		Line::show();
		text.show();
		cout<<"-------------------------\n\n";
}