#include<stdio.h>
#include<iostream>
using namespace std;

class Rectangle{
	private:
		double height,width;
		char *color;
		double x,y;//�ı����λ�ã���(x,y)��(x+height,y+width)
		struct Text{
			char *text;//�ı��ַ���
			double dx,dy;//�ı�λ��,����λ��(x,y)��(x+height,y+width)
		};
		
		
		
	public:
		Rectangle(double h=0, double w=0,char *color,char *text)//���캯��,�൱�ںü�������
		{
			height=h,width=w;
			Text.text=new char
		}

		double S()//�����
		{
			reuturn height*width;
		}

		double C()//���ܳ�
		{
			return (height+width)*2;
		}

		~Rectangle()
		{
			
		}

		void ShowMsg()
		{
			cout<<"the massage of this Rectangle:\n"<<"height:"<<height<<endl<<"width:"<<width<<endl;//����
		}

		




};