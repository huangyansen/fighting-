#include "listdbl.h"

void Test_program(List* &L)
{
    int len=0;
    int pos=0;//头(空)结点为0号
    List *head=L;//最开始纪律头结点
	char key;
	while(1){
		cout <<  "input command: ";
		cin >> key;
		switch( key ) {
			case '+' :
				ElemType newData;
				cin >> newData;
				insertList(L,newData);//在指针L后面加一个节点
				pos++;
				len++;
				break;
			case '-' :
				removeList(L,head);//删除列表中指针所标记的数据项
				pos--;
				break;
			case '=' :
			    ElemType newData2;
			    cin>>newData2;
			    replaceList(L,newData2);//使用newData替换指针标记的数据项
			    break;
			case '@' :
				getCursor(L,head);//显示指针所标记数据项的值
				break;
			case 'N' :
			    if(gotoNext(L,head)){
                    printf("后移成功！\n");
                    if(pos==len) pos=0;//移动到头结点
                    else pos++;
			    }
                else printf("后移失败！\n");
			    break;
			case 'P' :
				if(gotoPrior(L,head)){
                    printf("前移成功！\n");
                    if(pos==0) pos=len;
                    else pos--;
				}
                else printf("前移失败！\n");
			    break;
			case '<' :
				gotoBegining(L,head);
				pos=1;
				break;
			case '>' :
				gotoEnd(L,head);
				pos=len;
				break;
			case 'E' :
			    if(isEmpty(head))
                    printf("链表为空！\n");
				else printf("链表不为空！\n");
				break;
			case 'F' :
                if(isFull(head))
                    printf("链表为满！\n");
				else printf("链表不为满！\n");
				break;
			case 'C' :
                clearList(head);
                pos=0;
                len=0;
				break;
			case 'Q' :
				printf("测试程序结束！\n");
				return;
            case 'R' :
                reverseList(head);
                printf("翻转后结果为:\n");
                showStructure(head);
                break;
            case 'L'://得到链表长度
                printf("链表长度为:%d\n",len);
                break;
            case 'G'://得到当前指针的位置
                printf("当前指针指向第%d个元素\n",pos);
                break;
			default:
				printf("输入有误，请重新输入！\n");
				break;
		}
		cout << endl;
	}
}


int main(){
    List *head=new List;
    InitList(head);//建一个空链表
    cout << "Program test!" <<endl;
    Test_program(head);

    return 0;
}
