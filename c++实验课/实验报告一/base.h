#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#ifndef _onec 
#define _onec //��ֹ��ͷ�ļ����ظ�����������౻�ظ�����Ľ���취��������

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
	Text();
	Text(int size, char* content=NULL, char* color=NULL);//���εĹ��캯��
	Text(Text& T);//�������캯��
	void show();
	~Text();
	friend class Rectangle;
	friend class CPPage;
};

#endif 