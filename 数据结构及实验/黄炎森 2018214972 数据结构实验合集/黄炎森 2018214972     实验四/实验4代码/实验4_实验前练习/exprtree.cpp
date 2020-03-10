#include"exptree.h"
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
        build(root->left);
        build(root->right);
    }
}

void expression( ExprTreeNode *root )//�Դ���ȫ��������׺����������ʽ,�����룬�����
{
    //�������������һ��һ�� ( ; ���ұ߻�ȥ����һ��һ�� ) ;
    if(root)
    {
        cout<<"(";
        expression( root->left );

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
    else if(str=='-')
    {
        return l-r;
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
        int ansl = evaluate( root ->left );
        int ansr = evaluate( root ->right );
        return ans(root->data,ansl,ansr);//����������һ��������
    }
    else if(root&&(root->data>='0'&&root->data<='9'))//���������Ϊ���־ͷ�������
        return (root->data-'0');
}


ExprTreeNode* ExprTreeCopy( ExprTreeNode* root,ExprTreeNode* &c_root)  // ʵ������ϰ2����,����һ����(����һ������ָ��), ���������
{
    if(root)
    {
        c_root = new ExprTreeNode;
        c_root->data=root->data;
        c_root->left=NULL, c_root->right=NULL;
        ExprTreeCopy( root->left, c_root->left);
        ExprTreeCopy( root->right, c_root->right);
        return c_root;
    }
}

void commute( ExprTreeNode *root )//ʵ������ϰ3����  ����������е�ÿ������������������� ,���򽻻�
{
    if(root&&root->data!='-'&&root->data!='/')//�����"-"����"/"���ܽ���
    {
        commute( root->left );
        commute( root->right );
        ExprTreeNode* temp;
        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
} //���ʣ��� Ϊʲô���ĵ���'-'���Խ�������ô���������Ⱥ󣿣�








