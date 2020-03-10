#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

template <typename T>
void Make2DArray(int m,int n,int t,T** &dm,T** &dm_)
{
	dm=new T *[m];
	for(int i=0;i<m;++i)
		if((dm[i]=new T [n])==NULL)
			exit(0);

	dm_=new T *[n];
	for(i=0;i<n;++i)
		if((dm_[i]=new T [t])==NULL)
			exit(0);

	cout<<"input the first matrix:\n";
	for(i=0;i<m;++i)
		for(int j=0;j<n;++j)
			cin>>dm[i][j];

	cout<<"input the second matrix:\n";
	for(i=0;i<n;++i)
		for(int j=0;j<t;++j)
			cin>>dm_[i][j];
	
	T** temp=new T *[m];
	for(i=0;i<m;++i)
		if((temp[i]=new T [t])==NULL)
			exit(0);

	for(i=0;i<m;++i)
		for(int j=0;j<t;++j)
			temp[i][j]=0;

	for(i=0;i<m;++i)
		for(int j=0;j<t;++j)
			for(int k=0;k<n;++k)
				temp[i][j]+=dm[i][k]*dm_[k][j];

	cout<<"The answer is:\n";
	for(i=0;i<m;++i){
		for(int j=0;j<t;++j)
			cout<< temp[i][j] <<'\t';
		cout<<endl;
	}
	
	for(i=0;i<m;i++)
		delete[] temp[i];
	delete[]temp;

}

template <typename T>
void Delete2DArray(int m,int n,T** dm,T** dm_)
{
	for(int i=0;i<m;i++)
		delete[] dm[i];
	delete[]dm;

	for(i=0;i<n;i++)
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
	cout<<"Please enter data type(1:int  2:double):";
	int t;
	M:cin>>t;
	if(t==1){//隐式实例化
		Make2DArray(m1,n1,n2,dm1,dm_1);
		Delete2DArray(m1,n1,dm1,dm_1);
	}
	else if(t==2){
		Make2DArray(m1,n1,n2,dm2,dm_2);
		Delete2DArray(m1,n1,dm2,dm_2);
	}
	else{
		cout<<"error! Please input the correct number!\n";
		goto M;
	}
	return 0;
}
