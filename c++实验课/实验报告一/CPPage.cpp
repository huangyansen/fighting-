#include "CPPage.h"


CPPage::CPPage()//初始化
{
	this->RH=NULL;
	this->EH=NULL;
	countCPP++;
}


void CPPage::AddR(Rectangle R)//增加一个矩形
{
	Reclist* pnew= new Reclist(R,NULL,NULL);//注意初始化

	if(countR==0)//第一个节点
	{
		this->RH=pnew;
		this->RH->next=this->RH;
		this->RH->prior=this->RH;
		countR++;
		return;
	}

	pnew->next=this->RH;
	pnew->prior=this->RH->prior;
	this->RH->prior->next=pnew;
	this->RH->prior=pnew;
	
	countR++;
}


void CPPage::AddE(ellipse E)//增加一个椭圆 
{
	Ellist* pnew= new Ellist(E,NULL,NULL);

	if(countE==0)//第一个节点
	{
		this->EH=pnew;
		this->EH->next=this->EH;
		this->EH->prior=this->EH;
		countE++;
		return;
	}

	pnew->next=this->EH;
	pnew->prior=this->EH->prior;
	this->EH->prior->next=pnew;
	this->EH->prior=pnew;

	countE++;
}

void CPPage::DelR()//删掉上一个矩形
{
	if(countR==0)
	{
		cout<<"页面内无矩形，不能删除\n";
		return;
	}

	Reclist* temp= this->RH->prior;
	temp->prior->next=this->RH;
	this->RH->prior=temp->prior;
	delete temp;
	countR--;
}

void CPPage::DelE()//删掉上一个椭圆
{
	if(EH==NULL)
	{
		cout<<"页面内无椭圆，不能删除\n";
		return;
	}

	Ellist* temp= this->EH->prior;
	temp->prior->next=this->EH;
	this->EH->prior=temp->prior;
	delete temp;
	countE--;
}

void CPPage::show()
//作为友元类，展示其中矩形和椭圆个数以及文本信息（私有）的show函数，可以直接访问矩形和椭圆的任何成员
{
	cout<<"\n\n--------CPPage--------\n";
	cout<<"The number of Rectangle is :"<<countR<<endl;
	Reclist* temp1=this->RH;
	for(int i=0;i<countR;++i)
	{	
		(temp1->rec).text.show();
		cout<<"\n";
		temp1=temp1->next;
	}
	

	cout<<"The number of ellipse is :"<<countE<<endl;
	Ellist* temp2=this->EH;
	for(int j=0;j<countE;++j)
	{
		(temp2->ell).text.show();
		cout<<"\n";
		temp2=temp2->next;
	}
	cout<<"----------------------\n";
}


int CPPage::countE=0;
int CPPage::countR=0;
int CPPage::countCPP=0;