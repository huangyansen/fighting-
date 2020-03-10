#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<map>
#include<stack>
using namespace std;

bool prior(char c1,char c2)//判断运算符优先级,c1比c2优先就返回真
{
    map<char,int>m;
    m['#']=-1;
    m['(']=0;
    m['-']=1;
    m['+']=1;
    m['*']=2;
    m['/']=2;

    if(m[c1]>m[c2])
        return true;
    else return false;
}

void opera(char o, stack<double> &ans)
{
    double temp1,temp2,temp3;
    if(o=='+')
    {
        temp1=ans.top();
        ans.pop();
        temp2=ans.top();
        ans.pop();
        temp3=temp1+temp2;
        ans.push(temp3);
    }
    else if(o=='-')
    {
        temp1=ans.top();
        ans.pop();
        temp2=ans.top();
        ans.pop();
        temp3=temp2-temp1;
        ans.push(temp3);
    }
    else if(o=='*')
    {
        temp1=ans.top();
        ans.pop();
        temp2=ans.top();
        ans.pop();
        temp3=temp2*temp1;
        ans.push(temp3);
    }
    else if(o=='/')
    {
        temp1=ans.top();
        ans.pop();
        temp2=ans.top();
        ans.pop();
        temp3=temp2/temp1;
        ans.push(temp3);
    }
}

int main()
{
    string s;
    cout<<"请输入中缀式:";
    cin>>s;
    stack<char>f;//放运算符
    f.push('#');//结束标志
    stack<double>ans;//放结果

    int len=s.length();
    for(int i=0; i<len; ++i)
    {
        if(s[i]>='0'&&s[i]<='9')
            {ans.push(s[i]-'0');  cout<<"执行放数字操作，放入的数字为:"<<ans.top()<<endl;}  //直接放数字
        else if(s[i]=='(')
            f.push('(');//左括号直接入栈
        else if(s[i]==')')
        {
            while(f.top()!='(') //直到遇到左括号前一直出栈
            {
                opera(f.top(),ans);//执行运算操作
                f.pop();
            }
            f.pop();//把'('pop出来
        }
        else if(prior(s[i],f.top()))//当前运算符优先级比较大，直接入栈
            {cout<<"执行操作符入栈操作，栈顶为:"<<f.top()<<"入栈为:"<<s[i]<<endl; f.push(s[i]); }
        else //当前运算符优先级小于或者等于，置换
        {
            cout<<"执行操作符置换操作，执行的操作为:"<<f.top()<<"入栈的操作为:"<<s[i]<<'\t';
            char temp=f.top();
            f.pop();
            f.push(s[i]);
            opera(temp,ans);
            cout<<"此时结果栈的栈顶为:"<<ans.top()<<endl;
        }
    }

    cout<<"扫描完一遍之后:"<<endl;
    while(f.top()!='#'){//扫描一遍之后，要把运算符栈出完
        cout<<"此时出栈的运算符是:"<<f.top()<<'\t';
        opera(f.top(),ans);
        f.pop();
        cout<<"执行之后，结果栈栈顶为:"<<ans.top()<<endl;
    }

    cout<<"the answer is:"<<ans.top()<<endl;
    return 0;
}
