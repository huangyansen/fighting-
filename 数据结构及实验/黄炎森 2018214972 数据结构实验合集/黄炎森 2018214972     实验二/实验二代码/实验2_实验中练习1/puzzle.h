#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>

using namespace std;
typedef char Elemtype;

struct List{
    Elemtype c;
    List* prior;
    List* next;
};

void InitPuzzle(List* &head, char answ[] , char init[]);
void shiftLeft(List* &head);
void swapEnds(List* &head);
void display(List* head);
bool issolve(List* head,char answ[]);
