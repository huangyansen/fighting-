#include "score.h"

void ShowMessage( char *msg, char *str )//显示标题之类  已修改
{
	printf( "\n\n%s%s\n", msg,str );
}

void ShowMenu( char *title, char menuitem[][31], int cc )//把每一级提示输入信息显示出来  已修改
{
	int i;
	printf( "\n\n**%s**\n",title );
	printf( "—————————————\n" );
	for( i=0; i<cc; i++ )
		printf( "      %s \n", menuitem[i] );
	printf( "—————————————\n" );
	printf( "请选择一项（0--%d）： ", cc-1 );
}

void ShowSelectError( int cc )//输入错误，重新选择   已修改
{
	printf( "\n选择错误!!\n" );
	printf( "提示：只能选择0到%d的数, 请重新选择！\n\n", cc );
}

int ShowIsSave(void)//返回是否要保存数据，保存则返回1   已修改
{
	int dd;
	char TitleName[30] = "保存数据吗？";
	char showitem[2][31] = {	"1   保存数据",
								"0   不保存数据" };
	while ( 1 )
	{
		ShowMenu( TitleName, showitem, 2 );
		scanf( "%d", &dd );
		if ( dd==1 )  return TRUE;
		else if ( dd==0 ) return FALSE;
	}
}


void IsSave( student_ *pstu )  //已修改
{
	if ( EditFlag )//如果信息有修改过
	{
		if (ShowIsSave()) DoSave(pstu,DataNum);//执行前面主程序里面的保存数据
	}
}

void ShowQuit( student_ *pstu )  //已修改
{
	IsSave(pstu);
	printf( "\n谢谢使用本软件!\n" );
	printf( "欢迎下次再使用！\n" );
	printf( "再见！！\n" );
}


int OpenData( student_ **pstu, int num )//打开文件，建立链表，将指定班级下的第一个学生信息的首地址赋给pstu   已修改
{
	int i=0, pos=0, pend, rc;
	FILE *fp;
	fp = fopen( WorkingFileName, "rb+" );//以二进制读的方式打开指定班级文件
	if (!fp)
	{
		ShowMessage(  WorkingFileName,"\n文件打开有错！" );
		return 0;
	}
	rc = sizeof(STUDENT);
	fseek( fp, 0L, SEEK_END );//让fp指向指定班级文件尾
	pend = ftell(fp);//pend记录fp相对于指定班级文件头的位置，即总长
	fseek( fp, 0L, SEEK_SET );//让fp指向指定班级文件头

	student_ *head,*tail,*pnew;
	head=(student_ *)malloc(sizeof(student_));
	if(head==NULL) {printf("no enough memory!\n"); exit(-1);}
	head->next=NULL;
	tail=head;//创建头节点，经过后面处理，可以让头节点的指针指向(pstu),即第一个学生地址

	while( pend && pend-pos>=rc )
	{
		pnew = (student_ *)malloc (sizeof(student_));
		if (!pnew)
		{
			ShowMessage( WorkingFileName,"\n内存分配有错！" );
			return 0;
		}
		fread( pnew, sizeof(STUDENT), 1, fp );//从fp所指向的班级文件中读取1个STUDENT型数据到pnew，即完成对当前pnew的赋值
		//！！这里记得要减去4个字节，因为老师给的文件里面结构体中没有指针(4字节)  //要对哪个送值？？？
		pnew->next=NULL;

		tail->next=pnew;
		tail=pnew;//tail用于记录最后一个学生的信息地址

		pos = ftell(fp); //用pos记录fp当前相对于首地址的位置
		i++;
	}//将指定班级下的第一个Student的信息赋给pstu
    *pstu=head->next;//将head的下一位赋给pstu
	DataNum = i;//指该班级文件下有i个学生
	fclose(fp);


  /* printf ("\n==========================班级数据表===========================\n");   //此时，*pstu(二维指针pstu指向的地方值)的值已被更新为指定班级下第一位学生信息的地址
    	while(*pstu){
			printf( "%10s%12s%4s%3d%6d%6.1f%6.1f%6.1f\n",  //指向结构体的指针访问成员函数一定要加括号
				(*pstu)->stu.no, (*pstu)->stu.name,
				((*pstu)->stu.sex==man)?"男":"女",
				(*pstu)->stu.age,
				(*pstu)->stu.classno,
				(*pstu)->stu.English,
				(*pstu)->stu.Math,
				(*pstu)->stu.C_Language );
            (*pstu)=(*pstu)->next;
            //printf("pstu内储存的信息的地址是：%d\n",*pstu);        //对指针*pstu的进行了移动，会影响后面的输出
        }
	printf ("===============================================================\n"); *///测试数据，在这里要改变指针pstu的值，
                        //pstu 赋值正确                                                            //需要用到二级指针，传地址，来改变pstu的值
    printf("pstu内储存的信息的地址是：%d\n",(*pstu));
	return 1;
}

