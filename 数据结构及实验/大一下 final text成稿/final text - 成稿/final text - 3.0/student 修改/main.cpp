#include "score.h"

int  EditFlag = 0;
char WorkingFileName[31] = "";//班级文件名
int  DataNum = 0;//指该班级文件下有i个学生

int main(void)
{
    student_ *pstu;//指针，用链表记录文件中第一个学生结构的地址     （pstu->第一个student->各类信息）
    pstu=(student_ *)malloc(sizeof(student_));
    pstu->next=NULL;
    if(pstu==NULL)
    {
        printf("WRONG\n");
        return 0;
    }
    //初始化，即让pstu所指的第一个指针指空
    DoMainMenu(pstu);//主菜单显示及其相关操作(包括退出系统)
    FreeMemory(pstu);//释放申请的指针
    getch();
    return 0;
}





