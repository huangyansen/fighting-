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
void InitExprTree( ExprTreeNode* &root );//Ϊʲô��ʦ����û�����ã�����
void DeExprTree( ExprTreeNode *root );
void build( ExprTreeNode* &root );
void expression( ExprTreeNode *root );
int evaluate( ExprTreeNode *root );
void cleartree( ExprTreeNode *root );
void showStructure( ExprTreeNode *root );
void showSub( ExprTreeNode *root, ExprTreeNode *p, int level );
ExprTreeNode* ExprTreeCopy( ExprTreeNode *T ,ExprTreeNode* &c_root);   // ʵ������ϰ2����,����һ����(����һ������ָ��)
void commute( ExprTreeNode *root ); //ʵ������ϰ3����  ����������е�ÿ�������������������
