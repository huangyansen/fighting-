#include "base.h"


#ifndef _onec_
#define _onec_

class Rectangle: public Line //�̳��߿���
{
private:
	int length,width;//������
	Text text;//�ı���Ϊ�����ݳ�Ա
	
public:
	Rectangle();//�չ��캯��
	Rectangle(int length,int width,int x,int y,int thick,char* color1,int size,char *content,char *color2);//���캯��
	Rectangle(int length,int width,int x,int y,int thick,char* color,Text T);//������Ĺ��캯���������õ���text��������캯��
	Rectangle(int length,int width,Line L,Text T);//������Ĺ��캯��,�õ�����Line�Ŀ���������text���������

	Rectangle(Rectangle& R);  //����Text�Ŀ������캯��
//�Լ����ڼ̳���Ŀ������캯����Ҫ�ڿ������캯���ĳ�ʼ����Ա�б��е��û���Ŀ������캯�����ô��õ������ͼ��ݣ�
	void show();

	friend class CPPage;//��CPPage��Ϊ���ε���Ԫ�࣬��CPPage�еĳ�Ա���������Է��ʾ��ε��κγ�Ա
};


class ellipse: public Line //�̳��߿���
{
private:
	int radius;//�뾶
	Text text;//�ı���Ϊ�����ݳ�Ա
	
public:
	ellipse();
	ellipse(int radius,int x,int y,int thick,char* color1,int size,char *content,char *color2);//���캯��
	ellipse(int radius,int x,int y,int thick,char* color,Text T);
	ellipse(int radius,Line L,Text T);
	ellipse(ellipse& E);
	void show();

	friend class CPPage;
};

#endif 