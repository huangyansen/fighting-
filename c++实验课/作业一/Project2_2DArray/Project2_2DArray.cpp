#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int **p=(int**)malloc(sizeof(int*)*n);//��Ԫ��

	for(int i=0;i<n;++i){
		//p[i]=(int*)malloc(sizeof(int)*m);//��Ԫ��
		for(int j=0;j<m;++j)
			scanf("%d",&p[i][j]);//��i�е�j��Ԫ�صĵ�ַ
	}

	cout<<"����������:"<<endl;
	for(int I=0;I<n;++I){
		for(int J=0;J<m;++J)
			printf("%d ",p[I][J]);
		printf("\n");
		free(p[I]);
	}
	free(p);
	return 0;
}

