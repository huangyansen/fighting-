#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#define MaxStackSize 100
using namespace std;

typedef int ElemType;

struct Stack{
    int top;
    int maxsize;
    ElemType *dataItems;
};

void InitStack( Stack &S, int maxNumber ); //为什么老师给的代码里面没有引用？？？？？
void DestroyStack( Stack S );
void Push( Stack &S, ElemType newDataItem );
ElemType Pop( Stack &S );
void clearStack( Stack &S );
bool isEmpty( Stack S );
bool isFull( Stack S );
void showStructure( Stack S );
