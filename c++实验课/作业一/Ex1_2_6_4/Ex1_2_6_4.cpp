#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void jc(unsigned __int64 n){
	unsigned __int64 now=1,next=1;
	for(unsigned __int64 i=1;i<n;++i){
		now*=i;//��ǰһ��
		next=now*(i+1);//��һ��
		if(next/now!=(i+1)) { printf("��%I64u����������ǰ: %I64u! : %I64u\n",i+1,i,now); return;}
	}
	printf("δ���: %I64d! : %I64u\n",n,next);//δ���
}

int main()
{
	unsigned __int64 n;//ֱ�����������ݷ�Χ
	scanf("%I64u",&n);
	jc(n);
	return 0;
}
