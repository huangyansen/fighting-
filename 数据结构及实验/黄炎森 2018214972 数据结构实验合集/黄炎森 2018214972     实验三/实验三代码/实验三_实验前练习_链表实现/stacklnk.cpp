#include "stacklnk.h"

void InitStack( Stack &S )//��ʼ������,û�пյ�ͷ��㣬ע���Ǵ�ͷ�ڵ�(ջ��)ǰ����,S������ṹ��S->top���ǽڵ㣬��Ҫ��̬����
{
    S.Size=0;
    S.top=NULL;//��ʼʱ����ջ��Ϊ�սڵ㣬������Ϊջ�׵ı�ʶ
}

void DestroyStack( Stack S )
{
    StackNode* temp;
    while(S.Size!=0)
    {
        temp=S.top;
        S.top=S.top->next;
        delete temp;
        (S.Size)--;
    }
}

void Push( Stack &S, ElemType newDataItem )
{
    if(isFull(S))
    {
        cout<<"ջ����,���ܽ�����ջ������\n";
        return;
    }

    S.Size++;
    StackNode* snew=new StackNode;
    snew->dataltem=newDataItem;

    StackNode *temp=S.top;
    S.top=snew;
    snew->next=temp;
}

ElemType Pop( Stack &S )
{
    StackNode* temp1=S.top;
    StackNode* temp2=S.top;
    S.top=S.top->next;
    S.Size--;
    delete temp1;
    return temp2->dataltem;
}

void clearStack( Stack &S )
{
    StackNode* temp;
    while(S.Size!=0)
    {
        temp=S.top;
        S.top=S.top->next;
        S.Size--;
        delete temp;
    }
}

bool isEmpty( Stack S )
{
    if(S.Size==0)
        return true;
    else return false;
}

bool isFull( Stack S )
{
    if(S.Size==MaxStackSize)
        return true;
    else return false;
}

void showStructure( Stack S )
{
    StackNode* temp;
    while(S.Size!=0)
    {
        temp=S.top;
        S.top=S.top->next;
        cout<<temp->dataltem<<endl;
        delete temp;
        S.Size--;
    }
}
