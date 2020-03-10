#include "Rectangle.h"

Rectangle::Rectangle(int length,int high,int x,int y,int thick,char* color,Text T) : text(T),Line(x,y,thick,color)//�����õ���text��������캯��
{
		this->length=length;
		this->high=high;
}

Rectangle::Rectangle(Rectangle& R)//���޵��еĿ�����һ��Ҫд�յ�Text���캯������Ϊ�ڵ��ÿ������캯������������ʱû�и�����ʼ���Ĳ���
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