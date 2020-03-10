#include "exprtree.h"
extern char s[105];

int main()
{
    cout<<"please input:\n";
    cin>>s;

    ExprTreeNode *root;
    InitExprTree(root);
    build(root);
    expression(root);
    int Ans;
    if(evaluate(root)!=0)
        Ans=1;
    else Ans=0;
    cout<<"\nanswer is:"<<Ans<<endl;
    DeExprTree(root);
    return 0;
}
