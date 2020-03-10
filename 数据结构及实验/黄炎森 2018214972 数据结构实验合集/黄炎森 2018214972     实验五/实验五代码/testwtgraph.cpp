#include "wtgraph.h"

int flag[105];//为0表示这个下标没有代表一个字符串，为1则有   点的下标也是从0开始
set<int>s;//存字符串的二进制数，方便找到该字符串是否在当前的图里面， 存当前图中的点

void InitWtGraph( WtGraph &G, int maxNumber )//创建一个空的图。为其分配足够的内存空间，它包含maxNumber个顶点的图。(动态分配)
{
    G.Size=0;//初始创建图，一个顶点也没有
    G.maxSize=maxNumber;//最大有maxNumber个顶点的图
    G.vertex= new Vertex[maxNumber];//分配顶点

    G.adjMatrix=new int*[maxNumber];
    for(int i=0; i<maxNumber; ++i)
        G.adjMatrix[i]=new int[maxNumber];//动态分配二维数组

    for(int i=0; i<maxNumber; ++i) //初始化距离,全为不可到达，即最大值;到自己为0
        for(int j=0; j<maxNumber; ++j)
        {
            if(i==j) G.adjMatrix[i][j]=0;
            else G.adjMatrix[i][j]=infiniteEdgeWt;
        }


    memset(flag,0,sizeof(flag));
}

void DeWtGraph( WtGraph &G )//释放存储图占用的空间
{
    delete G.vertex;

    for(int i=0; i<G.maxSize; ++i)
        delete [] G.adjMatrix[i];
    delete G.adjMatrix;
}

int  getIndex( WtGraph &G, char *v )//根据顶点字符串信息返回是哪一个点,没有则返回-1
{
    for(int i=0; i<G.maxSize; ++i)
    {
        if(strcmp(G.vertex[i].label,v)==0)
            return i;
    }

    return -1;
}

int  Getedge( WtGraph G, int row, int col )//根据两个顶点返回边权,没有则返回-1
{
    if(row>G.maxSize||col>G.maxSize)
        return -1;

    return G.adjMatrix[row-1][col-1];
}

void setEdge( WtGraph &G, int row, int col, int wt )//用wt更新边权
{
    if(row>G.maxSize||col>G.maxSize)
        cout<<"Refresh Fail!\n";

    G.adjMatrix[row-1][col-1]=wt;
    cout<<"Refresh success!\n";
}

int trans(char s[])//将字符串通过二进制转化为唯一数字
{
    int len=strlen(s);
    int key=0,base=1;
    for(int i=0; i<len; ++i)
    {
        key+=(s[i]-'a')*base;
        base*=2;
    }
    return key;
}


void insertVertex( WtGraph &G, Vertex newVertex )//添加点newVertex到图中。如果这个顶点在图中已存在，则不用管。(图已存在)
{
    //通过遍历，找(0,maxNumber-1)中有哪些下标不在当前图中
    int temp=trans(newVertex.label);

    if(s.count(temp))//点已经存在
    {
        cout<<"Already exist!\n";
        return;
    }

    //点不在当前图中
    s.insert(temp);//往当前图中加入一个点（个数也增加了）
    G.Size++;
    for(int i=0; i<G.maxSize; ++i)
    {
        if(flag[i]==0)//表示这个下标没有表示一个字符串        记得在主函数中把flag置为0！！！
        {
            strcpy(G.vertex[i].label,newVertex.label);//用下标引索字符串
            G.vertex[i].color=newVertex.color;
            flag[i]=1;//表示用过了
            break;
        }
    }
}

void insertEdge( WtGraph &G, char *v1, char *v2, int wt )//添加一条连接v1和v2的无向边到图中，已有则更新它
{
    int temp1=trans(v1),temp2=trans(v2);
    if(s.count(temp1)==0||s.count(temp2)==0)//不满足图中两个点都存在
    {
        cout<<"Not all of the two points are in the diagram!\n";
        return;
    }

    //两个点都在图中了
    int mark=0;
    int a,b;
    for(int i=0; i<G.maxSize; ++i)
    {
        if(strcmp(G.vertex[i].label,v1)==0)
        {
            mark++;
            a=i;
        }
        if(strcmp(G.vertex[i].label,v2)==0)
        {
            mark++;
            b=i;
        }

        if(mark==2)//两个点的下标都找到了
            break;
    }

    G.adjMatrix[a][b]=G.adjMatrix[b][a]=wt;
}


