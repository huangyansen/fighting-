#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

struct ExprTreeNode
{
    char data;
    ExprTreeNode *left, *right;
};

void InitExprTreeNode ( ExprTreeNode *root, char elem, ExprTreeNode *leftPtr, ExprTreeNode *rightPtr );
void InitExprTree( ExprTreeNode* &root );//为什么老师给的没有引用？？？
void DeExprTree( ExprTreeNode *root );
void build( ExprTreeNode* &root );
void expression( ExprTreeNode *root );
int evaluate( ExprTreeNode *root );
void cleartree( ExprTreeNode *root );
void showStructure( ExprTreeNode *root );
void showSub( ExprTreeNode *root, ExprTreeNode *p, int level );
ExprTreeNode* ExprTreeCopy( ExprTreeNode *T ,ExprTreeNode* &c_root);   // 实验中练习2新增,复制一棵树(返回一棵树的指针)
void commute( ExprTreeNode *root ); //实验中练习3新增  交换表达树中的每个运算符的两个操作数
