#include<string.h>
#include<stdio.h>
#include"Student.h"


void SetStudentInfo(studentnode *node, int number, char *name,
                    int elective, int experiment,
                    int required);
void ReadFile(const char *filename);
void WriteFile(const char  *filename,const char *type,char *str);

void LoadFile();

void Append2File(studentnode *studentnode);

void SetNum(studentnode *node, int number);
void SetName(studentnode *node, char name[]);
void SetElective(studentnode *node, int elective);
void SetExperiment(studentnode *node, int experiment);
void SetRequired(studentnode *node, int required);

int StudentNumber(studentnode *node);
void OrderStudent(studentnode *node);
void InsertStudent(studentnode *node, int index, studentnode *newNode);
void ModifyStudent(studentnode *node,int number, studentnode *newNode);
void DeleteStudent(studentnode *node, int number);
studentnode *FindStudent(studentnode *node, int number);

