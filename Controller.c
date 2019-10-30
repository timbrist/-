#include"Controller.h"


void MainWindow()
{
   
    int select = 1;
    void (*pFunc[11])(list *l) ={ControlExit, ControlInput,ControlSearch, ControlDelete,
                         ControlModify, ControlInsert, ControlOrder, ControlSum,ControlDisplay,ControlSave};
    list l;
    InitList(&l); 
  
    //load file ;
    LoadFile(&l);
 
    while(true)
    {
        Menu();
        DisplaySelection(); 
        scanf("%d", &select);
        //TODO: do menu things;
        if( select > 0 && select <=9)
            pFunc[select](&l);
        else
            break;
    }
    l.Free(&l);
    printf("退出成功\n");
}
void LoadFile(list *l)
{
    //1.判断file是否为空

    //if(isFileEmpty("studentfileinfo.txt"))return;

    int filelines = GetFileLines(FILENAME); 

    //printf("filelines:%d\n", filelines);
    student *stu = (student *)malloc(sizeof(student) *filelines);
    GetStudentLine(stu, filelines);

    //printf("required:%d\n", stu[1].required);
    for(int i = 0; i < filelines-1; ++i) 
        l->Add(l,stu[i]);
    free(stu);


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
void ControlDisplay(list *l)
{
    l->Print(l);
}
void ControlSave(list * l)
{
    
    linknode *head = &l->l;
    char studentfileinfo[MAXLINE];
    char num[16];
    char name[16];
    char el[8];
    char ex[8];
    char re[8];
    char total[8];
    FILE *fp;
    if( (fp = fopen(FILENAME,"w")) ==NULL) 
    {
        printf("Open file failed\n");
        return;
    } 
    fclose(fp);
    printf("num:%d\n",head->value.num);
    while(head != NULL)
    {

        //1.将value的学生信息封装为字符串
        sprintf(num, "%d", head->value.num);
        strcpy(name,head->value.name);
        sprintf(el, "%d",head->value.elective);   
        sprintf(ex, "%d", head->value.experiment);
        sprintf(re, "%d", head->value.required);
        sprintf(total, "%d",head->value.total);

        studentfileinfo[0]='\0';
        printf("num2:%s\n",num);
        strcat(studentfileinfo,num);
        printf("num3:%s\n",studentfileinfo);
        strcat(studentfileinfo,";");
        strcat(studentfileinfo,name);
        strcat(studentfileinfo,";");
        strcat(studentfileinfo,el);
        strcat(studentfileinfo,";");
        strcat(studentfileinfo,ex);
        strcat(studentfileinfo,";");
        strcat(studentfileinfo,re);
        strcat(studentfileinfo,";");
        strcat(studentfileinfo,total);
        strcat(studentfileinfo,"\n");
        printf("info： %s\n", studentfileinfo);
        WriteFile(FILENAME,studentfileinfo);
        studentfileinfo[0] = '\0'; 
        head = head->next;
        
    }
   
}

