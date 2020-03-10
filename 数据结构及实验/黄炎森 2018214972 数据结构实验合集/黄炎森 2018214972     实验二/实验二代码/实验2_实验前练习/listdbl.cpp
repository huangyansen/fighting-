#include "listdbl.h"

void reverseList(List* &head)//实验中练习2新增，倒置一个列表中的数据项顺序，且不移动指针的位置
{
    List *tempa=head->next;
    List *tempz=head->prior;

    while(tempa!=tempz&&tempz->next!=tempa){
        char temp=tempa->c;
        tempa->c=tempz->c;
        tempz->c=temp;

        tempa=tempa->next;
        tempz=tempz->prior;
    }

}

void InitList(List* &head) //建一个空的双链表(有空的头结点)
{
    head->c='0';
    head->next=head;
    head->prior=head;
}

void DestroyList(List* &head) //释放存储列表的内存(从头结点开始删)
{
    List *temp=head->next;
    while(temp!=head)
    {
        List *s=temp;
        temp=temp->next;
        delete s;
    }
    delete head;
}

void insertList(List* &L,ElemType newData) //将新数据插入到指针L所指的数据后面
{
    List *pnew=new List;
    pnew->c=newData;

    pnew->next=L->next;
    pnew->prior=L;
    L->next->prior=pnew;
    L->next=pnew;
    L=pnew;//将指针移动到新元素上
}

void removeList(List* &L,List* head) //删除列表中指针所标记的数据项
{
    if(L==head) //当L为头结点时返回错误
    {
        printf("不能删除头结点！\n");
        return;
    }
    List *p=L;
    L->prior->next=p->next;
    p->next->prior=L->prior;
    L=L->next;//将L移至下一个元素
    delete p;
}

void replaceList(List* &L,ElemType newData) //使用newData替换指针标记的数据项
{
    L->c=newData;
}

void clearList(List* &head) //删除列表中所有数据项，从头结点开始
{
    List *p=head->next;
    while(p!=head)
    {
        p->c='0';//因为数据项都为char，故这里用数字0代表清空数据
        p=p->next;
    }
}

bool isEmpty(List* head) //判断列表是否为空，传入头结点
{
    if(head->next==head)//为空
        return true;
    else return false;
}

bool isFull(List* head) //判断链表是否为满
{
    int count_=0;
    List* temp=head->next;
    while(temp!=head){
        count_++;
        temp=temp->next;
    }
    if(count_>=Maxn)//为满
        return true;
    else return false;
}

void gotoBegining(List* &L,List* head)//移动指针到链表开始
{
    while(L!=head)
        L=L->next;
}

void gotoEnd(List* &L,List* head)//移动指针到链表末尾
{
    while(L->next!=head)
        L=L->next;
}

bool gotoNext(List* &L,List* head)
{
    if(!isEmpty(head)){
        L=L->next;
        return true;
    }
    else return false;
}

bool gotoPrior(List* &L,List* head)
{
    if(!isEmpty(head)){
        L=L->prior;
        return true;
    }
    else return false;
}

void getCursor(List* L,List* head)//返回指针所标记数据项的值
{
    if(L!=head)
        cout<<L->c;
    else if(L==head&&!isEmpty(head))//不空且指向头结点
        printf("指针指向头节点!\n");
    else printf("链表为空！\n");
}

void showStructure(List* head)//输出表中的数据项
{
    if(isEmpty(head)){
        printf(" Empty list\n");
    }
    else{//输出链表中所有数据
        List* temp=head->next;
        int count_=0;
        while(temp!=head){
            printf("第%d个数据是:%c\n",++count_,temp->c);
            temp=temp->next;
        }
    }
}

