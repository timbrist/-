#include<stdio.h>
#include<stdbool.h>

void Menu();
void ShowStudents(char *num, char *name, char *elective, char *experiment,char *required, char *sum);

void PrintInputFeedback(bool isSaved);
bool Select(unsigned int *select);
bool SelectStuNum(unsigned int *num);
void ShowStudents(char *num, char *name, char *elective, char *experiment,char *required, char *sum);
bool InputStuNum(unsigned int *num);
bool InputStuName(char *name);
bool InputElective(unsigned int *elective);
bool InputExperiment(unsigned int *experiment);
bool InputRequired(unsigned int *required);
