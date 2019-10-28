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


typedef struct StudentNode
{
    int id;
    student s;
    struct StudentNode *next;
}studentnode;

char StudentInfo[MAXLINE];
