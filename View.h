#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void Menu();
void Exit();
void Input();
void Delete();
void Search();
void Modify();
void Insert();
void Order();
void Sum();

void ShowStudents(char *num, char *name, char *elective, char *experiment,char *required, char *sum);

void PrintInputFeedback(bool isSaved);
void MainWindow();

void ShowStudents(char *num, char *name, char *elective, char *experiment,char *required, char *sum);
int StuNum();
void StuName(char *name);
int Elective();
int Experiment();
int Required();
