#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

void Make2DArray(int m,int n,int** &dm)
{
	dm=new int *[m];
	for(int i=0;i<m;++i)
		if((dm[i]=new int [n])==NULL)
			exit(0);
	
	cout<<"intput the array:\n";
	for(i=0;i<m;i++)
		for(int j=0;j<n;++j)
			cin>>dm[i][j];
}

void Delete2DArray(int m,int** &dm){
	for(int i=0;i<m;i++)
		delete[] dm[i];
	delete[]dm;
}

void print(int **dm,int n,int m){
	cout<<"The answer:\n";
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j)
			cout<<dm[i][j]<<"\t";
		cout<<endl;
	}
}


int main()
{
	int n,m;
	cout<<"input matrix size m,n:";
	cin>>m>>n;
	
	int **dm;
	Make2DArray(m,n,dm);
	print(dm,n,m);
	Delete2DArray(m,dm);
	return 0;
}


