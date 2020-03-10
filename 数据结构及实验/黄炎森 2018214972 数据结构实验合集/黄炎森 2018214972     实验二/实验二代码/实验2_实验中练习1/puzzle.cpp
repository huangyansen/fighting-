#include"puzzle.h"

void InitPuzzle(List* &head, char answ[] , char init[])//answ 为结果字符串，改变主函数中传过来的head,即init建成双链表
{
    head->next=head;
    head->prior=head;//初始化头指针

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

void shiftLeft(List* &head)//整体左移一个,即把第一个取出来插入末尾
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

void swapEnds(List* &head)//交换最左边和最右边字母,交换里面的内容就可以
{
    Elemtype temp=head->next->c;
    head->next->c=head->prior->c;
    head->prior->c=temp;
}

void display(List* head)//显示当前字谜
{
    List* temp=head->next;
    while(temp!=head){
        cout<<temp->c;
        temp=temp->next;
    }
    cout<<endl;
}

bool issolve(List* head,char answ[])//是否破译字谜
{
    int flag=0;
    int len=strlen(answ);
    List* temp=head;
    for(int i=0;i<len;++i){
        temp=temp->next;
        if(temp->c!=answ[i])
            return false;
    }
    if(temp->next!=head) return false;//当前字符串比答案长
    else return true;
}

int main(){
    char answ[100],init[100];
    cout<<"请分别输入结果字符串和初始字符串创建一个字谜游戏:\n";
    cin>>answ>>init;
    List* head=new List;
    InitPuzzle(head,answ,init);

    int t;
    while(1){
        cout<<"请输入操作:(0:退出 1:整体左移 2:交换首尾)";
        cin>>t;
        if(t==0){
            cout<<"游戏结束！\n";
            break;
        }
        else if(t==1){
            shiftLeft(head);
            display(head);
            if(issolve(head,answ)){
                cout<<"恭喜你解密成功！\n";
                break;
            }
        }
        else if(t==2){
            swapEnds(head);
            display(head);
            if(issolve(head,answ)){
                cout<<"恭喜你解密成功！\n";
                break;
            }
        }
    }
    return 0;
}
