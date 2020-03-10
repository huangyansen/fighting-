#include"puzzle.h"

void InitPuzzle(List* &head, char answ[] , char init[])//answ Ϊ����ַ������ı��������д�������head,��init����˫����
{
    head->next=head;
    head->prior=head;//��ʼ��ͷָ��

    int len=strlen(init);
    List* s=head;
    for(int i=0;i<len;++i){
        List* p = new List;
        p->c=init[i];
        s->next=p;
        p->prior=s;
        p->next=head;
        head->prior=p;
        s=p;
    }
}

void shiftLeft(List* &head)//��������һ��,���ѵ�һ��ȡ��������ĩβ
{
    List* tempa=head->next;
    List* tempz=head->prior;

    head->next=tempa->next;
    tempa->next->prior=head;
    tempz->next=tempa;
    tempa->prior=tempz;
    tempa->next=head;
    head->prior=tempa;
}

void swapEnds(List* &head)//��������ߺ����ұ���ĸ,������������ݾͿ���
{
    Elemtype temp=head->next->c;
    head->next->c=head->prior->c;
    head->prior->c=temp;
}

void display(List* head)//��ʾ��ǰ����
{
    List* temp=head->next;
    while(temp!=head){
        cout<<temp->c;
        temp=temp->next;
    }
    cout<<endl;
}

bool issolve(List* head,char answ[])//�Ƿ���������
{
    int flag=0;
    int len=strlen(answ);
    List* temp=head;
    for(int i=0;i<len;++i){
        temp=temp->next;
        if(temp->c!=answ[i])
            return false;
    }
    if(temp->next!=head) return false;//��ǰ�ַ����ȴ𰸳�
    else return true;
}

int main(){
    char answ[100],init[100];
    cout<<"��ֱ��������ַ����ͳ�ʼ�ַ�������һ��������Ϸ:\n";
    cin>>answ>>init;
    List* head=new List;
    InitPuzzle(head,answ,init);

    int t;
    while(1){
        cout<<"���������:(0:�˳� 1:�������� 2:������β)";
        cin>>t;
        if(t==0){
            cout<<"��Ϸ������\n";
            break;
        }
        else if(t==1){
            shiftLeft(head);
            display(head);
            if(issolve(head,answ)){
                cout<<"��ϲ����ܳɹ���\n";
                break;
            }
        }
        else if(t==2){
            swapEnds(head);
            display(head);
            if(issolve(head,answ)){
                cout<<"��ϲ����ܳɹ���\n";
                break;
            }
        }
    }
    return 0;
}
