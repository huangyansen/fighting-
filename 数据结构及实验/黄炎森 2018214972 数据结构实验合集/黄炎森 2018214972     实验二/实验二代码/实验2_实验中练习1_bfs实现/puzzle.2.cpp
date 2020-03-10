#include"puzzle.2.h"
int father[100000];//记录不同状态的字符串
int flag[100000];//记录该字符串是否用过
int op[100000];//记录每个字符串状态对应的操作
int Temp;

void shiftLeft(char now[],char next[])//整体左移一个,即把第一个取出来插入末尾
{
    int len=strlen(now);
    for(int i=1; i<=len-1; ++i)
        next[i-1]=now[i];
    next[len-1]=now[0];
}

void swapEnds(char now[],char next[])//交换最左边和最右边字母,交换里面的内容就可以
{
    int len=strlen(now);
    strcpy(next,now);
    next[0]=now[len-1];
    next[len-1]=now[0];
}

void display(char s[])//显示当前字谜
{
    cout<<s<<endl;
}

bool issolve(char init[],char answ[])//是否破译字谜
{
    int len1=strlen(init);
    int len2=strlen(answ);
    if(len1!=len2) return false;

    for(int i=0; i<len1; ++i)
    {
        if(init[i]!=answ[i])
            return false;
    }
    return true;
}

int F(char s[])//由字符转成数字，作为flag的key值
{
    int len=strlen(s);
    int key=0,base=1;
    for(int i=0;i<len;++i){
        key+=(s[i]-'a')*base;
        base*=2;
    }
    return key;
}



void bfs(char init[], char answ[]) //宽搜，1代表整体左移，2代表首尾交换,函数内双链表，只用记录操作过程
{
    memset(flag,0,sizeof(flag));
    memset(father,0,sizeof(father));
    memset(op,0,sizeof(op));
    queue<Node>q;
    Node start;
    start.mark=0;
    strcpy(start.c,init);
    q.push(start);//队列初始值
    flag[F(start.c)]=1;
    father[F(start.c)]=-1;//初始状态的父亲为-1
    op[F(start.c)]=0;//操作为0

    while(!q.empty())
    {
        static Node now,next;
        now=q.front();//该步操作
        q.pop();
        if(issolve(now.c,answ))
        {
            Temp=F(now.c);
            return;
        }//标记最后一次操作

        for(int i=1; i<=2; ++i)
        {
            if(i==1)
            {
                shiftLeft(now.c,next.c);
                next.mark=1;
            }
            else
            {
                swapEnds(now.c,next.c);
                next.mark=2;
            }

            if(flag[F(next.c)]==0) //这种情况之前未出现
            {
                flag[F(next.c)]=1;
                father[F(next.c)]=F(now.c);
                op[F(next.c)]=next.mark;
                q.push(next);
            }
        }
    }
}

bool legal(char init[],char answ[])//检查是否能由当前字符串变换到结果字符串，不能则返回false
{
    int len1=strlen(init);
    int len2=strlen(answ);
    if(len1!=len2) return false;

    int flag1[100],flag2[100];
    memset(flag1,0,sizeof(flag1));
    memset(flag2,0,sizeof(flag2));

    for(int i=0; i<len1; ++i)
    {
        flag1[init[i]-'a']++;
        flag2[answ[i]-'a']++;
    }

    for(int i=0; i<26; ++i) //检查26个字母个数是否一样
    {
        if(flag1[i]!=flag2[i])
            return false;
    }
    return true;
}

int main()
{
    char answ[50],init[50];
    cout<<"请分别输入结果字符串和初始字符串创建一个字谜游戏:\n";
    cin>>answ>>init;

    if(!legal(init,answ))
        cout<<"该游戏不合法！\n";
    else
    {
        bfs(init,answ);

        stack<int>s;//记录最终结果

        while(1)
        {
            if(Temp==-1) break;//到底了
            s.push(Temp);
            Temp=father[Temp];
        }

        char next[50];
        int len=strlen(init);
        strcpy(next,init);
        cout<<"解密结果如下:\n";
        while(!s.empty())
        {
            int t=s.top();//压的是状态
            s.pop();
            if(op[t]==1)//op[t]==0是无操作
            {
                char tempc=next[0];
                for(int i=0;i<=len-2;++i)
                    next[i]=next[i+1];
                next[len-1]=tempc;
                cout<<"shiftLeft:";
                display(next);
            }
            else if(op[t]==2)
            {
                char tempc=next[0];
                next[0]=next[len-1];
                next[len-1]=tempc;
                cout<<"swapEnds:";
                display(next);
            }
        }
    }
    return 0;
}
