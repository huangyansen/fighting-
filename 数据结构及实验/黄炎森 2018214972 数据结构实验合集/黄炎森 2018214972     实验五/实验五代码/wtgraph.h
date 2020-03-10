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

struct Vertex {//顶点（顶点信息是字符串）
	char label[vertexLabelLength];
	char color;//表示该点颜色(r,g,b,y)
};

struct WtGraph//图的结构
{
    int maxSize, Size;//最大顶点数， 实际顶点数
    Vertex *vertex;//动态申请，指向顶点个数的字符串类型的数组（相当于二级指针）
    int** adjMatrix;//存边的邻接矩阵，二级指针    初始化全为0
};

void InitWtGraph( WtGraph &G, int maxNumber );//创建一个空的图。为其分配足够的内存空间，它包含maxNumber个顶点的图。(动态分配)
void DeWtGraph( WtGraph &G );//释放( free)存储图占用的空间
int  getIndex( WtGraph &G, char *v );//根据字符串返回该点对应下标序号
int  Getedge( WtGraph G, int row, int col );//根据两个顶点返回边权
void setEdge( WtGraph &G, int row, int col, int wt );//用wt更新边权
void insertVertex( WtGraph &G, Vertex newVertex );//添加点newVertex到图中。如果这个顶点在图中已存在，则更新它。
void insertEdge( WtGraph &G, char *v1, char *v2, int wt );//添加一条连接v1和v2的无向边到图中，已有则更新它
bool retrieveVertex( WtGraph G, char *v, Vertex &vData );//有则为true并且vData返回点数据；否则返回false
bool GetedgeWeight( WtGraph G, char *v1, char *v2, int &wt );//有则为true并且wt返回边权；否则返回false
void removeVertex( WtGraph &G, char *v);//前提是图包括顶点v。 结果：从图中删除顶点v。
void removeEdge( WtGraph &G, char *v1, char *v2 );//前提是图包括顶点v1和v2。 结果：从图中删除连接v1和v2的无向边。
void Clear( WtGraph &G );//删所有的点和边
bool isEmpty( WtGraph G );
bool isFull( WtGraph G );
void showStructure( WtGraph G );//以数组形式输出图的顶点，以邻接矩阵形式输出边(带权值),如果图为空，则输出“Empty graph”
void computePaths( WtGraph G );//计算并输出最短路径矩阵  ， 实验中练习1新增
bool hasProperColoring( WtGraph G );//检查填色是否满足规则,实验中练习2新增
bool areAllEven( WtGraph G );//测试图中每个顶点的度数是否都为偶数, 实验中练习3新增
