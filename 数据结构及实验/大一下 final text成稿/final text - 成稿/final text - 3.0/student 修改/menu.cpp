#include "score.h"

void DoMainMenu( student_ *pstu )//主菜单操作
{
    char TitleName[30] = "学生课程学习主菜单选择";
    char showitem[9][31]= {	"1   打开文件",
                            "2   保存文件",
                            "3   登录数据",
                            "4   查找数据",
                            "5   修改数据",
                            "6   显示数据",
                            "7   结果排序",
                            "8   统计数据",
                            "0   退出系统"
                          };
    void (*func[])(student_ *&, int) = { DoOpen, DoSave, Doinput, DoSearch, DoEdit, DoShow, DoSort, Dotongji };//把函数名赋值给func函数指针
    //表明这些函数都是该数据传入类型
    int dd;

    while ( 1 )
    {
        ShowMenu( TitleName, showitem, 9 );
        scanf( "%d", &dd );
        if ( dd==0 )
        {
            ShowQuit(pstu);//退出该程序，如果有修改过，就提示是否要保存修改数据
            break;
        }
        else if ( dd<0 || dd>=9 )
        {
            ShowSelectError(9);
            continue;
        }
        else
            func[dd-1](pstu,DataNum);//输入正确，执行输入对应的操作，通过函数指针来实现（相当于执行上述的9个不同程序）
    }
}

//分别解释每个操作
void DoOpen( student_ *&pstu, int num )//打开文件(必须要先打开文件）作用：  选择一个班级进行后续操作：从2~8 ，用引用，方便和其它菜单保持一致
{
    char TitleName[30] = "请选择一个文件";
    char showitem[8][31] = {	"1  01班学习成绩文件",
                                "2  02班学习成绩文件",
                                "3  03班学习成绩文件",
                                "4  04班学习成绩文件",
                                "5  05班学习成绩文件",
                                "6  06班学习成绩文件",
                                "7  07班学习成绩文件",
                                "0  返回上一级"
                           };
    char FileName[][21]  = { "class01.dat", "class02.dat", "class03.dat", "class04.dat", "class05.dat", "class06.dat", "class07.dat" };
    int  dd;

    while ( 1 )
    {
        ShowMenu( TitleName, showitem, 8 );
        scanf( "%d", &dd );
        if ( dd==0 )
            break;
        else if ( dd<0 || dd>=8 )
            ShowSelectError(8);
        else
        {
            strcpy( WorkingFileName, FileName[dd-1] );//把文件名（即班级名）赋给 WorkFileName ， 此时已进入到指定班级状态（级别）
            if ( !OpenData( &pstu, num ) )//打开班级文件，执行之后就把 func[dd-1](pstu,DataNum)中的DataNum改为该班级总人数了,传pstu的地址
            {
                ShowMessage( WorkingFileName,"\n文件不存在，请重新选择！");
                strcpy( WorkingFileName, "" ); //如果打不开，就重置WorkingFileName,并重新执行OpenData操作
                continue;
            }

            ShowMessage(  WorkingFileName,"\n文件已经打开！");
            break;
        }
    }
}

void DoSave( student_ *&pstu, int num )//在对班级下面学生的信息进行修改后，要对班级文件信息进行保存
{
    char TitleName[30] = "请选择一个文件";
    char showitem[8][31] = {	"1  01班学习成绩文件",
                                "2  02班学习成绩文件",
                                "3  03班学习成绩文件",
                                "4  04班学习成绩文件",
                                "5  05班学习成绩文件",
                                "6  06班学习成绩文件",
                                "7  07班学习成绩文件",
                                "0  返回上一级"
                           };
    char FileName[7][21] = { "class01.dat", "class02.dat", "class03.dat", "class04.dat", "class05.dat", "class06.dat", "class07.dat" };
    int  dd;
    if (!strcmp(WorkingFileName,""))//若WorkingFileName为空，及即当前没有已经打开了的文件，则执行下面程序选择班级来保存
    {
        while ( 1 )
        {
            ShowMenu( TitleName, showitem, 8 );
            scanf( "%d", &dd );
            if ( dd==0 )
                break;
            if ( dd<0 || dd>=8 )
                ShowSelectError(8);
            else
            {
                strcpy( WorkingFileName, FileName[dd-1] );//再赋值班级名
                break;
            }
        }
    }
    SaveData( pstu, num );
    ShowMessage(WorkingFileName,"文件已经保存！");
}


void Doinput( student_ *&pstu, int num )//登录数据，即在已打开的班级后面追加学生信息
{
    int i,cc;

    student_ *tail;
    tail=pstu;
    for(int j=1; j<num; ++j)
    {
        tail=tail->next;
    }//将tail移至最后一个学生地址

    printf( "\n\n数据登录操作！\n" );
    while(1)
    {
        printf( "\n请输入本次登陆学生人数: " );
        scanf( "%d", &cc );
        fflush(stdin);   //清空数据流
        if (cc>0 && cc<MAXNUM-num)
            break;
    }
    printf( "\n请依次输入下列学生数据:\n" );
    for ( i=0; i<cc; i++ )
    {
        tail->next = InputItem();
        //在已有学生后面追加登录信息
        if (tail->next==NULL)
        {
            printf("\n内存分配有错!\n");
            FreeMemory (pstu);
            //未分配到空间，销毁链表
            exit(-1);
        }
        tail=tail->next;
        tail->next=NULL;//方便销毁链表时找到结束点
        DataNum++;//该班级学生人数增加一个
    }
    EditFlag = 1;//表示数据已经修改过
}


