#include "score.h"

int  EditFlag = 0;
char WorkingFileName[31] = "";//�༶�ļ���
int  DataNum = 0;//ָ�ð༶�ļ�����i��ѧ��

int main(void)
{
	STUDENT *pstu;//ָ�룬�������¼�ļ��е�һ��ѧ���ṹ�ĵ�ַ     ��pstu->��һ��student->������Ϣ��
    pstu=(STUDENT *)malloc(sizeof(STUDENT));
    if(pstu==NULL) {printf("WRONG\n");return 0;}
	//��ʼ��������pstu��ָ�ĵ�һ��ָ��ָ��      Ϊʲô���ﲻ��
	DoMainMenu(pstu);//���˵���ʾ������ز���(�����˳�ϵͳ)
	FreeMemory(pstu);//�ͷ������ָ��
	getch();
	return 0;
}





