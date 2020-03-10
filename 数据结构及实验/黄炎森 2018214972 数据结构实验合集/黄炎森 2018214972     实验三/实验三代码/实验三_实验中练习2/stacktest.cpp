#include "stackdwn.h"

int main()
{
    char ch;
    ElemType a;
    Stack S;
    InitStack( S, MaxStackSize ); //初始化栈
    int flag=1;
    while(flag)
    {
        cout<<"请输入指令:";
        cin>>ch;

        switch (ch)
        {
        case '+':
            cout<<"请输入您要入栈的数据:";
            cin>>a;
            Push(S,a);
            break;
        case '-':
            if(isEmpty(S))
                cout<<"栈已空,不能进行出栈操作！\n";
            else cout<<"栈顶元素为:"<<Pop(S)<<endl;
            break;
        case 'F':
            if(isFull(S))
                cout<<"栈满!\n";
            else cout<<"栈未满!\n";
            break;
        case 'E':
            if(isEmpty(S))
                cout<<"栈为空!\n";
            else cout<<"栈非空!\n";
            break;
        case 'C':
            clearStack(S);
            cout<<"栈已清空!\n";
            break;
        case 'Q':
            flag=0;
            break;
        default:
            cout<<"输入指令有误,请重新输入!\n";
            break;
        }
    }

    cout<<"欢迎下次使用!\n";
    return 0;
}
