#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include<stack>
using namespace std;

int main()
{
    char str[100];
    cout<<"������һ����׺ʽ:";//��׺ʽΪ������
    cin>>str;
    stack<double>s;//ջ�ڴ�double������
    int len=strlen(str);

    double temp1,temp2,ans;
    for(int i=0;i<len;++i){
        if(str[i]>='0'&&str[i]<='9')
            s.push(str[i]-'0');
        else if(str[i]=='+'){
            temp1=s.top();
            s.pop();
            temp2=s.top();
            s.pop();
            ans=temp1+temp2;
            s.push(ans);
        }
        else if(str[i]=='-'){
            temp1=s.top();
            s.pop();
            temp2=s.top();
            s.pop();
            ans=temp2-temp1;
            s.push(ans);
        }
        else if(str[i]=='*'){
            temp1=s.top();
            s.pop();
            temp2=s.top();
            s.pop();
            ans=temp1*temp2;
            s.push(ans);
        }
        else if(str[i]=='/'){
            temp1=s.top();
            s.pop();
            temp2=s.top();
            s.pop();
            ans=temp2/temp1;
            s.push(ans);
        }
    }
    cout<<"the answer is:"<<s.top();
    return 0;
}
