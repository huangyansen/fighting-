#include "base.h"
#include "derived.h"

struct Reclist
{
	Reclist(Rectangle R,Reclist* n,Reclist* p):rec(R)
		//�ṹ��Ĺ��캯�����õ�������Ŀ�������
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
};//˫��ѭ��������


class CPPage
{
private:
	Reclist* RH;
	Ellist* EH; //���κ���Բ�� ����,��̬�����ڴ�
	static int countR;
	static int countE;//����
	static int countCPP;//��CPPage����

public:
	CPPage();//�չ��캯������ʼʱʲô��û��
	void AddR(Rectangle R);//����һ������
	void AddE(ellipse E);//����һ����Բ
	void DelR();//ɾ����һ������
	void DelE();//ɾ����һ����Բ
	void show();
};