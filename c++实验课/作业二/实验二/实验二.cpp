#include "stdafx.h"
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

void Make2DArray(int m,int n,double** &dm)
{
	dm=new double *[m];
	for(int i=0;i<m;++i)
		if((dm[i]=new double [n])==NULL)
			exit(0);
	
	cout<<"intput the array:\n";
	for(i=0;i<m;i++)
		for(int j=0;j<n;++j)
			cin>>dm[i][j];
}

void Make2DArray(int m,int n,char** &dm)
{
	dm=new char *[m];
	for(int i=0;i<m;++i)
		if((dm[i]=new char [n])==NULL)
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

void Delete2DArray(int m,double** &dm){
	for(int i=0;i<m;i++)
		delete[] dm[i];
	delete[]dm;
}

void Delete2DArray(int m,char** &dm){
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

void print(double **dm,int n,int m){
	cout<<"The answer:\n";
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j)
			cout<<dm[i][j]<<"\t";
		cout<<endl;
	}
}

void print(char **dm,int n,int m){
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
	
	int **dm1;
	double **dm2;
	char **dm3;
	cout<<"Please enter data type(1:int  2:double 3:char):";
	int t;
	M:cin>>t;
	if(t==1){
		Make2DArray(m,n,dm1);
		print(dm1,n,m);
		Delete2DArray(m,dm1);
	}
	else if(t==2){
		Make2DArray(m,n,dm2);
		print(dm2,n,m);
		Delete2DArray(m,dm2);
	}
	else if(t==3){
		Make2DArray(m,n,dm3);
		print(dm3,n,m);
		Delete2DArray(m,dm3);
	}
	else{
		cout<<"error! Please input the correct number!\n";
		goto M;
	}
	return 0;
}
