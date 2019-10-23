#include "Controller.h"


void MainWindow()
{
    int select = 1;
    void (*pFunc[8])() ={Exit, Input,Search, Delete,
                         Modify, Insert, Order, Sum};
    while(true)
    {
        Menu();
        DisplaySelection(); 
        scanf("%d", &select);
        //TODO: do menu things;
        if( select >= 0 && select <=7)
            pFunc[select]();
        else
            break;
    }
    DisplayExit();

}

//============从View中得到的数据============

void Input()
{
    int num = StuNum();
    char name[16];
    StuName(name);
    int elective = Elective();
    int experiment = Experiment();
    int required = Required();
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



//==================将数据传递给Model===============
