// ʵ���_2.cpp : Defines the entry point for the console application.
// ��һ�����붯̬�ռ�ķ�ʽ

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
    a=(int**)malloc(sizeof(int*)*mm);//mm����
    for(j=0;j<mm;j++)
        a[j]=(int*)malloc(sizeof(int*)*nn);//ÿ��nn����
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
            s[i][j]=i*2+j;//s������ά����ʹ��
            printf("s[%d][%d]=%d ",i,j,s[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<m;i++)//��free��m����ָ��
    {
        free(s[i]);
        s[i]=NULL;//free֮��Ҫ��Ϊnull����ֹҰָ��
    }
    free(s);
    s=NULL;//��ֹҰָ��
}
 
int **creat2d(int mm,int nn)
{
    int **a;
    int j;
    a=(int**)malloc(sizeof(int*)*mm);//mm����
    for(j=0;j<mm;j++)
        a[j]=(int*)malloc(sizeof(int*)*nn);//ÿ��nn����
    return a;
}
