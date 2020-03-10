#include "stacklnk.h"

void InitStack( Stack &S, int maxNumber )//����maxnumberΪMaxStackSize
{
    S.dataItems=new ElemType [maxNumber];//��̬����һ������
    S.maxsize=maxNumber;
    S.top=-1;//��0��ʼ(ջ��ָ��)
}

void DestroyStack( Stack S )
{
    delete S.dataItems;
}

void Push( Stack &S, ElemType newDataItem )//���ƶ�ջ��ָ�룬���������
{
    if(isFull(S))
    {
        cout<<"ջ����,���ܽ�����ջ������\n";
        return;
    }

    (S.top)++;
    (S.dataItems)[S.top]=newDataItem;
}

ElemType Pop( Stack &S )
{
    ElemType temp=(S.dataItems)[S.top];
    (S.top)--;
    return temp;
}

void clearStack( Stack &S )//��������ֱ����ָ��ָ��һ��ʼ�Ϳ���
{
    S.top=-1;
}

bool isEmpty( Stack S )
{
    if(S.top==-1)
        return true;
    else return false;
}

bool isFull( Stack S )
{
    if(S.top==S.maxsize-1)
        return true;
    else return false;
}

void showStructure( Stack S )
{
    if(isEmpty(S))
    {
        cout<<"Empty stack!\n";
        return;
    }

    while(S.top!=-1)
    {
        cout<<(S.dataItems)[S.top]<<endl;
        (S.top)--;
    }
}

