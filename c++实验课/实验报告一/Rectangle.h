#include "Rectangle.h"

class Rectangle: public Line //继承线框类
{
private:
	int length,high;//长，宽
	Text text;//文本类为其数据成员
	
public:
	Rectangle(int length,int high,int x,int y,int thick,char* color,Text T) : text(T),Line(x,y,thick,color);

	Rectangle(Rectangle& R);

	void show();
};