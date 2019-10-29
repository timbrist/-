//===============list.h================
#pragma once
#include<stdlib.h>
#include<stdio.h>
#include"../Student.h"
#define NULLVALUE -5019
//==================================linklist======================
/*
typedef struct Value 
{
    int id;//唯一值
    int total;//需要排序的值
}Value;
*/
typedef student Value;//复用需要修改自定义数据,以及以下几个函数

typedef struct LinkNode
{
    Value value;
    struct LinkNode *next;
}linknode;



//初始化, //复用：自定义数据结构
void InitLinkList(linknode *list);
//添加
void AddNode(linknode *list, Value v);
//插入
void InsertNode(linknode *list, Value v, int i);
//统计
int CountList(linknode *list);
//从大到小排序
void SortList(linknode *list);
//显示//复用：需要修改显示的数据类型
void PrintList(linknode *list);
//查找前一个 //复用：Value 特定的值
linknode *FindPrevious(linknode *list, Value v);
//删除 //依赖FindPrevious
void DeleteNode(linknode *list, Value v);
//删除某个位置的结点
void DeleteList(linknode *list, int position);
//删除有key的节点
void DeleteListValue(linknode *list, int onlykey);
//修改//复用: 需要oldValue中的某个唯一值
void ModifyList(linknode *list, Value oldValue, Value newValue);
//根据key 修改当前value
void ModifyListValue(linknode *list, int onlykey, Value newv);
//查找
linknode* FindNode(linknode *list,Value v);

//根据key，查询整个value
Value GetListValue(linknode *list,int onlykey);
//使用完要回收
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
    void(*Delete2)(struct List *This, Value v);
    void(*DeleteValue)(struct List *This, int onlykey); 
    Value(*GetValue)(struct List *This, int onlykey);
    void(*Modify2)(struct List *This, Value oldValue, Value newValue);
    void(*Modify)(struct List *This, int onlykey, Value newv);
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
void Delete2(struct List *This, Value v);
void Modify2(struct List *This, Value oldValue, Value newValue);
void Modify(struct List *This, int onlykey, Value newv);
Value GetValue(struct List *This, int onlykey );
void DeleteValue(struct List *This, int onlykey);
