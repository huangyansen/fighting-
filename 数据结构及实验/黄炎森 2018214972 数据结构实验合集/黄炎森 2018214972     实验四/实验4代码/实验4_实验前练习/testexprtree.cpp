#include "exptree.h"

extern char s[105];

int main()
{
    cout<<"请输入前缀式:\n";
    cin>>s;

    ExprTreeNode *root;
    InitExprTree(root);
    build(root);
    expression(root);
    cout<<"\nanswer is:"<<evaluate(root)<<"\n\n";


    ExprTreeNode *copyroot;//执行copy操作
    copyroot = ExprTreeCopy(root,copyroot);
    cout<<"after copy:\n";
    expression(copyroot);
    cout<<"\nthe copy answer is:"<<evaluate(copyroot)<<"\n\n";
    DeExprTree(copyroot);


    commute( root );
    cout<<"after exchange:\n";
    expression(root);
    cout<<"\nthe exchange answer is:"<<evaluate(root)<<endl;

    DeExprTree(root);
    return 0;
}
