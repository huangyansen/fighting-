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
:CGraph(R)//������Ŀ������� ���û���Ĺ��캯����ʽ
{										
		this->length=R.length;
		this->width=R.width;
}

void Rectangle::show()//ʵ�������麯��
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



CRoundRect::CRoundRect(int length,int width,int a,int b,int c,int type,int thick,char *color)//�����Ĺ��캯��
:Rectangle(length,width,type,thick,color),ellipse(a,b,c,type,thick,color),CGraph(type,thick,color)//�ھ��κ���Բ����Ĺ����У���������ͼ����Ĺ���
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

double CRoundRect::area()//��̳�����Ȼ���ԶԴ��麯����������
{
	return Rectangle::area()+ellipse::area();
}



CPPage::CPPage(vector<CGraph*>V)//����һ���յ�pptҳ����,����main��ҲҪ��һ��vector����main�г�ʼ����
{
	this->V=V;
}

CPPage::CPPage(CPPage& page)//�������죨������ָ���ÿ��ָ��ָ��Ķ�������page�����ݳ�Ա��
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

void CPPage::Del(int type,int num)//ɾ��ͼ��,�������ͺ��±�ȥ�ң�ÿɾ��һ�Σ��±��仯������,��ɾ������Ϊtype�ĵ�num��ͼ��
{
	if(V.empty())//PPtpage��Ϊ�գ�����ɾ��ͼ�ζ���
	{
		cout<<"Wrong!\n";
		return;
	}

	int t0=0,t1=0,t2=0;//��¼��ǰ����

	for(int i=0;i<V.size();++i)
	{
		if(V[i]->type==0)//���Σ�����Ԫ���У�����ֱ�ӷ��� ��֮Ϊ��Ԫ��ϵ���������˽�г�Ա
		{												//��eg: BΪA����Ԫ�࣬ �������B�ж����A a������ֱ��ͨ����.������A������г�Ա��
			t0++;
			if(type==0&&t0==num)
			{	
				V.erase(V.begin()+i);
				return;
			}
				
		}
		else if(V[i]->type==1)//��Բ
		{
			t1++;
			if(type==1&&t1==num)
			{	
				V.erase(V.begin()+i);
				return;
			}
		}
		else if(V[i]->type==2)//Բ�Ǿ���
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


void CPPage::show()//չʾ����ͼ����Ϣ��ͨ��type�б�
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
