#include<string.h>
#include<stdio.h>
#define MAXLINE 64
//学生信息
typedef struct Student
{
    char num[16];
    char name[16];
    char elective_grade[4];
    char experiment_grade[4];
    char required_grade[4];//用于写入文件
    unsigned int number;//学号排序
    unsigned int elective;//用于排序
    unsigned int experiment;
    unsigned int required;
}stu;

//学生信息节点
typedef struct StuNode
{
    char stuFile[MAXLINE];//写入文件一行信息
    unsigned int id;
    stu s;
    struct StuNode *next;
}stuNode;

void SetStudentInfo(stuNode *node, unsigned int number, char *name,
                    unsigned int elective, unsigned int experiment,
                    unsigned int required);
void ReadFile(const char *filename);
void WriteFile(const char  *filename,const char *type,char *str);
void Append2File(stuNode * stuNode);


unsigned int StudentNumber(stuNode *node);
void OrderStudent(stuNode *node);
void InsertStudent(stuNode *node, unsigned int index, stuNode *newNode);
void ModifyStudent(stuNode *node,unsigned int number, stuNode *newNode);
void DeleteStudent(stuNode *node, unsigned int number);
stuNode *FindStudent(stuNode *node, unsigned int number);
