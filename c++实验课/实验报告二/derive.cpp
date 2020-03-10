#include "base.h"
#include "derive.h"

Rectangle::Rectangle(){}

Rectangle::Rectangle(int length,int width,int type,double thick, char *color)
:CGraph(type,thick,color)
{
		this->length=length;
		this->width=width;
}

Rectangle::Rectangle(Rectangle& R)
:CGraph(R)//派生类的拷贝构造 调用基类的构造函数方式
{										
		this->length=R.length;
		this->width=R.width;
}

void Rectangle::show()//实例化纯虚函数
{
		cout<<"---------Rectangle---------\n";
		cout<<"The message of Rectangle:\n";
		cout<<"length is "<<length<<endl;
		cout<<"width is "<<width<<endl;
		cout<<"thick is"<<thick<<endl;
		cout<<"color is"<<color<<endl;
		cout<<"---------------------------\n\n";
}

double Rectangle::area()
{
	return (this->length)*(this->width);
}



ellipse::ellipse() {}

ellipse::ellipse(int a,int b,int c,int type,double thick, char *color)
:CGraph(type,thick,color)
{
	this->a=a;
	this->b=b;
	this->c=c;
}

ellipse::ellipse(ellipse& E)
:CGraph(E)
{
	this->a=E.a;
	this->b=E.b;
	this->c=E.c;
}

void ellipse::show()
{
		cout<<"---------Ellipse---------\n";
		cout<<"The message of Ellipse:\n";
		cout<<"long axis is "<<a<<endl;
		cout<<"minor axis is "<<b<<endl;
		cout<<"focal length is "<<c<<endl;
		cout<<"thick is"<<thick<<endl;
		cout<<"color is"<<color<<endl;
		cout<<"---------------------------\n\n";
}

double ellipse::area()
{
	return 3.14*a*b;
}



CRoundRect::CRoundRect(int length,int width,int a,int b,int c,int type,int thick,char *color)//虚基类的构造函数
:Rectangle(length,width,type,thick,color),ellipse(a,b,c,type,thick,color),CGraph(type,thick,color)//在矩形和椭圆对象的构造中，会跳过对图形类的构造
{}

CRoundRect::CRoundRect(Rectangle R,ellipse E,int type,int thick,char* color)
:Rectangle(R),ellipse(E),CGraph(type,thick,color)
{}

CRoundRect::CRoundRect(CRoundRect& CR)
:Rectangle(CR),ellipse(CR),CGraph(CR)
{}

void CRoundRect::show()
{
		cout<<"---------CRoundRect---------\n";
		Rectangle::show();
		ellipse::show();
		cout<<"---------------------------\n\n";
}

double CRoundRect::area()//多继承中依然可以对纯虚函数进行重载
{
	return Rectangle::area()+ellipse::area();
}



CPPage::CPPage(vector<CGraph*>V)//构造一个空的ppt页对象,即在main中也要传一个vector（在main中初始化）
{
	this->V=V;
}

CPPage::CPPage(CPPage& page)//拷贝构造（把数组指针的每个指针指向的东西赋给page的数据成员）
{
	V=page.V;
	numCR=page.numCR;
	numE=page.numE;
	numR=page.numR;
}

void CPPage::ADDR(Rectangle& R)
{
	V.push_back((CGraph*)&R);
	numR++;
}

void CPPage::ADDE(ellipse& E)
{
	V.push_back((CGraph*)&E);
	numE++;
}

void CPPage::ADDCR(CRoundRect& CR)
{
	V.push_back((CGraph*)&CR);
	numCR++;
}

void CPPage::Del(int type,int num)//删除图形,根据类型和下标去找（每删除一次，下标会变化！！）,即删除类型为type的第num个图形
{
	if(V.empty())//PPtpage内为空，不能删除图形对象
	{
		cout<<"Wrong!\n";
		return;
	}

	int t0=0,t1=0,t2=0;//记录当前个数

	for(int i=0;i<V.size();++i)
	{
		if(V[i]->type==0)//矩形，在友元类中，可以直接访问 与之为友元关系的类的所有私有成员
		{												//（eg: B为A的友元类， 则对于在B中定义的A a，可以直接通过“.”访问A类的所有成员）
			t0++;
			if(type==0&&t0==num)
			{	
				V.erase(V.begin()+i);
				return;
			}
				
		}
		else if(V[i]->type==1)//椭圆
		{
			t1++;
			if(type==1&&t1==num)
			{	
				V.erase(V.begin()+i);
				return;
			}
		}
		else if(V[i]->type==2)//圆角矩形
		{
			t2++;
			if(type==2&&t2==num)
			{
				V.erase(V.begin()+i);
				return;
			}
		}
	}

}


void CPPage::show()//展示所有图形信息（通过type判别）
{
		cout<<"---------CPPage---------\n";
		CGraph* p;
		for(int i=0;i<V.size();++i)
		{
			p=V[i];
			p->show();
		}
		cout<<"---------------------------\n\n";

}


int CPPage::numCR=0;
int CPPage::numE=0;
int CPPage::numR=0;
