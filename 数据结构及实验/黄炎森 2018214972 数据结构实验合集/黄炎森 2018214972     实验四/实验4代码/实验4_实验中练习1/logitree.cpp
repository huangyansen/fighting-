#include"exprtree.h"
int current=0;
char s[105];

void InitExprTree( ExprTreeNode* &root )//建空树
{
    root = NULL;
}

void DeExprTree( ExprTreeNode *root )//释放树的空间
{
    if(root)//后序遍历释放
    {
        DeExprTree( root->left );
        DeExprTree( root->right );
        delete root;
    }
}

void build( ExprTreeNode* &root)//以先序建树,用current对字符数组遍历,current初始化为0
{
    root = new ExprTreeNode;
    if(s[current]>='0'&&s[current]<='9')//叶子节点
    {
        root->data=s[current];
        root->left=NULL,root->right=NULL;
        current++;
        return;
    }
    else//运算符
    {
        root->data=s[current];
        current++;
        if(root->data=='-')//为"-",只用建右子树
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

void expression( ExprTreeNode *root )//以带完全括弧的中缀输出算术表达式,先序入，中序出
{
    //从左边下来，下一层一个 ( ; 从右边回去，上一层一个 ) ;
    if(root)
    {
        cout<<"(";
        if(root->data!='-')  expression( root->left );//为"-"不用遍历左子树

        cout<<root->data;

        expression( root->right );
        cout<<")";
    }
}

int ans(char str,int l,int r)//根据运算符和数字返回结果
{
    if(str=='+')
    {
        return l+r;
    }
    else if(str=='-')//取反
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

int evaluate( ExprTreeNode *root )//返回表达式的值，用后序遍历计算
{
    if(root&&(root->data<'0'||root->data>'9'))//如果不空且为运算符
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
            return ans(root->data,ansl,ansr);//处理是左右一定是数字
        }
    }
    else if(root&&(root->data>='0'&&root->data<='9'))//如果不空且为数字就返回数字
        return (root->data-'0');
}
