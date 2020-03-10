//放头文件,宏定义,函数定义

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#define Maxn 100

using namespace std;

typedef char ElemType;

struct List{
    ElemType c;
    List *prior;
    List *next;
};

void InitList(List* &head);
void DestroyList(List* &head);
void insertList(List* &L,ElemType newData);
void removeList(List* &L,List* head);
void replaceList(List* &L,ElemType newData);
void clearList(List* &head);
bool isEmpty(List* head);
bool isFull(List* head);
void gotoBegining(List* &L,List* head);
void gotoEnd(List* &L,List* head);
bool gotoNext(List* &L,List* head);
bool gotoPrior(List* &L,List* head);
void getCursor(List* L,List* head);
void showStructure(List* head);
void reverseList(List* &head);

