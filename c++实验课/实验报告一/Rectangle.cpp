#include "Rectangle.h"

Rectangle::Rectangle(int length,int high,int x,int y,int thick,char* color,Text T) : text(T),Line(x,y,thick,color)//这里用到了text的深拷贝构造函数
{
		this->length=length;
		this->high=high;
}

Rectangle::Rectangle(Rectangle& R)//从无到有的拷贝，一定要写空的Text构造函数，因为在调用拷贝构造函数，创建对象时没有给出初始化的参数
{
		this->length=R.length;
		this->high=R.high;
		this->text=R.text;
}

void Rectangle::show()
{
		cout<<"The message of Rectangle:\n";
		cout<<"length is "<<length<<endl;
		cout<<"high is "<<high<<endl;
		Line::show();
		text.show();
}