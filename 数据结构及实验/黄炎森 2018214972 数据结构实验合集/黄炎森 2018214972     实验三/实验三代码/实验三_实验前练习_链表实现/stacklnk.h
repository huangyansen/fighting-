#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#define MaxStackSize 100
using namespace std;

typedef int ElemType;

struct StackNode {//链表的每个节点
    ElemType  dataltem;
    StackNode *next;
};

struct Stack {//栈结构
    int	 Size;
    StackNode *top;
};

void InitStack( Stack &S );
void DestroyStack( Stack S );
void Push( Stack &S, ElemType newDataItem );
ElemType Pop( Stack &S );
void clearStack( Stack &S );
bool isEmpty( Stack S );
bool isFull( Stack S );
void showStructure( Stack S );


