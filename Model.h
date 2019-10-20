#include<stdio.h>
#define MAXLINE 64
typedef struct Student
{
    char num[16];
    char name[16];
    char elective_grade[4];
    char experiment_grade[4];
    char required_grade[4];
    unsigned int elective;
    unsigned int experiment;
    unsigned int required;
}stu;

typedef struct StuNode
{
    unsigned int id;
    stu s;
    struct StuNode *next;
}stuNode;

void SetStudentInfo(stuNode *node, char *num, char *name,
                    unsigned int elective, unsigned int experiment,
                    unsigned int required);
void ReadFile(const char *filename);
void WriteFile(const char  *filename,const char *type,char *str);
void Add(stuNode * stuNode);
