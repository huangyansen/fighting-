#include "score.h"

int  EditFlag = 0;
char WorkingFileName[31] = "";//�༶�ļ���
int  DataNum = 0;//ָ�ð༶�ļ�����i��ѧ��

int main(void)
{
    student_ *pstu;//ָ�룬�������¼�ļ��е�һ��ѧ���ṹ�ĵ�ַ     ��pstu->��һ��student->������Ϣ��
    pstu=(student_ *)malloc(sizeof(student_));
    pstu->next=NULL;
    if(pstu==NULL)
    {
        printf("WRONG\n");
        return 0;
    }
    //��ʼ��������pstu��ָ�ĵ�һ��ָ��ָ��
    DoMainMenu(pstu);//���˵���ʾ������ز���(�����˳�ϵͳ)
    FreeMemory(pstu);//�ͷ������ָ��
    getch();
    return 0;
}





