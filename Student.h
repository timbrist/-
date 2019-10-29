#pragma once
#include<string.h>
#define MAXLINE 128
typedef struct Student
{
    int id;//唯一值&&递增
    int num;//序号
    char name[16];//姓名
    int elective;//选修课
    int experiment;//实验课
    int required;//必修课
    int total;//总成绩， 需要排序的值
}student;

typedef struct StudentFile
{
    char num[16];
    char name[16];
    char elective[8];
    char experiment[8];
    char required[8];
    char sum[8];
}studentfile;

char StudentInfo[MAXLINE];

void SetStudent(student *stu, int n, char na[], int el, int ex, int re);

