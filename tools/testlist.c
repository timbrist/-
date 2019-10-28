#include"list.h"


int main()
{
    printf("hello world");

    Value v[10];
    v[0].total = 2;
    v[0].id = 20;
    v[1].total = 4;
    v[1].id = 40;
    v[2].total = 6;
    v[2].id = 60;
    v[3].total = 8;
    v[3].id = 80;
    v[4].total = 1;
    v[4].id = 10;
    v[5].total = 3;
    v[5].id = 30;
    v[6].total = 5;
    v[6].id = 50;
    v[7].total = 7;
    v[7].id = 70;
    v[8].total = 9;
    v[8].id = 90;
    v[9].total = 10;
    v[9].id = 100;
    list l;
    InitList(&l);
    for (int i = 0; i < 10; ++i)
    {
        l.Add(&l, v[i]);
    }
    l.Print(&l);
    printf("------------sort--------------\n"); 
    l.Sort(&l);
    l.Print(&l);
    printf("--------------------------------/n");
    Value vv;
    vv.id = 80;
    vv.total = 8;
    l.Delete2(&l, vv);
    l.Print(&l);
    l.Free(&l);

    getchar();
    return 0;
}
