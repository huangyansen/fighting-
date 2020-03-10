#include "stackdwn.h"

int main()
{
    char ch;
    ElemType a;
    Stack S;
    InitStack( S, MaxStackSize ); //��ʼ��ջ
    int flag=1;
    while(flag)
    {
        cout<<"������ָ��:";
        cin>>ch;

        switch (ch)
        {
        case '+':
            cout<<"��������Ҫ��ջ������:";
            cin>>a;
            Push(S,a);
            break;
        case '-':
            if(isEmpty(S))
                cout<<"ջ�ѿ�,���ܽ��г�ջ������\n";
            else cout<<"ջ��Ԫ��Ϊ:"<<Pop(S)<<endl;
            break;
        case 'F':
            if(isFull(S))
                cout<<"ջ��!\n";
            else cout<<"ջδ��!\n";
            break;
        case 'E':
            if(isEmpty(S))
                cout<<"ջΪ��!\n";
            else cout<<"ջ�ǿ�!\n";
            break;
        case 'C':
            clearStack(S);
            cout<<"ջ�����!\n";
            break;
        case 'Q':
            flag=0;
            break;
        default:
            cout<<"����ָ������,����������!\n";
            break;
        }
    }

    cout<<"��ӭ�´�ʹ��!\n";
    return 0;
}
