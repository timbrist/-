#include"Controller.h"


void MainWindow()
{
    int select = 1;
    void (*pFunc[8])(list *l) ={ControlExit, ControlInput,ControlSearch, ControlDelete,
                         ControlModify, ControlInsert, ControlOrder, ControlSum};
    list l;
    InitList(&l); 
    while(true)
    {
        Menu();
        DisplaySelection(); 
        scanf("%d", &select);
        //TODO: do menu things;
        if( select > 0 && select <=7)
            pFunc[select](&l);
        else
            break;
    }
    l.Free(&l);
    printf("退出成功\n");
}
void ControlExit()
{}
void ControlInput(list *l)
{
   char select = 'n';
   while(true)
   {  
       //======调用View获取原始数据=====       
        int num = StuNum();
        char name[16];
        StuName(name);
        int elective = Elective();
        int experiment = Experiment();
        int required = Required();
        //======封装为学生数据======
        student stu;
        SetStudent(&stu,num,name,elective,experiment,required);
        //======学号和总成绩保存到list内存中=== 
        l->Add(l,stu);
        //=========输出学生表==================== 
        //DisplayStudentTable(num,name,elective,experiment,required);
        l->Print(l);
        //======询问用户是否继续===========
        isContinue();
        select = getchar();
        scanf("%c",&select);
        if(select != 'y')
            break;

   } 
}
void ControlInsert(list *l)
{
    char select = 'n';
    while(true)
    {
        int p = GetPosition();
        printf("请输入插入后的学生信息\n");
       //======调用View获取原始数据=====       
        int num = StuNum();
        char name[16];
        StuName(name);
        int elective = Elective();
        int experiment = Experiment();
        int required = Required();
        //======封装为学生数据======
        student stu;
        SetStudent(&stu,num,name,elective,experiment,required);
        //======学号和总成绩保存到list内存中=== 
        l->Insert(l,stu,p);
        //=========输出学生表==================== 
        //DisplayStudentTable(num,name,elective,experiment,required);
        l->Print(l);
        //======询问用户是否继续===========
        isContinue();
        select = getchar();
        scanf("%c",&select);
        if(select != 'y')
            break;
    }
}
void ControlSearch(list *l)
{
    int num = StuNum();
    student stu;    
    stu = l->GetValue(l, num);
    //=========================================
    DisplayStudentTable(stu.num, stu.name, stu.elective,
            stu.experiment, stu.required);
}
void ControlDelete( list *l)
{
    int num = StuNum();  
    //=======delete list===== 
    l->DeleteValue(l,num); 
}
void ControlModify(list *l)
{
    char select = 'n';
    while(true)
    {
        int p = GetPosition();
        printf("请输入插入后的学生信息\n");
       //======调用View获取原始数据=====       
        int num = StuNum();
        printf("输入一下需要修改的信息");
        char name[16];
        StuName(name);
        int elective = Elective();
        int experiment = Experiment();
        int required = Required();
        //======封装为学生数据======
        student stu;
        SetStudent(&stu,num,name,elective,experiment,required);
        //======学号和总成绩保存到list内存中=== 
        l->Modify(l,num, stu);
        //=========输出学生表==================== 
        //DisplayStudentTable(num,name,elective,experiment,required);
        l->Print(l);
        //======询问用户是否继续===========
        isContinue();
        select = getchar();
        scanf("%c",&select);
        if(select != 'y')
            break;
    }

}
void ControlOrder(list *l)
{
    l->Sort(l);
    l->Print(l);
}
void ControlSum(list *l)
{ 
    int count = l->Count(l);
    printf("总人数:%d\n", count);
}
void DisplayAll(list *l)
{
    l->Print(l);
}
