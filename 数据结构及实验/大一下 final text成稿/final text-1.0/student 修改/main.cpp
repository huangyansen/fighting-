#include "score.h"

int  EditFlag = 0;
char WorkingFileName[31] = "";//�༶�ļ���
int  DataNum = 0;//ָ�ð༶�ļ�����i��ѧ��

int main(void)
{
	STUDENT **pstu;//��άָ�룬���ڼ�¼�ļ���     ��pstu->class->student��
	pstu = (STUDENT **)malloc(MAXNUM*sizeof(STUDENT *));
	if (!pstu) exit (-1);
	InitList(pstu,MAXNUM);//��ʼ��������pstu��ָ��ָ������ÿһ����ָ��
	DoMainMenu(pstu);//���˵���ʾ������ز���(�����˳�ϵͳ)
	FreeMemory(pstu,MAXNUM);//�ͷ������ָ��
	getch();
	return 0;
}

2
//      1234      �ƺ���  �� 24   102  68.0  76.0  79.0
//      1235        ����  �� 25   102  68.0  76.0  88.0


5
//      1234         liu  �� 22   123  77.0  67.0  82.0
//      1235       zhang  Ů 21   123  82.0  68.0  73.0
//      1236        wang  �� 25   123  65.0  82.0  81.0


7
//      1235       zhang  �� 23   123  87.0  67.0  88.0
      1236        wang  �� 24   123  85.0  76.0  90.0
      1002        sewi  �� 24   211  88.0  67.0  89.0
      1234         liu  Ů 22   123  67.0  78.0  87.0
      2112        hong  Ů 23   211  78.0  77.0  90.0
      2113        hong  �� 24   211  77.0  58.0  89.0
      1237        hong  �� 22   211  78.0  82.0  89.0
      1001         hei  Ů 24   211  84.0  67.0  89.0
//
//
//
//
//
//
//
