#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<map>
#include<stack>
using namespace std;

bool prior(char c1,char c2)//�ж���������ȼ�,c1��c2���Ⱦͷ�����
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
    cout<<"��������׺ʽ:";
    cin>>s;
    stack<char>f;//�������
    f.push('#');//������־
    stack<double>ans;//�Ž��

    int len=s.length();
    for(int i=0; i<len; ++i)
    {
        if(s[i]>='0'&&s[i]<='9')
            {ans.push(s[i]-'0');  cout<<"ִ�з����ֲ��������������Ϊ:"<<ans.top()<<endl;}  //ֱ�ӷ�����
        else if(s[i]=='(')
            f.push('(');//������ֱ����ջ
        else if(s[i]==')')
        {
            while(f.top()!='(') //ֱ������������ǰһֱ��ջ
            {
                opera(f.top(),ans);//ִ���������
                f.pop();
            }
            f.pop();//��'('pop����
        }
        else if(prior(s[i],f.top()))//��ǰ��������ȼ��Ƚϴ�ֱ����ջ
            {cout<<"ִ�в�������ջ������ջ��Ϊ:"<<f.top()<<"��ջΪ:"<<s[i]<<endl; f.push(s[i]); }
        else //��ǰ��������ȼ�С�ڻ��ߵ��ڣ��û�
        {
            cout<<"ִ�в������û�������ִ�еĲ���Ϊ:"<<f.top()<<"��ջ�Ĳ���Ϊ:"<<s[i]<<'\t';
            char temp=f.top();
            f.pop();
            f.push(s[i]);
            opera(temp,ans);
            cout<<"��ʱ���ջ��ջ��Ϊ:"<<ans.top()<<endl;
        }
    }

    cout<<"ɨ����һ��֮��:"<<endl;
    while(f.top()!='#'){//ɨ��һ��֮��Ҫ�������ջ����
        cout<<"��ʱ��ջ���������:"<<f.top()<<'\t';
        opera(f.top(),ans);
        f.pop();
        cout<<"ִ��֮�󣬽��ջջ��Ϊ:"<<ans.top()<<endl;
    }

    cout<<"the answer is:"<<ans.top()<<endl;
    return 0;
}
