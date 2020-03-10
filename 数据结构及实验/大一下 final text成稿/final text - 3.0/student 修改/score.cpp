#include "score.h"

void ShowMessage( char *msg, char *str )//��ʾ����֮��  ���޸�
{
	printf( "\n\n%s%s\n", msg,str );
}

void ShowMenu( char *title, char menuitem[][31], int cc )//��ÿһ����ʾ������Ϣ��ʾ����  ���޸�
{
	int i;
	printf( "\n\n**%s**\n",title );
	printf( "��������������������������\n" );
	for( i=0; i<cc; i++ )
		printf( "      %s \n", menuitem[i] );
	printf( "��������������������������\n" );
	printf( "��ѡ��һ�0--%d���� ", cc-1 );
}

void ShowSelectError( int cc )//�����������ѡ��   ���޸�
{
	printf( "\nѡ�����!!\n" );
	printf( "��ʾ��ֻ��ѡ��0��%d����, ������ѡ��\n\n", cc );
}

int ShowIsSave(void)//�����Ƿ�Ҫ�������ݣ������򷵻�1   ���޸�
{
	int dd;
	char TitleName[30] = "����������";
	char showitem[2][31] = {	"1   ��������",
								"0   ����������" };
	while ( 1 )
	{
		ShowMenu( TitleName, showitem, 2 );
		scanf( "%d", &dd );
		if ( dd==1 )  return TRUE;
		else if ( dd==0 ) return FALSE;
	}
}


void IsSave( student_ *pstu )  //���޸�
{
	if ( EditFlag )//�����Ϣ���޸Ĺ�
	{
		if (ShowIsSave()) DoSave(pstu,DataNum);//ִ��ǰ������������ı�������
	}
}

void ShowQuit( student_ *pstu )  //���޸�
{
	IsSave(pstu);
	printf( "\nллʹ�ñ����!\n" );
	printf( "��ӭ�´���ʹ�ã�\n" );
	printf( "�ټ�����\n" );
}


int OpenData( student_ **pstu, int num )//���ļ�������������ָ���༶�µĵ�һ��ѧ����Ϣ���׵�ַ����pstu   ���޸�
{
	int i=0, pos=0, pend, rc;
	FILE *fp;
	fp = fopen( WorkingFileName, "rb+" );//�Զ����ƶ��ķ�ʽ��ָ���༶�ļ�
	if (!fp)
	{
		ShowMessage(  WorkingFileName,"\n�ļ����д�" );
		return 0;
	}
	rc = sizeof(STUDENT);
	fseek( fp, 0L, SEEK_END );//��fpָ��ָ���༶�ļ�β
	pend = ftell(fp);//pend��¼fp�����ָ���༶�ļ�ͷ��λ�ã����ܳ�
	fseek( fp, 0L, SEEK_SET );//��fpָ��ָ���༶�ļ�ͷ

	student_ *head,*tail,*pnew;
	head=(student_ *)malloc(sizeof(student_));
	if(head==NULL) {printf("no enough memory!\n"); exit(-1);}
	head->next=NULL;
	tail=head;//����ͷ�ڵ㣬�������洦��������ͷ�ڵ��ָ��ָ��(pstu),����һ��ѧ����ַ

	while( pend && pend-pos>=rc )
	{
		pnew = (student_ *)malloc (sizeof(student_));
		if (!pnew)
		{
			ShowMessage( WorkingFileName,"\n�ڴ�����д�" );
			return 0;
		}
		fread( pnew, sizeof(STUDENT), 1, fp );//��fp��ָ��İ༶�ļ��ж�ȡ1��STUDENT�����ݵ�pnew������ɶԵ�ǰpnew�ĸ�ֵ
		//��������ǵ�Ҫ��ȥ4���ֽڣ���Ϊ��ʦ�����ļ�����ṹ����û��ָ��(4�ֽ�)  //Ҫ���ĸ���ֵ������
		pnew->next=NULL;

		tail->next=pnew;
		tail=pnew;//tail���ڼ�¼���һ��ѧ������Ϣ��ַ

		pos = ftell(fp); //��pos��¼fp��ǰ������׵�ַ��λ��
		i++;
	}//��ָ���༶�µĵ�һ��Student����Ϣ����pstu
    *pstu=head->next;//��head����һλ����pstu
	DataNum = i;//ָ�ð༶�ļ�����i��ѧ��
	fclose(fp);


  /* printf ("\n==========================�༶���ݱ�===========================\n");   //��ʱ��*pstu(��άָ��pstuָ��ĵط�ֵ)��ֵ�ѱ�����Ϊָ���༶�µ�һλѧ����Ϣ�ĵ�ַ
    	while(*pstu){
			printf( "%10s%12s%4s%3d%6d%6.1f%6.1f%6.1f\n",  //ָ��ṹ���ָ����ʳ�Ա����һ��Ҫ������
				(*pstu)->stu.no, (*pstu)->stu.name,
				((*pstu)->stu.sex==man)?"��":"Ů",
				(*pstu)->stu.age,
				(*pstu)->stu.classno,
				(*pstu)->stu.English,
				(*pstu)->stu.Math,
				(*pstu)->stu.C_Language );
            (*pstu)=(*pstu)->next;
            //printf("pstu�ڴ������Ϣ�ĵ�ַ�ǣ�%d\n",*pstu);        //��ָ��*pstu�Ľ������ƶ�����Ӱ���������
        }
	printf ("===============================================================\n"); *///�������ݣ�������Ҫ�ı�ָ��pstu��ֵ��
                        //pstu ��ֵ��ȷ                                                            //��Ҫ�õ�����ָ�룬����ַ�����ı�pstu��ֵ
    printf("pstu�ڴ������Ϣ�ĵ�ַ�ǣ�%d\n",(*pstu));
	return 1;
}