void DoSearch( student_ *&pstu, int num )//查找数据
{
    char  TitleName[30] = "请选择需要查找的数据项";
    char  showitem[9][31] = {	"1   学号",
                                "2   姓名",
                                "3   性别",
                                "4   年龄",
                                "5   班级",
                                "6   英语",
                                "7   数学",
                                "8   C语言",
                                "0   返回上一级"
                            };
    char  sex = 0;
    int   item=-1,flag;
    int   dd;
    float score = 0.0;
    char  name[31] = "";

    while ( 1 )//只能根据一项标准来查找数据信息
    {
        ShowMenu( TitleName, showitem, 9 );
        scanf( "%d", &dd );
        if ( dd==0 )
            break;
        else if ( dd<0 || dd>=9 )
            ShowSelectError(9);
        else
        {
            if ( dd==1 )
            {
                printf("\n请输入要查找的学号：");
                scanf( "%s", name );
                fflush(stdin);
            }
            else if ( dd==2 )
            {
                printf("\n请输入要查找的姓名：");
                scanf( "%s", name );
                fflush(stdin);
            }
            else if ( dd==3 )
            {
                while(1)
                {
                    printf("\n请输入要查找的性别(M,F): ");
                    fflush(stdin);
                    scanf("%c", &sex);
                    fflush(stdin);
                    if ( sex=='M' || sex=='F')
                        break;
                    else
                        ShowMessage( "","数据输入有错，请重新输入！" );
                }
                if ( sex=='M' )
                    item = 0;
                else
                    item = 1;
            }
            else if ( dd==4 )
            {
                while(1)
                {
                    printf("\n请输入要查找的年龄: ");
                    scanf("%d", &item);
                    fflush(stdin);
                    if ( item>15 && item<32 )
                        break;//年龄只能在15到32之间
                    else
                        ShowMessage(  "","数据输入有错，请重新输入！" );
                }
            }
            else if ( dd==5 )
            {
                printf("\n请输入要查找的班级: ");
                scanf("%d", &item);
                fflush(stdin);
            }
            else if ( dd==6 )
            {
                while(1)
                {
                    printf("\n请输入要查找的英语成绩: ");
                    scanf("%f", &score);
                    fflush(stdin);
                    if ( score>=0 && score<=100 )
                        break;
                    else
                        ShowMessage(  "", "数据输入有错，请重新输入！");
                }
            }
            else if ( dd==7 )
            {
                while(1)
                {
                    printf("\n请输入要查找的数学成绩: ");
                    scanf("%f", &score);
                    fflush(stdin);
                    if ( score>=0 && score<=100 )
                        break;
                    else
                        ShowMessage( "","数据输入有错，请重新输入！" );
                }
            }
            else if ( dd==8 )
            {
                while(1)
                {
                    printf("\n请输入要查找的C语言成绩: ");
                    scanf("%f", &score);
                    fflush(stdin);
                    if ( score>=0 && score<=100 )
                        break;
                    else
                        ShowMessage("","数据输入有错，请重新输入！" );
                }
            }

            if ( !SearchData(pstu,num,item,name,score,dd) )//在该班级文件下查找并显示[一次只有一个数据有效]num(该班级下学生总数) item(性别，年龄，班级) name(学号，姓名) score(三科成绩) dd(数据项）
                ShowMessage(  WorkingFileName,"文件中没有找到要查找的数据！" );
            else
                ShowMessage( WorkingFileName,"文件中的数据查找完毕！" );
            break;
        }
    }
}


void DoEdit( student_ *&pstu, int num )//修改数据
{
    int  dd;
    char no[31];

    printf( "\n——————————————数据修改！——————————————\n" );
    printf( "\n请输入要修改的学生的学号：" );
    scanf( "%s", no );//把学号当做字符串来找
    dd = SearchNo( pstu, num, no );
    if ( dd<0 )
    {
        printf( "\n没找到需要修改的学生！\n" );
        return;
    }
    printf( "\n" );
    ShowOneItem( pstu, dd );//展示出第dd个学生的信息
    InputOneData( pstu, dd );//为修改第i个学生的信息而重新输入一组数据
    EditFlag = 1;//表示修改过了
}


void DoShow( student_ *&pstu, int num )//显示数据 已修改
{
    student_ *p;
    p=pstu;

    printf ("\n==========================班级数据表===========================\n");
    printf("      学号       姓名  性别 年龄 班级  英语  数学  C语言\n");
    while(p)
    {
        printf( "%10s%12s%4s%5d%6d%6.1f%6.1f%6.1f\n",
                p->stu.no, p->stu.name,
                (p->stu.sex==man)?"男":"女",
                p->stu.age,
                p->stu.classno,
                p->stu.English,
                p->stu.Math,
                p->stu.C_Language );
        p=p->next;
    }
    printf ("===============================================================\n");
}


void DoSort( student_ *&pstu, int num )//根据不同的标准进行排序
{
    char TitleName[30] = "请选择一个字段进行排序";
    char showitem[8][31] = {	"1   学号",
                                "2   姓名",
                                "3   英语",
                                "4   数学",
                                "5   C语言",
                                "0   返回上一级"
                           };
    int  dd;

    while ( 1 )
    {
        ShowMenu( TitleName, showitem, 6 );
        scanf( "%d", &dd );
        if ( dd==0 )
            break;//返回上一级
        if ( dd<0 || dd>=6 )
            ShowSelectError(6);//输入错误，重新选择
        else
        {
            SortStuInfo( pstu, num, dd );//dd表示排序的选择标准
            ShowMessage( WorkingFileName,"文件已经排序保存！");
            break;
        }
    }
}

void Dotongji( student_ *&pstu, int num )//统计数据
{
    tongjiall( pstu, num );
    ShowMessage( WorkingFileName, "\n统计结束！");
}
