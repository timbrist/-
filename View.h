#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void DisplayExit();
void DisplaySelection();
void isSure();

void isContinue();
void DisplayTitle();
int GetNum();
void ShowStudents(char *num, char *name, char *elective, char *experiment,char *required, char *sum);
void DisplayStudentTable(int num, char name[],
                         int elective, int experiment,
                         int required);

void PrintInputFeedback(bool isSaved);
void MainWindow_test();

void ShowStudents(char *num, char *name, char *elective, char *experiment,char *required, char *sum);
int StuNum();
void StuName(char *name);
int Elective();
int Experiment();
int Required();
