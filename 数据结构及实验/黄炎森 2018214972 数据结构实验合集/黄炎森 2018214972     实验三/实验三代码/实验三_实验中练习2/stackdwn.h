#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#define MaxStackSize 100
using namespace std;

typedef int ElemType;

struct Stack{//�����µ�����ʵ��,��ʱջԪ�ظ���Ϊ(S.maxsize-top)��
    int top;
    int maxsize;
    ElemType *dataItems;
};

void InitStack( Stack &S, int maxNumber );
void DestroyStack( Stack S );
void Push( Stack &S, ElemType newDataItem );
ElemType Pop( Stack &S );
void clearStack( Stack &S );
bool isEmpty( Stack S );
bool isFull( Stack S );
void showStructure( Stack S );
