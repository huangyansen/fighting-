#include "wtgraph.h"

int flag[105];//Ϊ0��ʾ����±�û�д���һ���ַ�����Ϊ1����   ����±�Ҳ�Ǵ�0��ʼ
set<int>s;//���ַ����Ķ��������������ҵ����ַ����Ƿ��ڵ�ǰ��ͼ���棬 �浱ǰͼ�еĵ�

void InitWtGraph( WtGraph &G, int maxNumber )//����һ���յ�ͼ��Ϊ������㹻���ڴ�ռ䣬������maxNumber�������ͼ��(��̬����)
{
    G.Size=0;//��ʼ����ͼ��һ������Ҳû��
    G.maxSize=maxNumber;//�����maxNumber�������ͼ
    G.vertex= new Vertex[maxNumber];//���䶥��

    G.adjMatrix=new int*[maxNumber];
    for(int i=0; i<maxNumber; ++i)
        G.adjMatrix[i]=new int[maxNumber];//��̬�����ά����

    for(int i=0; i<maxNumber; ++i) //��ʼ������,ȫΪ���ɵ�������ֵ;���Լ�Ϊ0
        for(int j=0; j<maxNumber; ++j)
        {
            if(i==j) G.adjMatrix[i][j]=0;
            else G.adjMatrix[i][j]=infiniteEdgeWt;
        }


    memset(flag,0,sizeof(flag));
}

void DeWtGraph( WtGraph &G )//�ͷŴ洢ͼռ�õĿռ�
{
    delete G.vertex;

    for(int i=0; i<G.maxSize; ++i)
        delete [] G.adjMatrix[i];
    delete G.adjMatrix;
}

int  getIndex( WtGraph &G, char *v )//���ݶ����ַ�����Ϣ��������һ����,û���򷵻�-1
{
    for(int i=0; i<G.maxSize; ++i)
    {
        if(strcmp(G.vertex[i].label,v)==0)
            return i;
    }

    return -1;
}

int  Getedge( WtGraph G, int row, int col )//�����������㷵�ر�Ȩ,û���򷵻�-1
{
    if(row>G.maxSize||col>G.maxSize)
        return -1;

    return G.adjMatrix[row-1][col-1];
}

void setEdge( WtGraph &G, int row, int col, int wt )//��wt���±�Ȩ
{
    if(row>G.maxSize||col>G.maxSize)
        cout<<"Refresh Fail!\n";

    G.adjMatrix[row-1][col-1]=wt;
    cout<<"Refresh success!\n";
}

int trans(char s[])//���ַ���ͨ��������ת��ΪΨһ����
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


void insertVertex( WtGraph &G, Vertex newVertex )//��ӵ�newVertex��ͼ�С�������������ͼ���Ѵ��ڣ����ùܡ�(ͼ�Ѵ���)
{
    //ͨ����������(0,maxNumber-1)������Щ�±겻�ڵ�ǰͼ��
    int temp=trans(newVertex.label);

    if(s.count(temp))//���Ѿ�����
    {
        cout<<"Already exist!\n";
        return;
    }

    //�㲻�ڵ�ǰͼ��
    s.insert(temp);//����ǰͼ�м���һ���㣨����Ҳ�����ˣ�
    G.Size++;
    for(int i=0; i<G.maxSize; ++i)
    {
        if(flag[i]==0)//��ʾ����±�û�б�ʾһ���ַ���        �ǵ����������а�flag��Ϊ0������
        {
            strcpy(G.vertex[i].label,newVertex.label);//���±������ַ���
            G.vertex[i].color=newVertex.color;
            flag[i]=1;//��ʾ�ù���
            break;
        }
    }
}

void insertEdge( WtGraph &G, char *v1, char *v2, int wt )//���һ������v1��v2������ߵ�ͼ�У������������
{
    int temp1=trans(v1),temp2=trans(v2);
    if(s.count(temp1)==0||s.count(temp2)==0)//������ͼ�������㶼����
    {
        cout<<"Not all of the two points are in the diagram!\n";
        return;
    }

    //�����㶼��ͼ����
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

        if(mark==2)//��������±궼�ҵ���
            break;
    }

    G.adjMatrix[a][b]=G.adjMatrix[b][a]=wt;
}


bool retrieveVertex( WtGraph G, char *v, Vertex &vData )//����Ϊtrue����vData���ص��±ꣻ���򷵻�false
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

bool GetedgeWeight( WtGraph G, char *v1, char *v2, int &wt )//����Ϊtrue����wt���ر�Ȩ�����򷵻�false
{
    int temp1=trans(v1),temp2=trans(v2);
    if(s.count(temp1)==0||s.count(temp2)==0)//������ͼ�������㶼����
    {
        cout<<"Not all of the two points are in the diagram!\n";
        return false;
    }

    //�����㶼��ͼ����
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

        if(mark==2)//��������±궼�ҵ���
            break;
    }

    wt=G.adjMatrix[a][b];
    return true;
}