int SaveData( student_ *pstu, int num )//保存班级文件信息    已更新
{
	int i;
	FILE *fp;
	fp = fopen( WorkingFileName, "wb+" );//fp指向有存储位置的地址
	if (!fp)
	{
		ShowMessage(  WorkingFileName,"\n文件保存有错！" );
		return 0;
	}

	fseek( fp, 0L, SEEK_SET );
	student_ *pnew;
	pnew=pstu;

	for( i=0; i<DataNum; i++)//对该班级下所有的学生信息进行保存
	{
		if ( pnew )
			fwrite( pnew, sizeof(STUDENT), 1, fp );//将pnew(当下pnew所指向的学生的信息)的地址写到fp指向的文件中
        pnew=pnew->next;//更新pnew，使其指向下一个学生地址
	}
	fclose(fp);
	EditFlag = 0;
	return 1;
}

student_ *InputItem(void)//在已有学生后面追加登录信息，返回存有完整信息的地址  已修改
{
    student_ *p;
    char sex;
    p = (student_ *)malloc (sizeof(student_));
    if (p==NULL) return NULL;
    printf("\n==请输入学生信息== \n" );
    printf("学号: ");
    scanf( "%s", p->stu.no);
    fflush(stdin);
	printf("姓名: ");
    scanf( "%s", p->stu.name);
    fflush(stdin);
    while(1)
    {
        printf("性别(M,F): ");
        scanf("%c", &sex);
		fflush(stdin);
        if(sex=='M' || sex=='F') break;
	}
	p->stu.sex = (sex=='M')?man:female;
	printf("年龄: ");
    scanf("%d", &p->stu.age);
    fflush(stdin);
	printf("班级: ");
    scanf("%d", &p->stu.classno);
    fflush(stdin);
	printf("数学: ");
    scanf("%f", &p->stu.Math);
	fflush(stdin);
	printf("英语: ");
    scanf("%f", &p->stu.English);
	fflush(stdin);
    printf("C语言: ");
    scanf("%f", &p->stu.C_Language);
	fflush(stdin);
	return(p);
}

void ShowOneItem( student_ *pstu, int i )//输出当前班级下第i个学生的相关信息  已修改
{
    student_ *p;
    p=pstu;
    for(int j=1;j<i;++j)
        p=p->next;   //将p移至第i个学生信息地址

    printf( "%10s%12s%4s%3d%6d%6.1f%6.1f%6.1f\n",
			p->stu.no, p->stu.name,
			(p->stu.sex==man)?"男":"女",
			p->stu.age,
			p->stu.classno,
			p->stu.English,
			p->stu.Math,
			p->stu.C_Language );
}

int SearchData(student_ *pstu, int num, int item, char *name, float score, int dd )//根据不同的数据找学生信息（一次只能根据一个标准） 已修改
{
	int flag=0, i, ii=-1;//num(该班级下学生总数) item(性别，年龄，班级) name(学号，姓名) score(三科成绩) dd(数据项）
	printf( "\n_____________________查找到的数据如下：____________________________\n" );

	student_ *pnew;
	pnew=pstu;

	for (i=0; i<num; i++ )//对该班级下所有的学生信息(各个项)扫描一遍
	{
		if (!pnew) {pnew=pnew->next;continue;}
		if ( dd==1 && !strcmp(pnew->stu.no,name)	||
			 dd==2 && !strcmp(pnew->stu.name,name) ||
			 dd==3 && pnew->stu.sex==item			||
			 dd==4 && pnew->stu.age==item			||
			 dd==5 && pnew->stu.classno==item		||
			 dd==6 && pnew->stu.English==score		||
			 dd==7 && pnew->stu.Math==score		||
			 dd==8 && pnew->stu.C_Language==score		)//对于第i个学生，在各类判断标准下，找到与输入信息条件相等的
		{
			ii = i;//第i个学生符合
			ShowOneItem(pstu,ii);//展示出它的相关数据
			flag = 1;
			pnew=pnew->next;
		}

	}
	printf( "___________________________________________________________________\n" );
	if ( flag ) return TRUE;//flag=1表示在当下班级里面找到了符合条件的学生
	else return FALSE;
}

int SearchNo(student_ *pstu, int num, char *name )//num是总人数，根据学号name来找学生  已修改
{
	int i;
	student_ *pnew;
	pnew=pstu;

	for (i=0; i<num; i++ )
	{
		if (!pnew) { pnew=pnew->next;continue;}
		if (!strcmp(pnew->stu.no,name) ) return i;//找到则返回是第i个人
		pnew=pnew->next;//既非空，又匹配不上学号，就往下找一个
	}
	return -1;//没找到返回-1
}

