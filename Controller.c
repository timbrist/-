#include "Controller.h"
#include <stdlib.h>

    
void MainWindow()
{
    int select = 1;
    void (*pFunc[8])(studentnode *studentlist) ={Exit, Input,Search, Delete,
                         Modify, Insert, Order, Sum};
    studentnode *studentlist = (studentnode *)malloc(sizeof(studentnode));
    studentlist->id = 0;//第0个节点不用

    while(true)
    {
        Menu();
        DisplaySelection(); 
        scanf("%d", &select);
        //TODO: do menu things;
        if( select >= 0 && select <=7)
            pFunc[select](studentlist);
        else
            break;
    }
    studentnode *head = studentlist;
    FreeList(head);
    DisplayExit();

}

//============从View中得到的数据============

void Input(studentnode *studentlist)
{
    char select = 'n';
    while(true)
    {
        //======调用View获取原始数据
        int num = StuNum();
        char name[16];
        StuName(name);
        int elective = Elective();
        int experiment = Experiment();
        int required = Required();
        //=============
       
        //将原始数据封装为student类型
        studentnode *node = (studentnode *)malloc(sizeof(studentnode)); 
        SetNum(node, num);
        SetName(node, name);
        SetElective(node, elective);
        SetExperiment(node, experiment);
        SetRequired(node, required);
        Append(studentlist, node);
        DisplayList(studentlist);
         //=======调用Model写入文件 
        Append2File(node); 
        isContinue();
        select = getchar();
        scanf("%c",&select);
        if(select != 'y')
            break;
    }
    
   
}
void Exit()
{
    char e;
    isSure();
    getchar();
    e = getchar(); 
    if(e == 'y')
        exit(0);
       
}

void Search()
{
    int num = GetNum();
    //TODO: controller Search(num)
    //RETURN: char studentInfo[MAXLINE]

}
void Delete()
{
    int num = GetNum();
}
void Modify()
{
    int num = GetNum();
}
void Insert()
{
    int num = GetNum();
}
void Order()
{
    int num = GetNum();
}
void Sum()
{
    int number = 100;
    printf("总人数为： %d",number);
    printf("\n");
}
//============================================
void FreeList(studentnode *node)
{
    studentnode *head = node;
    while(node != NULL)
    {
       head = node->next;
       free(node);
       node = head;
    }
}
void Append(studentnode* studentlist, studentnode *node)
{
    if(node == NULL) return;
    studentnode *head = studentlist;
    int count = 1;
    while(head->next != NULL)
    {
        head = head->next;
        ++count;
    }
    node->id = count;
    head->next = node; 
}
void DisplayList(studentnode *studentlist)
{
    studentnode *head = studentlist;
    DisplayTitle();
    if(head == NULL) return;
    while(head != NULL)
    {
        if(head->id == 0 ) 
        {
            head = head->next;
            continue;
        }
        DisplayStudentTable(head->s.num,
                head->s.name,
                head->s.elective,
                head->s.experiment,
                head->s.required);
        head= head->next;
    }
}


//==================将数据传递给Model===============
