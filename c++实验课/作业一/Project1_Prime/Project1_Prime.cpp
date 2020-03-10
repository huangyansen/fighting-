#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;
bool flag[105];


int main(){
	for(int i_=1;i_<=100;++i_)
		flag[i_]=true;	
	
	flag[1]=false;

	for(int i=2;i<=100;++i){
		if(flag[i]){//ÊÇËØÊý
			for(int j=2*i;j<=100;j+=i)
				flag[j]=false;
		}
	}
	
	for(int i1=1;i1<=100;++i1)
		if(flag[i1])
			cout<<i1<<endl;

	return 0;
}

