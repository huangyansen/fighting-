#include "Line.h"

Line::Line(int x=0,int y=0,int thick=0.1,char* color=NULL)
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