bool retrieveVertex( WtGraph G, char *v, Vertex &vData )//有则为true并且vData返回点下标；否则返回false
{
    for(int i=0; i<G.maxSize; ++i)
    {
        if(strcmp(G.vertex[i].label,v)==0)
        {
            strcpy(vData.label,v);
            return true;
        }
    }

    return false;
}

bool GetedgeWeight( WtGraph G, char *v1, char *v2, int &wt )//有则为true并且wt返回边权；否则返回false
{
    int temp1=trans(v1),temp2=trans(v2);
    if(s.count(temp1)==0||s.count(temp2)==0)//不满足图中两个点都存在
    {
        cout<<"Not all of the two points are in the diagram!\n";
        return false;
    }

    //两个点都在图中了
    int mark=0;
    int a,b;
    for(int i=0; i<G.maxSize; ++i)
    {
        if(strcmp(G.vertex[i].label,v1)==0)
        {
            mark++;
            a=i;
        }
        if(strcmp(G.vertex[i].label,v2)==0)
        {
            mark++;
            b=i;
        }

        if(mark==2)//两个点的下标都找到了
            break;
    }

    wt=G.adjMatrix[a][b];
    return true;
}

void removeVertex( WtGraph &G, char *v)//前提是图包括顶点v。 结果：从图中删除顶点v。
{
    int temp=trans(v);

    if(s.count(temp)==0)//图中无此点
    {
        cout<<"The is no such point!\n";
        return;
    }

    int a;//删掉这个点   将邻接矩阵的该行该列置为0， 点的数组指针中存储的字符串删除(通过set删掉对应二进制数体现)
    for(int i=0; i<G.maxSize; ++i)
    {
        if(strcmp(G.vertex[i].label,v)==0)//到底用.  还是->
        {
            a=i;
            break;
        }
    }
    flag[a]=0;//表示这个点没有在用了

    for(int i=0; i<G.maxSize; ++i)
        G.adjMatrix[i][a]=G.adjMatrix[a][i]=0;

    s.erase(temp);
    G.Size--;
}

void removeEdge( WtGraph &G, char *v1, char *v2 )//前提是图包括顶点v1和v2。 结果：从图中删除连接v1和v2的无向边。
{
    int temp1=trans(v1),temp2=trans(v2);
    if(s.count(temp1)==0||s.count(temp2)==0)//不满足图中两个点都存在
    {
        cout<<"Not all of the two points are in the diagram!\n";
        return;
    }

    //两个点都在图中了
    int mark=0;
    int a,b;
    for(int i=0; i<G.maxSize; ++i)
    {
        if(strcmp(G.vertex[i].label,v1)==0)
        {
            mark++;
            a=i;
        }
        if(strcmp(G.vertex[i].label,v2)==0)
        {
            mark++;
            b=i;
        }

        if(mark==2)//两个点的下标都找到了
            break;
    }

    G.adjMatrix[a][b]=G.adjMatrix[b][a]=infiniteEdgeWt;
}


void Clear( WtGraph &G )//删所有的点和边 (通过清空set来表示删掉点) , 重置边权来删边
{
    G.Size=0;
    s.clear();
    memset(flag,0,sizeof(flag));

    for(int i=0; i<G.maxSize; ++i) //初始化距离，自己到自己为0，其余全为-1
        for(int j=0; j<G.maxSize; ++j)
        {
            if(i==j) G.adjMatrix[i][j]=0;
            else G.adjMatrix[i][j]=infiniteEdgeWt;
        }
}

bool isEmpty( WtGraph G )//检查有无顶点,无顶点则返回真
{
    if(s.empty())
        return true;
    return false;
}

bool isFull( WtGraph G )
{
    if(G.Size==G.maxSize)
        return true;
    return false;
}

