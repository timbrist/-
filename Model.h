#include<stdio.h>
#include<stdlib.h>
#include"Student.h"
#include<string.h>

#define MAXROWS 1024
#define FILENAME "../StudentInfo.txt"

int GetFileLines(const char *filename);
int isFileEmpty(const char *filename);
void GetStudentLine(student *stu, int filelines);
void WriteFile(const char *filename, char *str);
