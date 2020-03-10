#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

void Make2DArray(int m,int n,int t,int** &dm,int** &dm_)
{
	dm=new int *[m];
	for(int i=0;i<m;++i)
		if((dm[i]=new int [n])==NULL)
			exit(0);
	
	dm_=new int *[n];
	for(int i=0;i<n;++i)
		if((dm[i]=new int [t])==NULL)
			exit(0);
	
	int** temp=new int *[m];//暂存结果数组,并且显示它，最后在函数内释放
	for(int i=0;i<n;++i)
		if((dm[i]=new int [t])==NULL)
			exit(0);

	for(int i=0;i<m;++i)
		for(int j=0;j<t;++j)
			temp[i][j]=0;

	for(int i=0;i<m;++i)
		for(int j=0;j<t;++j)
			for(int k=0;k<n;++k)
				temp[i][j]+=dm[i][k]+dm_[k][j];

	cout<<"The answer is:\n";
	for(int i=0;i<m;++i){
		for(int j=0;j<t;++j)
			cout<< temp[i][j] <<'\t';
		cout<<endl;
	}
	
	for(int i=0;i<m;i++)
		delete[] temp[i];
	delete[]temp;

}

void Make2DArray(int m,int n,int t,double** &dm,double** &dm_)
{
	dm=new double *[m];
	for(int i=0;i<m;++i)
		if((dm[i]=new double [n])==NULL)
			exit(0);
	
	dm_=new double *[n];
	for(int i=0;i<n;++i)
		if((dm[i]=new double [t])==NULL)
			exit(0);
	
	double** temp=new double *[m];
	for(int i=0;i<n;++i)
		if((dm[i]=new double [t])==NULL)
			exit(0);

	for(int i=0;i<m;++i)
		for(int j=0;j<t;++j)
			temp[i][j]=0;

	for(int i=0;i<m;++i)
		for(int j=0;j<t;++j)
			for(int k=0;k<n;++k)
				temp[i][j]+=dm[i][k]+dm_[k][j];

	cout<<"The answer is:\n";
	for(int i=0;i<m;++i){
		for(int j=0;j<t;++j)
			cout<< temp[i][j] <<'\t';
		cout<<endl;
	}
	
	for(int i=0;i<m;i++)
		delete[] temp[i];
	delete[]temp;

}

void Make2DArray(int m,int n,int t,char** &dm,char** &dm_)//注意char相乘
{
	dm=new char *[m];
	for(int i=0;i<m;++i)
		if((dm[i]=new char [n])==NULL)
			exit(0);
	
	dm_=new char *[n];
	for(int i=0;i<n;++i)
		if((dm[i]=new char [t])==NULL)
			exit(0);
	
	char** temp=new char *[m];
	for(int i=0;i<n;++i)
		if((dm[i]=new char [t])==NULL)
			exit(0);
	
	for(int i=0;i<m;++i)//初始化
		for(int j=0;j<t;++j)
			temp[i][j]='a';

	for(int i=0;i<m;++i)
		for(int j=0;j<t;++j)
			for(int k=0;k<n;++k)
				temp[i][j]=(temp[i][j]-'a'+dm[i][k]-'a'+dm_[k][j]-'a')%25+'a';

	cout<<"The answer is:\n";
	for(int i=0;i<m;++i){
		for(int j=0;j<t;++j)
			cout<< temp[i][j] <<'\t';
		cout<<endl;
	}
	
	for(int i=0;i<m;i++)
		delete[] temp[i];
	delete[]temp;

}

void Delete2DArray(int m,int n,int** dm,int** dm_)
{
	for(int i=0;i<m;i++)
		delete[] dm[i];
	delete[]dm;

	for(int i=0;i<n;i++)
		delete[] dm_[i];
	delete[]dm_;
}

void Delete2DArray(int m,int n,double** dm,double** dm_)
{
	for(int i=0;i<m;i++)
		delete[] dm[i];
	delete[]dm;

	for(int i=0;i<n;i++)
		delete[] dm_[i];
	delete[]dm_;
}

void Delete2DArray(int m,int n,char** dm,char** dm_)
{
	for(int i=0;i<m;i++)
		delete[] dm[i];
	delete[]dm;

	for(int i=0;i<n;i++)
		delete[] dm_[i];
	delete[]dm_;
}


int main()
{
	int m1,n1,m2,n2;
	cout<<"enter the number of rows and columns of the first matrix:\n";
	cin>>m1>>n1;
	cout<<"enter the number of rows and columns of the second matrix:\n";
	cin>>m2>>n2;

	if(n1!=m2)//不能相乘,重新输入
	{
		cout<<"Wrong input!\n";
		goto M;
	}
	
	int **dm1,**dm_1;
	double **dm2,**dm_2;
	char **dm3,**dm_3;
	cout<<"Please enter data type(1:int  2:double 3:char):";
	int t;
	M:cin>>t;
	if(t==1){
		Make2DArray(m1,n1,n2,dm1,dm_1);
		Delete2DArray(m1,n1,dm1,dm_1);
	}
	else if(t==2){
		Make2DArray(m1,n1,n2,dm2,dm_2);
		Delete2DArray(m1,n1,dm2,dm_2);
	}
	else if(t==3){
		Make2DArray(m1,n1,n2,dm3,dm_3);
		Delete2DArray(m1,n1,dm3,dm_3);
	}
	else{
		cout<<"error! Please input the correct number!\n";
		goto M;
	}
	return 0;
}