void showStructure( WtGraph G )//以数组形式输出图的顶点，以邻接矩阵形式输出边(带权值),如果图为空，则输出“Empty graph”
{
    if(isEmpty(G))
    {
        cout<<"Empty graph!\n";
        return;
    }

    //打印每个下标代表的字符串，即顶点
    cout<<"\nThe message of Vertex:\n";
    for(int i=0; i<G.maxSize; ++i)
        if(flag[i]==1)
            printf("number %d represents \"%s\"\n",i,G.vertex[i].label);

    //先打印每列的列标
    cout<<"\nThe message of Edge:\n ";
    for(int k=0; k<G.maxSize; ++k)
        if(flag[k]==1)
            printf("%3d",k);
    printf("\n");


    for(int i=0; i<G.maxSize; ++i) //邻接矩阵
    {
        if(flag[i]==1)
        {
            printf("%d",i);
            for(int j=0; j<G.maxSize; ++j)
                if(flag[j]==1)
                {
                    if(G.adjMatrix[i][j]==infiniteEdgeWt) printf("  -");//不可到达就输出横杠
                    else printf("%3d",G.adjMatrix[i][j]);
                }
            printf("\n");
        }
    }

    cout<<"\nThe message of color:\n";
    for(int i=0; i<G.maxSize; ++i)
        if(flag[i]==1)
        {
            printf("The color of number %d is ",i);
            if(G.vertex[i].color=='r') cout<<"red\n";
            else if(G.vertex[i].color=='g') cout<<"green\n";
            else if(G.vertex[i].color=='b') cout<<"blue\n";
            else if(G.vertex[i].color=='y') cout<<"yellow\n";
        }

    printf("\n\n");
}

void computePaths( WtGraph G )//计算并输出最短路径矩阵  ， 实验中练习1新增
{
    //打印每个下标代表的字符串，即顶点
    cout<<"\nThe message of Vertex:\n";
    for(int i=0; i<G.maxSize; ++i)
        if(flag[i]==1)
            printf("number %d represents \"%s\"\n",i,G.vertex[i].label);

    //先整理原始矩阵
    for(int k=0; k<G.maxSize; ++k)
    {
        if(flag[k]==1)
        {
            for(int i=0; i<G.maxSize; ++i)
            {
                if(flag[i]==1)
                {
                    for(int j=0; j<G.maxSize; ++j)
                    {
                        if(flag[j]==1&&G.adjMatrix[i][k]<infiniteEdgeWt&&G.adjMatrix[k][j]<infiniteEdgeWt&&G.adjMatrix[i][k]+G.adjMatrix[k][j]<G.adjMatrix[i][j])
                        {
                            G.adjMatrix[i][j]=G.adjMatrix[i][k]+G.adjMatrix[k][j];
                        }
                    }
                }

            }
        }

    }


    //先打印每列的列标

    cout<<"\nThe message of Shortest Path:\n ";
    for(int k=0; k<G.maxSize; ++k)
        if(flag[k]==1)
            printf("%3d",k);
    printf("\n");

    for(int i=0; i<G.maxSize; ++i) //再重新打印邻接矩阵
    {
        if(flag[i]==1)
        {
            printf("%d",i);
            for(int j=0; j<G.maxSize; ++j)
                if(flag[j]==1)
                {
                    if(G.adjMatrix[i][j]==infiniteEdgeWt) printf("  -");//不可到达就输出横杠
                    else printf("%3d",G.adjMatrix[i][j]);
                }
            printf("\n");
        }
    }
    printf("\n\n");

}


bool hasProperColoring( WtGraph G )//检查填色是否满足规则，即对每个点可以到达的点进行检测
{
    for(int i=0;i<G.maxSize;++i)
    {
        if(flag[i]==1)//检查每个在图中的点
        {
            for(int j=0;j<G.maxSize;++j)
            {
                if(flag[j]==1&&G.adjMatrix[i][j]!=infiniteEdgeWt)//两点之间可以到达
                {
                    if(G.vertex[i].color==G.vertex[j].color)
                        return false;
                }
            }
        }
    }

    return true;
}

bool areAllEven( WtGraph G )//测试图中每个顶点的度数是否都为偶数
{
    for(int i=0;i<G.maxSize;++i)
    {
        if(flag[i]==1)//检查每个在图中的点
        {
            int cnt=0;
            for(int j=0;j<G.maxSize;++j)
            {
                if(flag[j]==1&&G.adjMatrix[i][j]!=infiniteEdgeWt)//两点之间可以到达
                    cnt++;
            }

            if(cnt%2!=0) return false;//该点度数不为0
            cnt=0;
        }
    }

    return true;
}
