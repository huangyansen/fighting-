#include "base.h"

#ifndef _onec_
#define _onec_

class Rectangle:virtual public CGraph //����
{
private:
	int length,width;//������

public:
	Rectangle();//�չ��캯��
	Rectangle(int length,int width,int type,double thick, char *color);//���캯��
	Rectangle(Rectangle& R);

	void show();
	double area();
};


class ellipse:virtual public CGraph //��Բ
{
private:
	int a,b,c;//���ᣬ���ᣬ����

public:
	ellipse();//�չ��캯��
	ellipse(int a,int b,int c,int type,double thick, char *color);//���캯��
	ellipse(ellipse& E);

	void show();
	double area();
};


class CRoundRect: public Rectangle, public ellipse//Բ�Ǿ����࣬��CGraph������ֻ��һ�ݱ���
{
public:
	CRoundRect(int length,int width,int a,int b,int c,int type,int thick,char* color);//�����Ĺ��캯��
	CRoundRect(Rectangle R,ellipse E,int type,int thick,char* color);
	CRoundRect(CRoundRect& CR);

	void show();
	double area();//��̳�����Ȼ���ԶԴ��麯����������
};


class CPPage//һҳPPT
{
private:
	vector<CGraph*>V;//ÿ��ָ��ָ��һ��ͼ��
	static int numR;
	static int numE;
	static int numCR;//PPT��ÿ��ͼ������

public:
	CPPage(vector<CGraph*>V);//����һ���յ�pptҳ����,����main��ҲҪ��һ��vector����main�г�ʼ����
	CPPage(CPPage& page);//�������죨������ָ���ÿ��ָ��ָ��Ķ�������page�����ݳ�Ա��
	void ADDR(Rectangle& R);
	void ADDE(ellipse& E);
	void ADDCR(CRoundRect& CR);//���ͼ��(�������룬���ò�ͬ����)
	void Del(int type,int num);//ɾ��ͼ��,�������ͺ��±�ȥ�ң�ÿɾ��һ�Σ��±��仯������
	void show();//չʾ����ͼ����Ϣ��ͨ��type�б�
};

#endif 