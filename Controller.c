#include"Controller.h"


void MainWindow()
{
    int select = 1;
    void (*pFunc[8])(map *m, list *l) ={ControlExit, ControlInput,ControlSearch, ControlDelete,
                         ControlModify, ControlInsert, ControlOrder, ControlSum};
    list l;
    InitList(&l);
    map m;
    InitMap(&m);    
    while(true)
    {
        Menu();
        DisplaySelection(); 
        scanf("%d", &select);
        //TODO: do menu things;
        if( select >= 0 && select <=7)
            pFunc[select](&m,&l);
        else
            break;
    }
}
void ControlExit()
{}
void ControlInput(map *m, list *l)
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
        //======数据保存到map内存中======
        m->AddMap(m,num,stu);

        //======学号和总成绩保存到list内存中===
        Value v;
        v.id = num;
        v.total = elective + experiment + required;
        l->Add(l,v);

        //=========输出学生表====================
        
        DisplayStudentTable(num,name,elective,experiment,required);
        //======询问用户是否继续===========
        isContinue();
        select = getchar();
        scanf("%c",&select);
        if(select != 'y')
            break;

   } 
}
void ControlInsert()
{}
void ControlSearch(map *m, list *l)
{
    int num = StuNum();
    student stu;
    stu = GetMapValue(m, num);

    //=========================================
    DisplayStudentTable(stu.num, stu.name, stu.elective,
            stu.experiment, stu.required);
}
void ControlDelete(map *m, list *l)
{
    int num = StuNum();
    //=======delete map=====
    m->DeleteMap(m, num); 
    //=======delete list=====
}
void ControlModify()
{}
void ControlOrder()
{}
void ControlSum()
{}