int SaveData( student_ *pstu, int num )//����༶�ļ���Ϣ    �Ѹ���
{
	int i;
	FILE *fp;
	fp = fopen( WorkingFileName, "wb+" );//fpָ���д洢λ�õĵ�ַ
	if (!fp)
	{
		ShowMessage(  WorkingFileName,"\n�ļ������д�" );
		return 0;
	}

	fseek( fp, 0L, SEEK_SET );
	student_ *pnew;
	pnew=pstu;

	for( i=0; i<DataNum; i++)//�Ըð༶�����е�ѧ����Ϣ���б���
	{
		if ( pnew )
			fwrite( pnew, sizeof(STUDENT), 1, fp );//��pnew(����pnew��ָ���ѧ������Ϣ)�ĵ�ַд��fpָ����ļ���
        pnew=pnew->next;//����pnew��ʹ��ָ����һ��ѧ����ַ
	}
	fclose(fp);
	EditFlag = 0;
	return 1;
}

student_ *InputItem(void)//������ѧ������׷�ӵ�¼��Ϣ�����ش���������Ϣ�ĵ�ַ  ���޸�
{
    student_ *p;
    char sex;
    p = (student_ *)malloc (sizeof(student_));
    if (p==NULL) return NULL;
    printf("\n==������ѧ����Ϣ== \n" );
    printf("ѧ��: ");
    scanf( "%s", p->stu.no);
    fflush(stdin);
	printf("����: ");
    scanf( "%s", p->stu.name);
    fflush(stdin);
    while(1)
    {
        printf("�Ա�(M,F): ");
        scanf("%c", &sex);
		fflush(stdin);
        if(sex=='M' || sex=='F') break;
	}
	p->stu.sex = (sex=='M')?man:female;
	printf("����: ");
    scanf("%d", &p->stu.age);
    fflush(stdin);
	printf("�༶: ");
    scanf("%d", &p->stu.classno);
    fflush(stdin);
	printf("��ѧ: ");
    scanf("%f", &p->stu.Math);
	fflush(stdin);
	printf("Ӣ��: ");
    scanf("%f", &p->stu.English);
	fflush(stdin);
    printf("C����: ");
    scanf("%f", &p->stu.C_Language);
	fflush(stdin);
	return(p);
}

void ShowOneItem( student_ *pstu, int i )//�����ǰ�༶�µ�i��ѧ���������Ϣ  ���޸�
{
    student_ *p;
    p=pstu;
    for(int j=1;j<i;++j)
        p=p->next;   //��p������i��ѧ����Ϣ��ַ

    printf( "%10s%12s%4s%3d%6d%6.1f%6.1f%6.1f\n",
			p->stu.no, p->stu.name,
			(p->stu.sex==man)?"��":"Ů",
			p->stu.age,
			p->stu.classno,
			p->stu.English,
			p->stu.Math,
			p->stu.C_Language );
}