void InputOneData( student_ *pstu, int i )//为修改第i个学生的信息而重新输入一组数据 【可以优化，想修改什么。。数据】  已修改
{
    student_ *p, *pnew=pstu;
    char sex;

    for(int j=1;j<i;++j)
        pnew=pnew->next; //pnew为第i个学生信息的地址

    p = (student_ *)malloc (sizeof(student_));
    if (p==NULL) return;

    printf("\n==请输入学号为%s的学生信息== \n", pnew->stu.no );
    printf("姓名: ");
    scanf( "%s", p->stu.name);
    fflush(stdin);
    while(1)
    {
        printf("性别(M,F): ");
        scanf("%c", &sex);
	fflush(stdin);
        if(sex=='M' || sex=='F') break;
    }
    p->stu.sex = (sex=='M') ? man : female;
    printf("年龄: ");
    scanf("%d", &p->stu.age);
    fflush(stdin);
    printf("班级: ");
    scanf("%d", &p->stu.classno);
    fflush(stdin);
    printf("数学: ");
    scanf("%f", &p->stu.Math);
    fflush(stdin);
    printf("英语: ");
    scanf("%f", &p->stu.English);
    fflush(stdin);
    printf("C语言: ");
    scanf("%f", &p->stu.C_Language);
    fflush(stdin);//将新数据全部输入到student型的p指针地址处
    strcpy(p->stu.no, pnew->stu.no);//再将原学生的学号赋给p
    pnew = p;//将新的完整的学生信息重新赋给pnew, 就相当于将新的信息地址写入第i个学生的地址
    free(p);//释放申请的空间
}


void Swap(student_ *p, student_ *q)  //已修改
{
     student_ temp = *p;
     temp.next = q->next;
     q->next = p->next;
     *p = *q;
     *q = temp;
}

void SortStuInfo( student_ *pstu, int num, int dd )//根据不同标准对学生信息进行排序，num表示该标班级的总人数  ,由大到小排序  已修改
{
    student_ *p,*pnew=pstu->next;
    student_ *max_=pnew;
    int i, j, k;

	while(pnew)//选择排序
	{
		max_=pnew;
		student_ *q=pstu->next;
		while(q){//在排序时根据不同标准来排序
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

void tongjiall( student_ *pstu, int num )//做统计[可优化？？]  已修改
{
	int i,cc=0;
	student_ *pnew;
	pnew=pstu;
	float max_=0, min_=0, avr=0;
	float maxalle=0, minalle=100, avralle=0;
	float maxallm=0, minallm=100, avrallm=0;
	float maxallc=0, minallc=100, avrallc=0;//英语，数学，C语言成绩的最高，最低，平均分

	printf( "\n---------------------学生成绩统计结果--------------------\n" );
	printf( "%10s%12s%8s%8s%8s\n", "学号", "姓名", "最高分", "最低分", "平均分" );

	for ( i=0; i<num; i++ )
	{
		if ( pnew )
		{
			avr = (pnew->stu.English+pnew->stu.Math+pnew->stu.C_Language)/(float)3.0;//第i个学生三门课的平均分
			max_ = pnew->stu.English>pnew->stu.Math ? pnew->stu.English : pnew->stu.Math;
			max_ = max_>pnew->stu.C_Language ? max_ : pnew->stu.C_Language;
			min_ = pnew->stu.English<pnew->stu.Math ? pnew->stu.English : pnew->stu.Math;
			min_ = min_<pnew->stu.C_Language ? min_ : pnew->stu.C_Language;//第i个学生三门课的最高和最低分
			if ( maxalle<pnew->stu.English) maxalle = pnew->stu.English;
			if ( minalle>pnew->stu.English) minalle = pnew->stu.English;
			avralle += pnew->stu.English;
			if ( maxallm<pnew->stu.Math) maxallm = pnew->stu.Math;
			if ( minallm>pnew->stu.Math) minallm = pnew->stu.Math;
			avrallm += pnew->stu.Math;
			if ( maxallc<pnew->stu.C_Language) maxallc = pnew->stu.C_Language;
			if ( minallc>pnew->stu.C_Language) minallc = pnew->stu.C_Language;
			avrallc += pnew->stu.C_Language;//分别找三门课中的最高，最低分，以及计算所以学生各门课的成绩和
			printf( "%10s%12s%8.1f%8.1f%8.1f\n", pnew->stu.no, pnew->stu.name, max_, min_, avr );//第i个学生的统计信息
			cc++;//统计总人数
		}
    pnew=pnew->next;
	}
	avralle = avralle/cc;
	avrallm = avrallm/cc;
	avrallc = avrallc/cc;
	printf( "---------------------------------------------------------\n\n" );

	printf( "%10s%10s%10s%10s%\n", "全班", "英语", "数学", "C语言" );
	printf( "---------------------------------------------------------\n" );
	printf( "%10s%10.1f%10.1f%10.1f\n", "最高分", maxalle, maxallm, maxallc );
	printf( "%10s%10.1f%10.1f%10.1f\n", "最低分", minalle, minallm, minallc );
	printf( "%10s%10.1f%10.1f%10.1f\n", "平均分", avralle, avrallm, avrallc );
	printf( "---------------------------------------------------------\n\n" );
}


void FreeMemory(student_ *pstu)//销毁链表
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
