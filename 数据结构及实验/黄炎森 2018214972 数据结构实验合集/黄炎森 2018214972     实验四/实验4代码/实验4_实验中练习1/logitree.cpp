#include"exprtree.h"
int current=0;
char s[105];

void InitExprTree( ExprTreeNode* &root )//������
{
    root = NULL;
}

void DeExprTree( ExprTreeNode *root )//�ͷ����Ŀռ�
{
    if(root)//��������ͷ�
    {
        DeExprTree( root->left );
        DeExprTree( root->right );
        delete root;
    }
}

void build( ExprTreeNode* &root)//��������,��current���ַ��������,current��ʼ��Ϊ0
{
    root = new ExprTreeNode;
    if(s[current]>='0'&&s[current]<='9')//Ҷ�ӽڵ�
    {
        root->data=s[current];
        root->left=NULL,root->right=NULL;
        current++;
        return;
    }
    else//�����
    {
        root->data=s[current];
        current++;
        if(root->data=='-')//Ϊ"-",ֻ�ý�������
        {
            build(root->right);
        }
        else
        {
            build(root->left);
            build(root->right);
        }
    }
}

void expression( ExprTreeNode *root )//�Դ���ȫ��������׺����������ʽ,�����룬�����
{
    //�������������һ��һ�� ( ; ���ұ߻�ȥ����һ��һ�� ) ;
    if(root)
    {
        cout<<"(";
        if(root->data!='-')  expression( root->left );//Ϊ"-"���ñ���������

        cout<<root->data;

        expression( root->right );
        cout<<")";
    }
}

int ans(char str,int l,int r)//��������������ַ��ؽ��
{
    if(str=='+')
    {
        return l+r;
    }
    else if(str=='-')//ȡ��
    {
        if(r==0)
            return 1;
        else return 0;
    }
    else if(str=='*')
    {
        return l*r;
    }
    else if(str=='/')
    {
        return l/r;
    }
}

int evaluate( ExprTreeNode *root )//���ر��ʽ��ֵ���ú����������
{
    if(root&&(root->data<'0'||root->data>'9'))//���������Ϊ�����
    {
        if(root->data=='-')
        {
            int ansr = evaluate( root ->right );
            return ans(root->data,0,ansr);
        }
        else
        {
            int ansl = evaluate( root ->left );
            int ansr = evaluate( root ->right );
            return ans(root->data,ansl,ansr);//����������һ��������
        }
    }
    else if(root&&(root->data>='0'&&root->data<='9'))//���������Ϊ���־ͷ�������
        return (root->data-'0');
}