int SearchData(student_ *pstu, int num, int item, char *name, float score, int dd )//���ݲ�ͬ��������ѧ����Ϣ��һ��ֻ�ܸ���һ����׼�� ���޸�
{
	int flag=0, i, ii=-1;//num(�ð༶��ѧ������) item(�Ա����䣬�༶) name(ѧ�ţ�����) score(���Ƴɼ�) dd(�����
	printf( "\n_____________________���ҵ����������£�____________________________\n" );

	student_ *pnew;
	pnew=pstu;

	for (i=0; i<num; i++ )//�Ըð༶�����е�ѧ����Ϣ(������)ɨ��һ��
	{
		if (!pnew) {pnew=pnew->next;continue;}
		if ( dd==1 && !strcmp(pnew->stu.no,name)	||
			 dd==2 && !strcmp(pnew->stu.name,name) ||
			 dd==3 && pnew->stu.sex==item			||
			 dd==4 && pnew->stu.age==item			||
			 dd==5 && pnew->stu.classno==item		||
			 dd==6 && pnew->stu.English==score		||
			 dd==7 && pnew->stu.Math==score		||
			 dd==8 && pnew->stu.C_Language==score		)//���ڵ�i��ѧ�����ڸ����жϱ�׼�£��ҵ���������Ϣ������ȵ�
		{
			ii = i;//��i��ѧ������
			ShowOneItem(pstu,ii);//չʾ�������������
			flag = 1;
			pnew=pnew->next;
		}

	}
	printf( "___________________________________________________________________\n" );
	if ( flag ) return TRUE;//flag=1��ʾ�ڵ��°༶�����ҵ��˷���������ѧ��
	else return FALSE;
}

int SearchNo(student_ *pstu, int num, char *name )//num��������������ѧ��name����ѧ��  ���޸�
{
	int i;
	student_ *pnew;
	pnew=pstu;

	for (i=0; i<num; i++ )
	{
		if (!pnew) { pnew=pnew->next;continue;}
		if (!strcmp(pnew->stu.no,name) ) return i;//�ҵ��򷵻��ǵ�i����
		pnew=pnew->next;//�ȷǿգ���ƥ�䲻��ѧ�ţ���������һ��
	}
	return -1;//û�ҵ�����-1
}

void InputOneData( student_ *pstu, int i )//Ϊ�޸ĵ�i��ѧ������Ϣ����������һ������ �������Ż������޸�ʲô�������ݡ�  ���޸�
{
    student_ *p, *pnew=pstu;
    char sex;

    for(int j=1;j<i;++j)
        pnew=pnew->next; //pnewΪ��i��ѧ����Ϣ�ĵ�ַ

    p = (student_ *)malloc (sizeof(student_));
    if (p==NULL) return;

    printf("\n==������ѧ��Ϊ%s��ѧ����Ϣ== \n", pnew->stu.no );
    printf("����: ");
    scanf( "%s", p->stu.name);
    fflush(stdin);
    while(1)
    {
        printf("�Ա�(M,F): ");
        scanf("%c", &sex);
	fflush(stdin);
        if(sex=='M' || sex=='F') break;
    }
    p->stu.sex = (sex=='M') ? man : female;
    printf("����: ");
    scanf("%d", &p->stu.age);
    fflush(stdin);
    printf("�༶: ");
    scanf("%d", &p->stu.classno);
    fflush(stdin);
    printf("��ѧ: ");
    scanf("%f", &p->stu.Math);
    fflush(stdin);
    printf("Ӣ��: ");
    scanf("%f", &p->stu.English);
    fflush(stdin);
    printf("C����: ");
    scanf("%f", &p->stu.C_Language);
    fflush(stdin);//��������ȫ�����뵽student�͵�pָ���ַ��
    strcpy(p->stu.no, pnew->stu.no);//�ٽ�ԭѧ����ѧ�Ÿ���p
    pnew = p;//���µ�������ѧ����Ϣ���¸���pnew, ���൱�ڽ��µ���Ϣ��ַд���i��ѧ���ĵ�ַ
    free(p);//�ͷ�����Ŀռ�
}


void Swap(student_ *p, student_ *q)  //���޸�
{
     student_ temp = *p;
     temp.next = q->next;
     q->next = p->next;
     *p = *q;
     *q = temp;
}

