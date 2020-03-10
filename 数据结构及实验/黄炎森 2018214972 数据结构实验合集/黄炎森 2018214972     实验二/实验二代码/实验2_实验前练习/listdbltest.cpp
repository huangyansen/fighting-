#include "listdbl.h"

void Test_program(List* &L)
{
    int len=0;
    int pos=0;//ͷ(��)���Ϊ0��
    List *head=L;//�ʼ����ͷ���
	char key;
	while(1){
		cout <<  "input command: ";
		cin >> key;
		switch( key ) {
			case '+' :
				ElemType newData;
				cin >> newData;
				insertList(L,newData);//��ָ��L�����һ���ڵ�
				pos++;
				len++;
				break;
			case '-' :
				removeList(L,head);//ɾ���б���ָ������ǵ�������
				pos--;
				break;
			case '=' :
			    ElemType newData2;
			    cin>>newData2;
			    replaceList(L,newData2);//ʹ��newData�滻ָ���ǵ�������
			    break;
			case '@' :
				getCursor(L,head);//��ʾָ��������������ֵ
				break;
			case 'N' :
			    if(gotoNext(L,head)){
                    printf("���Ƴɹ���\n");
                    if(pos==len) pos=0;//�ƶ���ͷ���
                    else pos++;
			    }
                else printf("����ʧ�ܣ�\n");
			    break;
			case 'P' :
				if(gotoPrior(L,head)){
                    printf("ǰ�Ƴɹ���\n");
                    if(pos==0) pos=len;
                    else pos--;
				}
                else printf("ǰ��ʧ�ܣ�\n");
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
                    printf("����Ϊ�գ�\n");
				else printf("����Ϊ�գ�\n");
				break;
			case 'F' :
                if(isFull(head))
                    printf("����Ϊ����\n");
				else printf("����Ϊ����\n");
				break;
			case 'C' :
                clearList(head);
                pos=0;
                len=0;
				break;
			case 'Q' :
				printf("���Գ��������\n");
				return;
            case 'R' :
                reverseList(head);
                printf("��ת����Ϊ:\n");
                showStructure(head);
                break;
            case 'L'://�õ�������
                printf("������Ϊ:%d\n",len);
                break;
            case 'G'://�õ���ǰָ���λ��
                printf("��ǰָ��ָ���%d��Ԫ��\n",pos);
                break;
			default:
				printf("�����������������룡\n");
				break;
		}
		cout << endl;
	}
}


int main(){
    List *head=new List;
    InitList(head);//��һ��������
    cout << "Program test!" <<endl;
    Test_program(head);

    return 0;
}
