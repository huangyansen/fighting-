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

void InitStack( struct Stack S, int maxNumber );
void DestroyStack( struct Stack S );
void Push( struct Stack S, ElemType newDataItem );
ElemType Pop( struct Stack S );
void clearStack( struct Stack S );
bool isEmpty( struct Stack S );
bool isFull( struct Stack S );
void showStructure( struct Stack S );
