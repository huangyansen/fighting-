#include "base.h"
#include "derived.h"

struct Reclist
{
	Reclist(Rectangle R,Reclist* n,Reclist* p):rec(R)
		//结构体的构造函数，用到矩形类的拷贝函数
	{
		next=n;
		prior=p;
	}

	Rectangle rec;
	Reclist* next;
	Reclist* prior;
};

struct Ellist
{
	Ellist(ellipse E,Ellist* n,Ellist* p):ell(E)
	{
		next=n;
		prior=p;
	}

	ellipse ell;
	Ellist* next;
	Ellist* prior;
};//双向循环链表储存


class CPPage
{
private:
	Reclist* RH;
	Ellist* EH; //矩形和椭圆形 链表,动态分配内存
	static int countR;
	static int countE;//计数
	static int countCPP;//对CPPage计数

public:
	CPPage();//空构造函数，初始时什么都没有
	void AddR(Rectangle R);//增加一个矩形
	void AddE(ellipse E);//增加一个椭圆
	void DelR();//删掉上一个矩形
	void DelE();//删掉上一个椭圆
	void show();
};