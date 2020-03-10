#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

#ifndef _onec 
#define _onec //��ֹ��ͷ�ļ����ظ�����������౻�ظ�����Ľ���취��


class CGraph //ͼ�γ�����(�����)
{
private:
	char color[10];
	double thick;//������ϸ
	int type; //����ͼ�����ͣ�Ϊ�ļ���ȡ��׼��

public:
	CGraph(int type=-1, double thick=1, char *color=NULL);//���캯��
	CGraph(CGraph& G);
	virtual void show()=0;//�麯��,�ṩ�ӿ�
	virtual double area()=0;//����ͼ�����

	friend class Rectangle;
	friend class ellipse;//��Ϊ��Ԫ�࣬����������ݳ�Ա
	friend class CRoundRect;
	friend class CPPage;
};

#endif 