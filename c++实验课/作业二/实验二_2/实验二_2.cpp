// 实验二_2.cpp : Defines the entry point for the console application.
// 另一种申请动态空间的方式

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define m 3   /* row */
#define n 4   /* column */

int **creat2d(int mm,int nn)
{
    int **a;
    int j;
    a=(int**)malloc(sizeof(int*)*mm);//mm个行
    for(j=0;j<mm;j++)
        a[j]=(int*)malloc(sizeof(int*)*nn);//每行nn个数
    return a;
}


void main()
{
    int i,j;
    int **s;
    s=creat2d(m,n);
 
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            s[i][j]=i*2+j;//s当做二维数组使用
            printf("s[%d][%d]=%d ",i,j,s[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<m;i++)//先free掉m个行指针
    {
        free(s[i]);
        s[i]=NULL;//free之后要置为null，防止野指针
    }
    free(s);
    s=NULL;//防止野指针
}
 
int **creat2d(int mm,int nn)
{
    int **a;
    int j;
    a=(int**)malloc(sizeof(int*)*mm);//mm个行
    for(j=0;j<mm;j++)
        a[j]=(int*)malloc(sizeof(int*)*nn);//每行nn个数
    return a;
}
