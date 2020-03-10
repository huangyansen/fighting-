#include"exptree.h"
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
        build(root->left);
        build(root->right);
    }
}

void expression( ExprTreeNode *root )//以带完全括弧的中缀输出算术表达式,先序入，中序出
{
    //从左边下来，下一层一个 ( ; 从右边回去，上一层一个 ) ;
    if(root)
    {
        cout<<"(";
        expression( root->left );

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

int evaluate( ExprTreeNode *root )//返回表达式的值，用后序遍历计算
{
    if(root&&(root->data<'0'||root->data>'9'))//如果不空且为运算符
    {
        int ansl = evaluate( root ->left );
        int ansr = evaluate( root ->right );
        return ans(root->data,ansl,ansr);//处理是左右一定是数字
    }
    else if(root&&(root->data>='0'&&root->data<='9'))//如果不空且为数字就返回数字
        return (root->data-'0');
}


ExprTreeNode* ExprTreeCopy( ExprTreeNode* root,ExprTreeNode* &c_root)  // 实验中练习2新增,复制一棵树(返回一棵树的指针), 用先序遍历
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

void commute( ExprTreeNode *root )//实验中练习3新增  交换表达树中的每个运算符的两个操作数 ,后序交换
{
    if(root&&root->data!='-'&&root->data!='/')//如果是"-"或者"/"不能交换
    {
        commute( root->left );
        commute( root->right );
        ExprTreeNode* temp;
        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
} //疑问？？ 为什么在文档中'-'可以交换，怎么解释数据先后？？








