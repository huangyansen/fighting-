#include <stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

//5
//      1234         liu  �� 22   123  77.0  67.0  82.0
//      1235       zhang  Ů 21   123  82.0  68.0  73.0
//      1236        wang  �� 25   123  65.0  82.0  81.0


//7
//      1235       zhang  �� 23   123  87.0  67.0  88.0
//      1236        wang  �� 24   123  85.0  76.0  90.0
//      1002        sewi  �� 24   211  88.0  67.0  89.0
//      1234         liu  Ů 22   123  67.0  78.0  87.0
//      2112        hong  Ů 23   211  78.0  77.0  90.0
//      2113        hong  �� 24   211  77.0  58.0  89.0
//      1237        hong  �� 22   211  78.0  82.0  89.0
//      1001         hei  Ů 24   211  84.0  67.0  89.0

enum SEX { man, female };
struct Student_Info
{
	char	no[9];			//ѧ��
	char	name[20];		//����
	enum	SEX sex;		//�Ա�
	int	age;			//����
	int	classno;		//�༶
	float	Math;			//��ѧ
	float	C_Language;		//C����
	float	English;		//Ӣ��
	struct Student_Info *next;
}stu[8]={ {"1235",  "zhang", man, 23, 123, 87.0, 67.0, 88.0},
          {"1236",   "wang", man, 24, 123,  85.0, 76.0, 90.0},
          {"1002",   "sewi",  man, 24, 211, 88.0, 67.0,  89.0},
          {"1234",    "liu", female, 22,   123,  67.0,  78.0,  87.0},
          {"2112",   "hong",  female, 23,   211,  78.0,  77.0,  90.0},
          {"2113",   "hong",  man, 24,  211,  77.0,  58.0,  89.0},
          {"1237",   "hong",  man, 22,   211,  78.0,  82.0,  89.0},
          {"1001",    "hei",  female, 24,   211,  84.0,  67.0,  89.0},
          };

typedef struct Student_Info STUDENT;



int main()
{
   FILE *fp;
   fp=fopen("class07.dat","wb+");
   if(fp==NULL){printf("WRONG\n"); return 0;}

   fwrite(stu,sizeof(STUDENT),8,fp);
   rewind(fp);
   memset(stu,0,8*sizeof(STUDENT));
   for(int i=0;i<8;++i){
    fseek(fp,i*sizeof(STUDENT),SEEK_SET);
    fread(&stu[i],sizeof(STUDENT),1,fp);
    printf( "%10s%12s%4s%3d%6d%6.1f%6.1f%6.1f\n",
				stu[i].no, stu[i].name,
				(stu[i].sex==man)?"��":"Ů",
				stu[i].age,
				stu[i].classno,
				stu[i].English,
				stu[i].Math,
				stu[i].C_Language );
   }
    return 0;
}
