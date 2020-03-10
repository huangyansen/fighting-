#include "score.h"

void ShowMessage( char *msg, char *str )//显示标题之类
{
	printf( "\n\n%s%s\n", msg,str );
}

void ShowMenu( char *title, char menuitem[][31], int cc )//把每一级提示输入信息显示出来
{
	int i;
	printf( "\n\n**%s**\n",title );
	printf( "—————————————\n" );
	for( i=0; i<cc; i++ )
		printf( "      %s \n", menuitem[i] );
	printf( "—————————————\n" );
	printf( "请选择一项（0--%d）： ", cc-1 );
}

void ShowSelectError( int cc )//输入错误，重新选择
{
	printf( "\n选择错误!!\n" );
	printf( "提示：只能选择0到%d的数, 请重新选择！\n\n", cc );
}

int ShowIsSave(void)//返回是否要保存数据，保存则返回1
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


void IsSave( STUDENT **pstu )
{
	if ( EditFlag )//如果信息有修改过
	{
		if (ShowIsSave()) DoSave(pstu,DataNum);//执行前面主程序里面的保存数据
	}
}

void ShowQuit( STUDENT **pstu )
{
	IsSave(pstu);
	printf( "\n谢谢使用本软件!\n" );
	printf( "欢迎下次再使用！\n" );
	printf( "再见！！\n" );
}


int OpenData( STUDENT **pstu, int num )//打开文件，即将指定班级下的Student信息全部赋给pstu[i](第i个学生)->student(结构体）
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
	pend = ftell(fp);//pend记录fp相对于指定班级文件头的位置
	fseek( fp, 0L, SEEK_SET );//让fp指向指定班级文件头
	while( pend && pend-pos>=rc )
	{
		pstu[i] = (STUDENT *)malloc (sizeof(STUDENT));
		if (!pstu[i])
		{
			ShowMessage( WorkingFileName,"\n内存分配有错！" );
			return 0;
		}
		fread( pstu[i], sizeof(STUDENT), 1, fp );//从fp所指向的班级文件中读取1个STUDENT型数据到pstu[i]，即完成对pstu的赋值
		pos = ftell(fp); //将pos的位置向右移动一个Student单元
		i++;
	}//将指定班级下的Student信息全部赋给pstu[i](第i个学生)->student(结构体）
	DataNum = i;//指该班级文件下有i个学生
	fclose(fp);
	return 1;
}

int SaveData( STUDENT **pstu, int num )//保存班级文件信息
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
	for( i=0; i<DataNum; i++)//对该班级下所有的学生信息进行保存
	{
		if ( pstu[i] )
			fwrite( pstu[i], sizeof(STUDENT), 1, fp );//将pstu[i](班级i-1)的地址写到fp指向的文件中
	}
	fclose(fp);
	EditFlag = 0;
	return 1;
}

STUDENT *InputItem(void)//在已有学生后面追加登录信息，返回存有完整信息的地址
{
    STUDENT *p;
    char sex;
    p = (STUDENT *)malloc (sizeof(STUDENT));
    if (p==NULL) return NULL;
    printf("\n==请输入学生信息== \n" );
    printf("学号: ");
    scanf( "%s", p->no);
    fflush(stdin);
	printf("姓名: ");
    scanf( "%s", p->name);
    fflush(stdin);
    while(1)
    {
        printf("性别(M,F): ");
        scanf("%c", &sex);
		fflush(stdin);
        if(sex=='M' || sex=='F') break;
	}
	p->sex = (sex=='M')?man:female;
	printf("年龄: ");
    scanf("%d", &p->age);
    fflush(stdin);
	printf("班级: ");
    scanf("%d", &p->classno);
    fflush(stdin);
	printf("数学: ");
    scanf("%f", &p->Math);
	fflush(stdin);
	printf("英语: ");
    scanf("%f", &p->English);
	fflush(stdin);
    printf("C语言: ");
    scanf("%f", &p->C_Language);
	fflush(stdin);
	return(p);
}

void ShowOneItem( STUDENT **pstu, int i )//输出当前班级下第i个学生的相关信息
{
    printf( "%10s%12s%4s%3d%6d%6.1f%6.1f%6.1f\n",
			pstu[i]->no, pstu[i]->name,
			(pstu[i]->sex==man)?"男":"女",
			pstu[i]->age,
			pstu[i]->classno,
			pstu[i]->English,
			pstu[i]->Math,
			pstu[i]->C_Language );
}

int SearchData(STUDENT **pstu, int num, int item, char *name, float score, int dd )//根据不同的数据找学生信息（一次只能根据一个标准）
{
	int flag=0, i, ii=-1;//num(该班级下学生总数) item(性别，年龄，班级) name(学号，姓名) score(三科成绩) dd(数据项）
	printf( "\n_____________________查找到的数据如下：____________________________\n" );
	for (i=0; i<num; i++ )//对该班级下所有的学生信息(各个项)扫描一遍
	{
		if (!pstu[i]) continue;
		if ( dd==1 && !strcmp(pstu[i]->no,name)	||
			 dd==2 && !strcmp(pstu[i]->name,name) ||
			 dd==3 && pstu[i]->sex==item			||
			 dd==4 && pstu[i]->age==item			||
			 dd==5 && pstu[i]->classno==item		||
			 dd==6 && pstu[i]->English==score		||
			 dd==7 && pstu[i]->Math==score		||
			 dd==8 && pstu[i]->C_Language==score		)//对于第i个学生，在各类判断标准下，找到与输入信息条件相等的
		{
			ii = i;//第i个学生符合
			ShowOneItem(pstu,ii);//展示出它的相关数据
			flag = 1;
		}
	}
	printf( "___________________________________________________________________\n" );
	if ( flag ) return TRUE;//flag=1表示在当下班级里面找到了符合条件的学生
	else return FALSE;
}

