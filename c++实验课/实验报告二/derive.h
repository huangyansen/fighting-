#include "base.h"

#ifndef _onec_
#define _onec_

class Rectangle:virtual public CGraph //矩形
{
private:
	int length,width;//长，宽

public:
	Rectangle();//空构造函数
	Rectangle(int length,int width,int type,double thick, char *color);//构造函数
	Rectangle(Rectangle& R);

	void show();
	double area();
};


class ellipse:virtual public CGraph //椭圆
{
private:
	int a,b,c;//长轴，短轴，焦距

public:
	ellipse();//空构造函数
	ellipse(int a,int b,int c,int type,double thick, char *color);//构造函数
	ellipse(ellipse& E);

	void show();
	double area();
};


class CRoundRect: public Rectangle, public ellipse//圆角矩形类，让CGraph在其中只有一份备份
{
public:
	CRoundRect(int length,int width,int a,int b,int c,int type,int thick,char* color);//虚基类的构造函数
	CRoundRect(Rectangle R,ellipse E,int type,int thick,char* color);
	CRoundRect(CRoundRect& CR);

	void show();
	double area();//多继承中依然可以对纯虚函数进行重载
};


class CPPage//一页PPT
{
private:
	vector<CGraph*>V;//每个指针指向一个图形
	static int numR;
	static int numE;
	static int numCR;//PPT中每个图形数量

public:
	CPPage(vector<CGraph*>V);//构造一个空的ppt页对象,即在main中也要传一个vector（在main中初始化）
	CPPage(CPPage& page);//拷贝构造（把数组指针的每个指针指向的东西赋给page的数据成员）
	void ADDR(Rectangle& R);
	void ADDE(ellipse& E);
	void ADDCR(CRoundRect& CR);//添加图形(根据输入，调用不同函数)
	void Del(int type,int num);//删除图形,根据类型和下标去找（每删除一次，下标会变化！！）
	void show();//展示所有图形信息（通过type判别）
};

#endif 