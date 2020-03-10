#include "wtgraph.h"

int main()
{
    WtGraph G;
    InitWtGraph(G,15);

    cout<<"-------------------Operation List-------------------\n";
    cout<<"+v:添加顶点v                 ?v:检索顶点v\n";
    cout<<"-v:删除顶点v    !v w:删除连接v和w的边\n";
    cout<<"=v w wt:添加一条顶点是v和w的边到到图中，边权为wt\n";
    cout<<"#v w:检索连接v和w的无向边，并且输出权值wt\n";
    cout<<"P:计算并输出最短路径矩阵     K:检查填色是否满足规则\n";
    cout<<"D:测试图中每个顶点的度数是否都为偶数\n";
    cout<<"E:判空                       F:判满\n";
    cout<<"C:清空                       Q:退出\n";
    cout<<"----------------------------------------------------\n";

    char t;
    while(1)
    {
        cout<<"Please input the operation:\n";
        cin>>t;
        switch (t)
        {
            case '+':{cout<<"Please input the message of Vertex(name,color): ";
                     Vertex newVertex;
                     cin>>newVertex.label>>newVertex.color;
                     insertVertex(G, newVertex);
                     showStructure(G);//修改之后展示
                     break;}
            case '?':{cout<<"Please input the Vertex: ";
                     char v[20];
                     cin>>v;
                     int temp=getIndex(G, v);
                     if(temp==-1)
                        cout<<"There is no such point!\n\n";
                     else cout<<"The number of "<<v<<" is "<<temp<<"\n\n";
                     break;}
            case '-':{cout<<"Please input the Vertex: ";
                     char v[20];
                     cin>>v;
                     removeVertex(G, v);
                     showStructure(G);//修改之后展示
                     break;}
            case '!':{cout<<"Please input the Vertex1 and Vertex2: ";
                     char v1[20],v2[20];
                     cin>>v1>>v2;
                     removeEdge(G, v1, v2);
                     showStructure(G);//修改之后展示
                     break;}
            case '=':{cout<<"Please input the Vertex1, Vertex2 and edge wight: ";
                     char v1[20],v2[20];
                     int wt;
                     cin>>v1>>v2>>wt;
                     insertEdge(G, v1, v2, wt);
                     showStructure(G);//修改之后展示
                     break;}
            case '#':{cout<<"Please input the Vertex1 and Vertex2: ";
                     char v1[20],v2[20];
                     cin>>v1>>v2;
                     int wt;
                     if(GetedgeWeight(G, v1, v2, wt))
                        printf("The edge between %s and %s is %d\n\n",v1,v2,wt);
                     break;}
            case 'E':{if(isEmpty(G))
                        cout<<"The graph is empty!\n";
                     else cout<<"The graph is not empty!\n\n";
                     break;}
            case 'F':{if(isFull(G))
                        cout<<"The graph is full!\n";
                     else cout<<"The graph is not full!\n\n";
                     break;}
            case 'C':{Clear(G);
                     break;}
            case 'Q':return 0;
                     break;
            case 'P':computePaths(G);
                     break;
            case 'K':if(hasProperColoring(G))
                        cout<<"The plan of color is right!\n\n";
                     else cout<<"The plan of color is right!\n\n";
                     break;
            case 'D':if(areAllEven(G))
                        cout<<"All point have even degrees!\n\n";
                     else cout<<"Not all point have even degrees!\n\n";
            default:cout<<"Wrong Input! Please input again!\n";
        }
    }

    return 0;
}
