#pragma once
#include<string.h>
#define MAXLINE 128
typedef struct Student
{
    int num;
    char name[16];
    int elective;
    int experiment;
    int required;
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

