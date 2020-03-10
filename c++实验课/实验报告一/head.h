#include <stdio.h>
#include <iostream>
using namespace std;

class Line//�߿�
{
private:
	int x,y;//�ο��㣬���ھ�����˵�����Ͻǵĵ㣬����Բ��˵��Բ��
	int thick;//��ϸ
	char color[10];//��ɫ

public:
	Line(int x=0,int y=0,int thick=0.1,char* color=NULL);//���εĹ��캯��
	void show();
};


class Text//�ı�
{
private:
	int size;//��С
	char* content;//���ݣ���Ҫ��̬����
	char color[10];//��ɫ

public:
	Text(int size, char* content=NULL, char* color=NULL);//���εĹ��캯��
	Text(Text& T);//�������캯��
	void show();
	~Text();
};


class Rectangle: public Line //�̳��߿���
{
private:
	int length,width;//������
	Text text;//�ı���Ϊ�����ݳ�Ա
	
public:
	Rectangle(int length,int width,int x,int y,int thick,char* color1,int size,char *content,char *color2);//���캯��
	Rectangle(int length,int width,int x,int y,int thick,char* color,Text T);//������Ĺ��캯���������õ���text��������캯��
	Rectangle(int length,int width,Line L,Text T);//������Ĺ��캯��,�õ�����Line�Ŀ���������text���������

	Rectangle(Rectangle& R);  //����Text�Ŀ������캯��
//�Լ����ڼ̳���Ŀ������캯����Ҫ�ڿ������캯���ĳ�ʼ����Ա�б��е��û���Ŀ������캯�����ô��õ������ͼ��ݣ�
	void show();
};


class ellipse: public Line //�̳��߿���
{
private:
	int radius;//�뾶
	Text text;//�ı���Ϊ�����ݳ�Ա
	
public:
	ellipse(int radius,int x,int y,int thick,char* color,Text T);
	ellipse(ellipse& E);
	void show();
};
