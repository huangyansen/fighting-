#include "CPPage.h"


CPPage::CPPage()//��ʼ��
{
	this->RH=NULL;
	this->EH=NULL;
	countCPP++;
}


void CPPage::AddR(Rectangle R)//����һ������
{
	Reclist* pnew= new Reclist(R,NULL,NULL);//ע���ʼ��

	if(countR==0)//��һ���ڵ�
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


void CPPage::AddE(ellipse E)//����һ����Բ 
{
	Ellist* pnew= new Ellist(E,NULL,NULL);

	if(countE==0)//��һ���ڵ�
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

void CPPage::DelR()//ɾ����һ������
{
	if(countR==0)
	{
		cout<<"ҳ�����޾��Σ�����ɾ��\n";
		return;
	}

	Reclist* temp= this->RH->prior;
	temp->prior->next=this->RH;
	this->RH->prior=temp->prior;
	delete temp;
	countR--;
}

void CPPage::DelE()//ɾ����һ����Բ
{
	if(EH==NULL)
	{
		cout<<"ҳ��������Բ������ɾ��\n";
		return;
	}

	Ellist* temp= this->EH->prior;
	temp->prior->next=this->EH;
	this->EH->prior=temp->prior;
	delete temp;
	countE--;
}

void CPPage::show()
//��Ϊ��Ԫ�࣬չʾ���о��κ���Բ�����Լ��ı���Ϣ��˽�У���show����������ֱ�ӷ��ʾ��κ���Բ���κγ�Ա
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