#include "stacklnk.h"

void InitStack( Stack &S )//初始化链表,没有空的头结点，注意是从头节点(栈顶)前插入,S是链表结构，S->top才是节点，需要动态申请
{
    S.Size=0;
    S.top=NULL;//初始时，堆栈内为空节点，可以作为栈底的标识
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
        cout<<"栈已满,不能进行入栈操作！\n";
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
