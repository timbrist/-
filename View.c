#include "View.h"
void Menu()
{
    printf("|----------------------------学生表---------------------------------|\n");
    printf("|                            0. 退出                                |\n");
    printf("|                            1. 录入                                |\n");
    printf("|                            2. 查找                                |\n");
    printf("|                            3. 删除                                |\n");
    printf("|                            4. 修改                                |\n");
    printf("|                            5. 插入                                |\n");
    printf("|                            6. 排序                                |\n");
    printf("|                            7. 统计                                |\n"); 
    printf("|-------------------------------------------------------------------|\n");
}
void DisplayExit()
{
    printf("学生管理系统以退出\n");
}
void DisplaySelection()
{
    printf("选择: ");
}
void isSure()
{
    printf("您确定退出吗?<y/n>: ");
}
void PrintInputFeedback(bool isSaved)
{
    if(isSaved)
        printf("Saved\n");
    else
        printf("Failed\n");
}


//========================pFunc[0]=======================================
//==========================================================    

int GetNum()
{ 
    int num = 0;
    printf("请输入学生号： ");
    scanf("%d", &num);
    return num;
}

void ShowStudents(char *num, char *name, char *elective, char *experiment,char *required, char *sum)
{
    //printf("NUMBER\tNAME\tELECTIVE\tEPERIMENT\tREQUIRED\tSUM");
    printf("%s\t%s\t%s\t%s\t%s\t%s\n",num,name,elective,experiment,required,sum);
}

int StuNum()
{ 
    int num = 0;
    printf("学号: ");
    scanf("%d", &num);
    printf("\n"); 
    return num;
}
void StuName(char *name)
{
    printf("姓名: ");
    scanf("%s", name);
}
int Elective()
{ 
    int elective = 0;
    printf("选修课: ");
    scanf("%d", &elective);
    printf("\n");
    return elective;
}
int Experiment()
{ 
    int experiment = 0;
    printf("实验课: ");
    scanf("%d",&experiment);
    printf("\n");
    return experiment;
}
int Required()
{ 
    int required = 0;
    printf("必修课: ");
    scanf("%d", &required);
    printf("\n");
    return required;
}