int SearchNo(STUDENT **pstu, int num, char *name )//num是总人数，根据学号name来找学生
{
	int i;
	for (i=0; i<num; i++ )
	{
		if (!pstu[i]) continue;
		if ( !strcmp(pstu[i]->no,name) ) return i;//找到则返回是第i个人
	}
	return -1;//没找到返回-1
}

void InputOneData( STUDENT **pstu, int i )//为修改第i个学生的信息而重新输入一组数据 【可以优化，想修改什么。。数据】
{
    STUDENT *p, *q;
    char sex;

    q = pstu[i];//q为第i个学生信息的地址，（修改前的信息）
    p = (STUDENT *)malloc (sizeof(STUDENT));
    if (p==NULL) return;
    printf("\n==请输入学号为%s的学生信息== \n", pstu[i]->no );
    printf("姓名: ");
    scanf( "%s", p->name);
    fflush(stdin);
    while(1)
    {
        printf("性别(M,F): ");
        scanf("%c", &sex);
	fflush(stdin);
        if(sex=='M' || sex=='F') break;
    }
    p->sex = (sex=='M') ? man : female;
    printf("年龄: ");
    scanf("%d", &p->age);
    fflush(stdin);
    printf("班级: ");
    scanf("%d", &p->classno);
    fflush(stdin);
    printf("数学: ");
    scanf("%f", &p->Math);
    fflush(stdin);
    printf("英语: ");
    scanf("%f", &p->English);
    fflush(stdin);
    printf("C语言: ");
    scanf("%f", &p->C_Language);
    fflush(stdin);//将新数据全部输入到student型的p指针地址处
    strcpy(p->no, pstu[i]->no);//再将原学生的学号赋给p
    pstu[i] = p;//将新的完整的学生信息重新赋给pstu[i]
    free(p);//释放申请的空间
}

void SortStuInfo( STUDENT **pstu, int max, int dd )//根据不同标准对学生信息进行排序，max表示该标班级的总人数
{
    STUDENT *p;
    int i, j, k;
	int num=0;

	for (i=0; i<max; i++ )
		if (!pstu[i]) break;
	num = i;//num表示什么？？？？？？？？

	for (i=0; i<num-1; i++)//选择排序
	{
		k = i;
		for (j=i+1; j<num; j++)//在排序时根据不同标准来排序
			switch( dd )
			{
				case 1: if ( strcmp(pstu[j]->no, pstu[k]->no)>0 )	k = j;	break;
				case 2: if ( strcmp(pstu[j]->name, pstu[k]->name)>0 )	k = j;	break;
				case 3: if ( pstu[j]->English>pstu[k]->English )	k = j;	break;
				case 4: if ( pstu[j]->Math>pstu[k]->Math )		k = j;	break;
				case 5: if ( pstu[j]->C_Language>pstu[k]->C_Language )	k = j;	break;
			}
		if (k!=i)
		{
			p = pstu[i];
			pstu[i] = pstu[k];
			pstu[k] = p;
		}

	}
}

void tongjiall( STUDENT **pstu, int num )//做统计[可优化？？]
{
	int i,cc=0;
	float max=0, min=0, avr=0;
	float maxalle=0, minalle=100, avralle=0;
	float maxallm=0, minallm=100, avrallm=0;
	float maxallc=0, minallc=100, avrallc=0;//英语，数学，C语言成绩的最高，最低，平均分

	printf( "\n---------------------学生成绩统计结果--------------------\n" );
	printf( "%10s%12s%8s%8s%8s\n", "学号", "姓名", "最高分", "最低分", "平均分" );

	for ( i=0; i<num; i++ )
	{
		if ( pstu[i] )
		{
			avr = (pstu[i]->English+pstu[i]->Math+pstu[i]->C_Language)/(float)3.0;//第i个学生三门课的平均分
			max = pstu[i]->English>pstu[i]->Math ? pstu[i]->English : pstu[i]->Math;
			max = max>pstu[i]->C_Language ? max : pstu[i]->C_Language;
			min = pstu[i]->English<pstu[i]->Math ? pstu[i]->English : pstu[i]->Math;
			min = min<pstu[i]->C_Language ? min : pstu[i]->C_Language;//第i个学生三门课的最高和最低分
			if ( maxalle<pstu[i]->English) maxalle = pstu[i]->English;
			if ( minalle>pstu[i]->English) minalle = pstu[i]->English;
			avralle += pstu[i]->English;
			if ( maxallm<pstu[i]->Math) maxallm = pstu[i]->Math;
			if ( minallm>pstu[i]->Math) minallm = pstu[i]->Math;
			avrallm += pstu[i]->Math;
			if ( maxallc<pstu[i]->C_Language) maxallc = pstu[i]->C_Language;
			if ( minallc>pstu[i]->C_Language) minallc = pstu[i]->C_Language;
			avrallc += pstu[i]->C_Language;//分别找三门课中的最高，最低分，以及计算所以学生各门课的成绩和
			printf( "%10s%12s%8.1f%8.1f%8.1f\n", pstu[i]->no, pstu[i]->name, max, min, avr );//第i个学生的统计信息
			cc++;//统计总人数
		}
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


void FreeMemory(STUDENT **pstu, int num)//释放申请的所有pstu指针
{
    int i;
    for (i=0; i<num; i++)
		if (pstu[i])
			free(pstu[i]);
    free(pstu);
}


void InitList(STUDENT **pstu, int num )//初始化所有pstu的指针
{
	int i;
	for (i=0;i<num;i++)
		pstu[i]=NULL;
}
