#include "listdbl.h"

void reverseList(List* &head)//ʵ������ϰ2����������һ���б��е�������˳���Ҳ��ƶ�ָ���λ��
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

void InitList(List* &head) //��һ���յ�˫����(�пյ�ͷ���)
{
    head->c='0';
    head->next=head;
    head->prior=head;
}

void DestroyList(List* &head) //�ͷŴ洢�б���ڴ�(��ͷ��㿪ʼɾ)
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

void insertList(List* &L,ElemType newData) //�������ݲ��뵽ָ��L��ָ�����ݺ���
{
    List *pnew=new List;
    pnew->c=newData;

    pnew->next=L->next;
    pnew->prior=L;
    L->next->prior=pnew;
    L->next=pnew;
    L=pnew;//��ָ���ƶ�����Ԫ����
}

void removeList(List* &L,List* head) //ɾ���б���ָ������ǵ�������
{
    if(L==head) //��LΪͷ���ʱ���ش���
    {
        printf("����ɾ��ͷ��㣡\n");
        return;
    }
    List *p=L;
    L->prior->next=p->next;
    p->next->prior=L->prior;
    L=L->next;//��L������һ��Ԫ��
    delete p;
}

void replaceList(List* &L,ElemType newData) //ʹ��newData�滻ָ���ǵ�������
{
    L->c=newData;
}

void clearList(List* &head) //ɾ���б��������������ͷ��㿪ʼ
{
    List *p=head->next;
    while(p!=head)
    {
        p->c='0';//��Ϊ�����Ϊchar��������������0�����������
        p=p->next;
    }
}

bool isEmpty(List* head) //�ж��б��Ƿ�Ϊ�գ�����ͷ���
{
    if(head->next==head)//Ϊ��
        return true;
    else return false;
}

bool isFull(List* head) //�ж������Ƿ�Ϊ��
{
    int count_=0;
    List* temp=head->next;
    while(temp!=head){
        count_++;
        temp=temp->next;
    }
    if(count_>=Maxn)//Ϊ��
        return true;
    else return false;
}

void gotoBegining(List* &L,List* head)//�ƶ�ָ�뵽����ʼ
{
    while(L!=head)
        L=L->next;
}

void gotoEnd(List* &L,List* head)//�ƶ�ָ�뵽����ĩβ
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

void getCursor(List* L,List* head)//����ָ��������������ֵ
{
    if(L!=head)
        cout<<L->c;
    else if(L==head&&!isEmpty(head))//������ָ��ͷ���
        printf("ָ��ָ��ͷ�ڵ�!\n");
    else printf("����Ϊ�գ�\n");
}

void showStructure(List* head)//������е�������
{
    if(isEmpty(head)){
        printf(" Empty list\n");
    }
    else{//�����������������
        List* temp=head->next;
        int count_=0;
        while(temp!=head){
            printf("��%d��������:%c\n",++count_,temp->c);
            temp=temp->next;
        }
    }
}