void SortStuInfo( student_ *pstu, int num, int dd )//���ݲ�ͬ��׼��ѧ����Ϣ��������num��ʾ�ñ�༶��������  ,�ɴ�С����  ���޸�
{
    student_ *p,*pnew=pstu->next;
    student_ *max_=pnew;
    int i, j, k;

	while(pnew)//ѡ������
	{
		max_=pnew;
		student_ *q=pstu->next;
		while(q){//������ʱ���ݲ�ͬ��׼������
			switch( dd )
			{
				case 1: if ( strcmp(q->stu.no, max_->stu.no)>0 )	max_=q;	break;
				case 2: if ( strcmp(q->stu.name, max_->stu.name)>0 )	max_=q;	break;
				case 3: if ( q->stu.English > max_->stu.English )	max_=q;	break;
				case 4: if ( q->stu.Math > max_->stu.Math )		max_=q;	break;
				case 5: if ( q->stu.C_Language > max_->stu.C_Language )	max_=q;	break;
			}

        }
    Swap(pnew,max_);
    pnew=pnew->next;
    }
}

void tongjiall( student_ *pstu, int num )//��ͳ��[���Ż�����]  ���޸�
{
	int i,cc=0;
	student_ *pnew;
	pnew=pstu;
	float max_=0, min_=0, avr=0;
	float maxalle=0, minalle=100, avralle=0;
	float maxallm=0, minallm=100, avrallm=0;
	float maxallc=0, minallc=100, avrallc=0;//Ӣ���ѧ��C���Գɼ�����ߣ���ͣ�ƽ����

	printf( "\n---------------------ѧ���ɼ�ͳ�ƽ��--------------------\n" );
	printf( "%10s%12s%8s%8s%8s\n", "ѧ��", "����", "��߷�", "��ͷ�", "ƽ����" );

	for ( i=0; i<num; i++ )
	{
		if ( pnew )
		{
			avr = (pnew->stu.English+pnew->stu.Math+pnew->stu.C_Language)/(float)3.0;//��i��ѧ�����ſε�ƽ����
			max_ = pnew->stu.English>pnew->stu.Math ? pnew->stu.English : pnew->stu.Math;
			max_ = max_>pnew->stu.C_Language ? max_ : pnew->stu.C_Language;
			min_ = pnew->stu.English<pnew->stu.Math ? pnew->stu.English : pnew->stu.Math;
			min_ = min_<pnew->stu.C_Language ? min_ : pnew->stu.C_Language;//��i��ѧ�����ſε���ߺ���ͷ�
			if ( maxalle<pnew->stu.English) maxalle = pnew->stu.English;
			if ( minalle>pnew->stu.English) minalle = pnew->stu.English;
			avralle += pnew->stu.English;
			if ( maxallm<pnew->stu.Math) maxallm = pnew->stu.Math;
			if ( minallm>pnew->stu.Math) minallm = pnew->stu.Math;
			avrallm += pnew->stu.Math;
			if ( maxallc<pnew->stu.C_Language) maxallc = pnew->stu.C_Language;
			if ( minallc>pnew->stu.C_Language) minallc = pnew->stu.C_Language;
			avrallc += pnew->stu.C_Language;//�ֱ������ſ��е���ߣ���ͷ֣��Լ���������ѧ�����ſεĳɼ���
			printf( "%10s%12s%8.1f%8.1f%8.1f\n", pnew->stu.no, pnew->stu.name, max_, min_, avr );//��i��ѧ����ͳ����Ϣ
			cc++;//ͳ��������
		}
    pnew=pnew->next;
	}
	avralle = avralle/cc;
	avrallm = avrallm/cc;
	avrallc = avrallc/cc;
	printf( "---------------------------------------------------------\n\n" );

	printf( "%10s%10s%10s%10s%\n", "ȫ��", "Ӣ��", "��ѧ", "C����" );
	printf( "---------------------------------------------------------\n" );
	printf( "%10s%10.1f%10.1f%10.1f\n", "��߷�", maxalle, maxallm, maxallc );
	printf( "%10s%10.1f%10.1f%10.1f\n", "��ͷ�", minalle, minallm, minallc );
	printf( "%10s%10.1f%10.1f%10.1f\n", "ƽ����", avralle, avrallm, avrallc );
	printf( "---------------------------------------------------------\n\n" );
}


void FreeMemory(student_ *pstu)//��������
{
   student_ *p,*q;

   p=pstu;
   while(p->next!=NULL){
    q=p->next;
    p->next=q->next;
    free(q);
   }
    free(pstu);
}
