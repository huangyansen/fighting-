#include "stackdwn.h"

void InitStack( Stack &S, int maxNumber )//传入maxnumber为MaxStackSize
{
    S.dataItems=new ElemType [maxNumber];//动态分配一个数组
    S.maxsize=maxNumber;
    S.top=maxNumber;//从maxNumber开始(栈顶指针),还没有任何元素
}

void DestroyStack( Stack S )
{
    delete S.dataItems;
}

void Push( Stack &S, ElemType newDataItem )//先移动栈顶指针，后放入数据
{
    if(isFull(S))
    {
        cout<<"栈已满,不能进行入栈操作！\n";
        return;
    }

    (S.top)--;
    (S.dataItems)[S.top]=newDataItem;
}

ElemType Pop( Stack &S )
{
    ElemType temp=(S.dataItems)[S.top];
    (S.top)++;
    return temp;
}

void clearStack( Stack &S )//清空数据项，直接令指针指向一开始就可以
{
    S.top=S.maxsize;
}

bool isEmpty( Stack S )
{
    if(S.top==S.maxsize)
        return true;
    else return false;
}

bool isFull( Stack S )
{
    if(S.top==0)
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

    while(S.top!=S.maxsize)
    {
        cout<<(S.dataItems)[S.top]<<endl;
        (S.top)++;
    }
}

