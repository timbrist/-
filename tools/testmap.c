// gcc testmap.c map.c
//main.cpp
#include"map.h"
#include<stdio.h>


int main()
{
    map m;
    InitMap(&m);
    char x = 'x';
    m.Add(&m, 19, x);
    m.Add(&m, 89, 'e');
    m.Add(&m, 28, 'p');
    printf("this is map:%c\n", m.GetValue(&m,19));
    printf("%c\n", m.GetValue(&m, 89));
    printf("%c\n", m.GetValue(&m, 28));
    printf("%d\n", m.Count(&m));
    m.Free(&m);
    getchar();
    return 0;
}

