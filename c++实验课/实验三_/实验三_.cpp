#include<stdio.h>
#include<iostream>
using namespace std;

class Rectangle{
	private:
		double height,width;
		char *color;
		double x,y;//文本框的位置，从(x,y)到(x+height,y+width)
		struct Text{
			char *text;//文本字符串
			double dx,dy;//文本位置,必须位于(x,y)到(x+height,y+width)
		};
		
		
		
	public:
		Rectangle(double h=0, double w=0,char *color,char *text)//构造函数,相当于好几个函数
		{
			height=h,width=w;
			Text.text=new char
		}

		double S()//求面积
		{
			reuturn height*width;
		}

		double C()//求周长
		{
			return (height+width)*2;
		}

		~Rectangle()
		{
			
		}

		void ShowMsg()
		{
			cout<<"the massage of this Rectangle:\n"<<"height:"<<height<<endl<<"width:"<<width<<endl;//待续
		}

		




};