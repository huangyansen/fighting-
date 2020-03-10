#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void jc(unsigned __int64 n){
	unsigned __int64 now=1,next=1;
	for(unsigned __int64 i=1;i<n;++i){
		now*=i;//当前一个
		next=now*(i+1);//下一个
		if(next/now!=(i+1)) { printf("在%I64u处溢出，溢出前: %I64u! : %I64u\n",i+1,i,now); return;}
	}
	printf("未溢出: %I64d! : %I64u\n",n,next);//未溢出
}

int main()
{
	unsigned __int64 n;//直接用最大的数据范围
	scanf("%I64u",&n);
	jc(n);
	return 0;
}
