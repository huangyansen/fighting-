#include "base.h"


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



Text::Text(){}

Text::Text(int size, char* content, char* color)
//����ʱ����дĬ�ϲ���������ʱ����д���ں����������Ͷ����ж���Ĭ�ϲ���д�ϣ�������ظ�����Ĵ��󣡣�
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