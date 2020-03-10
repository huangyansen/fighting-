#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

bool delimitersOk(string str)
{
    stack<char>s;
    int len=str.length();
    for(int i=0;i<len;++i){
        switch(str[i])
        {
            case '(':
            case '[':s.push(str[i]);
                     break;
            case ')':if(!s.empty()&&s.top()=='(')
                        s.pop();
                     else return false;
                     break;
            case ']':if(!s.empty()&&s.top()=='[')
                        s.pop();
                     else return false;
                     break;
            default:break;
        }
    }
    if(s.empty())
        return true;
    else return false;
}

int main()
{
    cout<<"������һ�����ʽ:";
    string s;
    cin>>s;

    if(delimitersOk(s))
        cout<<"�ֽ����ȷ!\n";
    else cout<<"�ֽ����������!\n";

    return 0;
}
