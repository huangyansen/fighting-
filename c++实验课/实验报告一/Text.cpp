#include "Text.h"


Text::Text(int size, char* content=NULL, char* color=NULL)
{
		this->size=size;
		if(content!=NULL) //动态分配文本信息
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

Text::void show()
{
		cout<<"The message of Text:\n";
		cout<<"size is "<<size<<endl;
		cout<<"color is "<<color<<endl;
		cout<<"content is "<<content<<endl;
}

Text::~Text()
{
		if(content!=NULL)
		{
			delete [] content;
			content=NULL;
		}
}