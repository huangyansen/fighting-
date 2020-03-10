#include "head.h"

Line::Line(int x,int y,int thick,char* color)
{
		this->x=x;
		this->y=y;
		this->thick=thick;
		if(color!=NULL)
			strcpy(this->color,color);
}

void Line::show()
{
		cout<<"The message of Line:\n";
		cout<<"(x,y) is "<<"("<<x<<","<<y<<")"<<endl;
		cout<<"thick is "<<thick<<endl;
		cout<<"color is "<<color<<endl;
}


Text::Text(int size, char* content, char* color)//����ʱ����дĬ�ϲ���������ʱ����д���ں����������Ͷ����ж���Ĭ�ϲ���д�ϣ�������ظ�����Ĵ���
{
		this->size=size;
		if(content!=NULL) //��̬�����ı���Ϣ
		{
			int len=strlen(content);
			this->content = new char[len+1];
			strcpy(this->content,content);
		}
		if(color!=NULL)
			strcpy(this->color,color);
}
	

Text::Text(Text& T)
{
		this->size=T.size;
		strcpy(this->color,T.color);
		
		int len=strlen(T.content);
		this->content = new char[len+1];
		strcpy(this->content,T.content);
}

void Text::show()
{
		cout<<"The message of Text:\n";
		cout<<"size is "<<size<<endl;
		cout<<"color is "<<color<<endl;
		cout<<"content is "<<"\""<<content<<"\""<<endl;
}

Text::~Text()
{
		if(content!=NULL)
		{
			delete [] content;
			content=NULL;
		}
}

Rectangle::Rectangle(int length,int width,int x,int y,int thick,char* color1,int size,char *content,char *color2)
			:Line(x,y,thick,color1),text(size,content,color2)
{
		this->length=length;
		this->width=width;
}


Rectangle::Rectangle(int length,int width,int x,int y,int thick,char* color,Text T) : text(T),Line(x,y,thick,color)//�����õ���text��������캯��
{
		this->length=length;
		this->width=width;
}

Rectangle::Rectangle(int length,int width,Line L,Text T): text(T),Line(L)
{
		this->length=length;
		this->width=width;
}

Rectangle::Rectangle(Rectangle& R): text(R.text),Line(R)  //����Text�Ŀ������캯��
{    //�Լ����ڼ̳���Ŀ������캯����Ҫ�ڿ������캯���ĳ�ʼ����Ա�б��е��û���Ŀ������캯�����ô��õ������ͼ��ݣ�
										
		this->length=R.length;
		this->width=R.width;
}

void Rectangle::show()
{
		cout<<"The message of Rectangle:\n";
		cout<<"length is "<<length<<endl;
		cout<<"width is "<<width<<endl;
		Line::show();
		text.show();
		cout<<"\n\n";
}



ellipse::ellipse(int radius,int x,int y,int thick,char* color,Text T) : text(T),Line(x,y,thick,color)
{
		this->radius=radius;
}

ellipse::ellipse(ellipse& E): text(E.text),Line(E) 
{
		this->radius=E.radius;
}

void ellipse::show()
{
		cout<<"The message of ellipse:\n";
		cout<<"radius is "<<radius<<endl;
		Line::show();
		text.show();

}


int main()
{
	char s[]="World!";
	Text t1(1,s,"red");
	//t1.show();
	Rectangle Rec1(10,20,2,5,3,"black",t1);
	Rec1.show();
	Rectangle Rec2(Rec1);
	Rec2.show();
	return 0;
}

