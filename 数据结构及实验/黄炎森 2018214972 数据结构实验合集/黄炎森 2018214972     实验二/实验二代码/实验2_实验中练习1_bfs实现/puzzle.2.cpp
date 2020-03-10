#include"puzzle.2.h"
int father[100000];//��¼��ͬ״̬���ַ���
int flag[100000];//��¼���ַ����Ƿ��ù�
int op[100000];//��¼ÿ���ַ���״̬��Ӧ�Ĳ���
int Temp;

void shiftLeft(char now[],char next[])//��������һ��,���ѵ�һ��ȡ��������ĩβ
{
    int len=strlen(now);
    for(int i=1; i<=len-1; ++i)
        next[i-1]=now[i];
    next[len-1]=now[0];
}

void swapEnds(char now[],char next[])//��������ߺ����ұ���ĸ,������������ݾͿ���
{
    int len=strlen(now);
    strcpy(next,now);
    next[0]=now[len-1];
    next[len-1]=now[0];
}

void display(char s[])//��ʾ��ǰ����
{
    cout<<s<<endl;
}

bool issolve(char init[],char answ[])//�Ƿ���������
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

int F(char s[])//���ַ�ת�����֣���Ϊflag��keyֵ
{
    int len=strlen(s);
    int key=0,base=1;
    for(int i=0;i<len;++i){
        key+=(s[i]-'a')*base;
        base*=2;
    }
    return key;
}



void bfs(char init[], char answ[]) //���ѣ�1�����������ƣ�2������β����,������˫����ֻ�ü�¼��������
{
    memset(flag,0,sizeof(flag));
    memset(father,0,sizeof(father));
    memset(op,0,sizeof(op));
    queue<Node>q;
    Node start;
    start.mark=0;
    strcpy(start.c,init);
    q.push(start);//���г�ʼֵ
    flag[F(start.c)]=1;
    father[F(start.c)]=-1;//��ʼ״̬�ĸ���Ϊ-1
    op[F(start.c)]=0;//����Ϊ0

    while(!q.empty())
    {
        static Node now,next;
        now=q.front();//�ò�����
        q.pop();
        if(issolve(now.c,answ))
        {
            Temp=F(now.c);
            return;
        }//������һ�β���

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

            if(flag[F(next.c)]==0) //�������֮ǰδ����
            {
                flag[F(next.c)]=1;
                father[F(next.c)]=F(now.c);
                op[F(next.c)]=next.mark;
                q.push(next);
            }
        }
    }
}

bool legal(char init[],char answ[])//����Ƿ����ɵ�ǰ�ַ����任������ַ����������򷵻�false
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

    for(int i=0; i<26; ++i) //���26����ĸ�����Ƿ�һ��
    {
        if(flag1[i]!=flag2[i])
            return false;
    }
    return true;
}

int main()
{
    char answ[50],init[50];
    cout<<"��ֱ��������ַ����ͳ�ʼ�ַ�������һ��������Ϸ:\n";
    cin>>answ>>init;

    if(!legal(init,answ))
        cout<<"����Ϸ���Ϸ���\n";
    else
    {
        bfs(init,answ);

        stack<int>s;//��¼���ս��

        while(1)
        {
            if(Temp==-1) break;//������
            s.push(Temp);
            Temp=father[Temp];
        }

        char next[50];
        int len=strlen(init);
        strcpy(next,init);
        cout<<"���ܽ������:\n";
        while(!s.empty())
        {
            int t=s.top();//ѹ����״̬
            s.pop();
            if(op[t]==1)//op[t]==0���޲���
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
