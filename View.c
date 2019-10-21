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
void PrintInputFeedback(bool isSaved)
{
    if(isSaved)
        printf("Saved\n");
    else
        printf("Failed\n");
}
bool Select(unsigned int *select)
{
    printf("选择: ");
    scanf("%u",select);
    if(*select > 7 || *select < 0)
        return false;
    else
        return true;
}
bool SelectStuNum(unsigned int *num)
{
    printf("请输入学号: ");
    scanf("%u", num);
    //TODO: judge num is aviable
    return true;
}
void ShowStudents(char *num, char *name, char *elective, char *experiment,char *required, char *sum)
{
    //printf("NUMBER\tNAME\tELECTIVE\tEPERIMENT\tREQUIRED\tSUM");
    printf("%s\t%s\t%s\t%s\t%s\t%s\n",num,name,elective,experiment,required,sum);
}

bool InputStuNum(unsigned int *num)
{ 
    printf("学号: ");
    scanf("%u", num);
    printf("\n");
    if(*num - 100000000 > 0)
       return false;
    else
       return true; 
}
bool InputStuName(char *name)
{
    printf("姓名: ");
    scanf("%s", name);
    printf("\n");
    if(name == NULL)
        return false;
    else
        return true;
}
bool InputElective(unsigned int *elective)
{ 
    printf("选修课: ");
    scanf("%u", elective);
    printf("\n");
    if(*elective - 100 > 0)
       return false;
    else
       return true; 
}
bool InputExperiment(unsigned int *experiment)
{ 
    printf("实验课: ");
    scanf("%u", experiment);
    printf("\n");
    if(*experiment- 100> 0)
       return false;
    else
       return true; 
}
bool InputRequired(unsigned int *required)
{ 
    printf("必修课: ");
    scanf("%u", required);
    printf("\n");
    if(*required - 100 > 0)
       return false;
    else
       return true; 
}
