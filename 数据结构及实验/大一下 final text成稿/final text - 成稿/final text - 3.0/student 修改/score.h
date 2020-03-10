#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


#ifndef SCORE_H
#define SCORE_H

#define TRUE	1
#define FALSE	0
#define MAXNUM	100


enum SEX { man, female };
struct Student_Info
{
    char	no[9];			//学号
    char	name[20];		//姓名
    enum	SEX sex;		//性别
    int	age;			//年龄
    int	classno;		//班级
    float	Math;			//数学
    float	C_Language;		//C语言
    float	English;//英语
};

struct LinkNode//为避免文件中没有指针空间的问题，将信息和指针分开来写
{
    Student_Info stu;
    LinkNode* next;
};

typedef struct Student_Info STUDENT;
typedef struct LinkNode student_;


student_ *GetStuInfo(int i);
void SortStuInfo(student_ *pstu, int num);
void Swap(student_ *p, student_ *q);
void FreeMemory(student_ *pstu, int num);

extern int  EditFlag;
extern char WorkingFileName[31];
extern int  DataNum;

void DoOpen(student_ *&, int);
void DoSave(student_ *&, int);
void Doinput(student_ *&, int);
void DoSearch(student_ *&, int);
void DoEdit(student_ *&, int);
void DoShow(student_ *&, int);
void DoSort(student_ *&, int);
void Dotongji(student_ *&, int);

void ShowMessage( char *msg, char *str );
void ShowMenu( char *title, char menuitem[][31], int cc );
int  ShowIsSave(void);
void ShowSelectError( int cc );
void ShowQuit( student_ *pstu );
void IsSave( student_ *pstu );

void DoMainMenu( student_ *pstu );

int  OpenData( student_ **pstu, int num );
int  SaveData( student_ *pstu, int num );

student_ *InputItem(void);
void ShowOneItem( student_ *pstu, int i );
void InputOneData( student_ *pstu, int i );

int  SearchData(student_ *pstu, int num, int item, char *name, float score, int dd );
int  SearchNo(student_ *pstu, int num, char *name );
void SortStuInfo( student_ *pstu, int num, int cc );
void tongjiall( student_ *pstu, int num );

void FreeMemory(student_ *pstu);

#endif
