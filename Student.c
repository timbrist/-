#include "Student.h"

void SetStudent(student *stu, int n, char na[], int el, int ex, int re)
{
    stu->num = n;
    strcpy(stu->name, na);
    stu->elective = el;
    stu->experiment = ex;
    stu->required = re;
    stu->total = el + ex + re;
}
