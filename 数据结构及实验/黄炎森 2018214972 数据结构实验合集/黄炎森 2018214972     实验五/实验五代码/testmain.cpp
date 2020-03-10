#include "wtgraph.h"

int main()
{
    WtGraph G;
    InitWtGraph(G,15);

    cout<<"-------------------Operation List-------------------\n";
    cout<<"+v:��Ӷ���v                 ?v:��������v\n";
    cout<<"-v:ɾ������v    !v w:ɾ������v��w�ı�\n";
    cout<<"=v w wt:���һ��������v��w�ıߵ���ͼ�У���ȨΪwt\n";
    cout<<"#v w:��������v��w������ߣ��������Ȩֵwt\n";
    cout<<"P:���㲢������·������     K:�����ɫ�Ƿ��������\n";
    cout<<"D:����ͼ��ÿ������Ķ����Ƿ�Ϊż��\n";
    cout<<"E:�п�                       F:����\n";
    cout<<"C:���                       Q:�˳�\n";
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
                     showStructure(G);//�޸�֮��չʾ
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
                     showStructure(G);//�޸�֮��չʾ
                     break;}
            case '!':{cout<<"Please input the Vertex1 and Vertex2: ";
                     char v1[20],v2[20];
                     cin>>v1>>v2;
                     removeEdge(G, v1, v2);
                     showStructure(G);//�޸�֮��չʾ
                     break;}
            case '=':{cout<<"Please input the Vertex1, Vertex2 and edge wight: ";
                     char v1[20],v2[20];
                     int wt;
                     cin>>v1>>v2>>wt;
                     insertEdge(G, v1, v2, wt);
                     showStructure(G);//�޸�֮��չʾ
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
