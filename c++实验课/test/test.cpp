#include <stdio.h>
#include <iostream>
using namespace std;

class Point
{
private:
	int x,y;

public:
	Point(int x=0,int y=0)
	{
		this->x=x;
		this->y=y;
	}

	virtual double area()
	{
		return 0.0;
	}
};

class Circle: public Point
{
private:
	int radius;

public:
	Circle(int r,int x,int y):Point(x,y)
	{
		this->radius=r;
	}

	double area()
	{
		return radius*radius*3.14;
	}
};

int main()
{
	Point P(5,5);

	Circle C(1,2,3);


	Circle* Cc=&P;
	cout<<Cc->area()<<endl;
	
	return 0;
}