void removeVertex( WtGraph &G, char *v)//ǰ����ͼ��������v�� �������ͼ��ɾ������v��
{
    int temp=trans(v);

    if(s.count(temp)==0)//ͼ���޴˵�
    {
        cout<<"The is no such point!\n";
        return;
    }

    int a;//ɾ�������   ���ڽӾ���ĸ��и�����Ϊ0�� �������ָ���д洢���ַ���ɾ��(ͨ��setɾ����Ӧ������������)
    for(int i=0; i<G.maxSize; ++i)
    {
        if(strcmp(G.vertex[i].label,v)==0)//������.  ����->
        {
            a=i;
            break;
        }
    }
    flag[a]=0;//��ʾ�����û��������

    for(int i=0; i<G.maxSize; ++i)
        G.adjMatrix[i][a]=G.adjMatrix[a][i]=0;

    s.erase(temp);
    G.Size--;
}

void removeEdge( WtGraph &G, char *v1, char *v2 )//ǰ����ͼ��������v1��v2�� �������ͼ��ɾ������v1��v2������ߡ�
{
    int temp1=trans(v1),temp2=trans(v2);
    if(s.count(temp1)==0||s.count(temp2)==0)//������ͼ�������㶼����
    {
        cout<<"Not all of the two points are in the diagram!\n";
        return;
    }

    //�����㶼��ͼ����
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

        if(mark==2)//��������±궼�ҵ���
            break;
    }

    G.adjMatrix[a][b]=G.adjMatrix[b][a]=infiniteEdgeWt;
}


void Clear( WtGraph &G )//ɾ���еĵ�ͱ� (ͨ�����set����ʾɾ����) , ���ñ�Ȩ��ɾ��
{
    G.Size=0;
    s.clear();
    memset(flag,0,sizeof(flag));

    for(int i=0; i<G.maxSize; ++i) //��ʼ�����룬�Լ����Լ�Ϊ0������ȫΪ-1
        for(int j=0; j<G.maxSize; ++j)
        {
            if(i==j) G.adjMatrix[i][j]=0;
            else G.adjMatrix[i][j]=infiniteEdgeWt;
        }
}

bool isEmpty( WtGraph G )//������޶���,�޶����򷵻���
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

void showStructure( WtGraph G )//��������ʽ���ͼ�Ķ��㣬���ڽӾ�����ʽ�����(��Ȩֵ),���ͼΪ�գ��������Empty graph��
{
    if(isEmpty(G))
    {
        cout<<"Empty graph!\n";
        return;
    }

    //��ӡÿ���±������ַ�����������
    cout<<"\nThe message of Vertex:\n";
    for(int i=0; i<G.maxSize; ++i)
        if(flag[i]==1)
            printf("number %d represents \"%s\"\n",i,G.vertex[i].label);

    //�ȴ�ӡÿ�е��б�
    cout<<"\nThe message of Edge:\n ";
    for(int k=0; k<G.maxSize; ++k)
        if(flag[k]==1)
            printf("%3d",k);
    printf("\n");


    for(int i=0; i<G.maxSize; ++i) //�ڽӾ���
    {
        if(flag[i]==1)
        {
            printf("%d",i);
            for(int j=0; j<G.maxSize; ++j)
                if(flag[j]==1)
                {
                    if(G.adjMatrix[i][j]==infiniteEdgeWt) printf("  -");//���ɵ����������
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

void computePaths( WtGraph G )//���㲢������·������  �� ʵ������ϰ1����
{
    //��ӡÿ���±������ַ�����������
    cout<<"\nThe message of Vertex:\n";
    for(int i=0; i<G.maxSize; ++i)
        if(flag[i]==1)
            printf("number %d represents \"%s\"\n",i,G.vertex[i].label);

    //������ԭʼ����
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


    //�ȴ�ӡÿ�е��б�

    cout<<"\nThe message of Shortest Path:\n ";
    for(int k=0; k<G.maxSize; ++k)
        if(flag[k]==1)
            printf("%3d",k);
    printf("\n");

    for(int i=0; i<G.maxSize; ++i) //�����´�ӡ�ڽӾ���
    {
        if(flag[i]==1)
        {
            printf("%d",i);
            for(int j=0; j<G.maxSize; ++j)
                if(flag[j]==1)
                {
                    if(G.adjMatrix[i][j]==infiniteEdgeWt) printf("  -");//���ɵ����������
                    else printf("%3d",G.adjMatrix[i][j]);
                }
            printf("\n");
        }
    }
    printf("\n\n");

}


bool hasProperColoring( WtGraph G )//�����ɫ�Ƿ�������򣬼���ÿ������Ե���ĵ���м��
{
    for(int i=0;i<G.maxSize;++i)
    {
        if(flag[i]==1)//���ÿ����ͼ�еĵ�
        {
            for(int j=0;j<G.maxSize;++j)
            {
                if(flag[j]==1&&G.adjMatrix[i][j]!=infiniteEdgeWt)//����֮����Ե���
                {
                    if(G.vertex[i].color==G.vertex[j].color)
                        return false;
                }
            }
        }
    }

    return true;
}

bool areAllEven( WtGraph G )//����ͼ��ÿ������Ķ����Ƿ�Ϊż��
{
    for(int i=0;i<G.maxSize;++i)
    {
        if(flag[i]==1)//���ÿ����ͼ�еĵ�
        {
            int cnt=0;
            for(int j=0;j<G.maxSize;++j)
            {
                if(flag[j]==1&&G.adjMatrix[i][j]!=infiniteEdgeWt)//����֮����Ե���
                    cnt++;
            }

            if(cnt%2!=0) return false;//�õ������Ϊ0
            cnt=0;
        }
    }

    return true;
}
