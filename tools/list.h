//===============list.h================
#pragma once
#include<stdlib.h>
#include<stdio.h>
#define NULLVALUE -5019
//==================================linklist======================
typedef struct Value //如果要服用这里是需要修改的 自定义数据
{
    int id;
    int total;
}Value;
typedef struct LinkNode
{
    Value value;
    struct LinkNode *next;
}linknode;

void InitLinkList(linknode *list);
void AddNode(linknode *list, Value v);
void InsertNode(linknode *list, Value v, int i);
int CountList(linknode *list);
int Partition(Value *a, int low, int high, int pivotkey);
void QSort(Value *a, int low, int high);
void SortList(linknode *list);
void PrintList(linknode *list);
void DeleteList(linknode *list, int position);
void FreeList(linknode *list);
//===============================================================

//==========================List=============================
typedef struct List//对外部使用的接口
{
    linknode l;
    void(*Add)(struct List *This, Value v);
    void(*Insert)(struct List *This, Value v, int position);
    int(*Count)(struct List *This);
    void(*Sort)(struct List *This);
    void(*Print)(struct List *This);
    void(*Delete)(struct List *This, int position);
    void(*Free)(struct List *This);
}list;
void InitList(list *This);
void Add(struct List*This, Value v);
void Insert(struct List*This, Value v, int position);
int Count(struct List*This);
void Sort(struct List*This);
void Print(struct List*This);
void Free(struct List*This);
void Delete(struct List *This, int position);
