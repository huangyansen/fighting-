#include "Rectangle.h"

class Rectangle: public Line //�̳��߿���
{
private:
	int length,high;//������
	Text text;//�ı���Ϊ�����ݳ�Ա
	
public:
	Rectangle(int length,int high,int x,int y,int thick,char* color,Text T) : text(T),Line(x,y,thick,color);

	Rectangle(Rectangle& R);

	void show();
};