#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <set>
using namespace std;

const int defMaxGraphSize = 100,
          vertexLabelLength = 11,
          infiniteEdgeWt =0x7fffffff;

struct Vertex {//���㣨������Ϣ���ַ�����
	char label[vertexLabelLength];
	char color;//��ʾ�õ���ɫ(r,g,b,y)
};

struct WtGraph//ͼ�Ľṹ
{
    int maxSize, Size;//��󶥵����� ʵ�ʶ�����
    Vertex *vertex;//��̬���룬ָ�򶥵�������ַ������͵����飨�൱�ڶ���ָ�룩
    int** adjMatrix;//��ߵ��ڽӾ��󣬶���ָ��    ��ʼ��ȫΪ0
};

void InitWtGraph( WtGraph &G, int maxNumber );//����һ���յ�ͼ��Ϊ������㹻���ڴ�ռ䣬������maxNumber�������ͼ��(��̬����)
void DeWtGraph( WtGraph &G );//�ͷ�( free)�洢ͼռ�õĿռ�
int  getIndex( WtGraph &G, char *v );//�����ַ������ظõ��Ӧ�±����
int  Getedge( WtGraph G, int row, int col );//�����������㷵�ر�Ȩ
void setEdge( WtGraph &G, int row, int col, int wt );//��wt���±�Ȩ
void insertVertex( WtGraph &G, Vertex newVertex );//��ӵ�newVertex��ͼ�С�������������ͼ���Ѵ��ڣ����������
void insertEdge( WtGraph &G, char *v1, char *v2, int wt );//���һ������v1��v2������ߵ�ͼ�У������������
bool retrieveVertex( WtGraph G, char *v, Vertex &vData );//����Ϊtrue����vData���ص����ݣ����򷵻�false
bool GetedgeWeight( WtGraph G, char *v1, char *v2, int &wt );//����Ϊtrue����wt���ر�Ȩ�����򷵻�false
void removeVertex( WtGraph &G, char *v);//ǰ����ͼ��������v�� �������ͼ��ɾ������v��
void removeEdge( WtGraph &G, char *v1, char *v2 );//ǰ����ͼ��������v1��v2�� �������ͼ��ɾ������v1��v2������ߡ�
void Clear( WtGraph &G );//ɾ���еĵ�ͱ�
bool isEmpty( WtGraph G );
bool isFull( WtGraph G );
void showStructure( WtGraph G );//��������ʽ���ͼ�Ķ��㣬���ڽӾ�����ʽ�����(��Ȩֵ),���ͼΪ�գ��������Empty graph��
void computePaths( WtGraph G );//���㲢������·������  �� ʵ������ϰ1����
bool hasProperColoring( WtGraph G );//�����ɫ�Ƿ��������,ʵ������ϰ2����
bool areAllEven( WtGraph G );//����ͼ��ÿ������Ķ����Ƿ�Ϊż��, ʵ������ϰ3����
