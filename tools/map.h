//===========map.h
#pragma once
//============轮子: hashtable===================
#include<stdlib.h>
#include"../Student.h"//自定义的数据结构; 未实现泛型编程，需要复用需要更改以下
#define HASH_TABLE_SIZE 10007//素数
#define NULLKEY -10007

typedef student info; //将数据类型更名
//typedef char info;

//用于存放 <key, value>的数据结构， 俗称哈希槽
typedef struct Bucket
{
    int key;
    info value;
}bucket;
//哈希表
typedef struct HashTable
{
    int count;
    bucket *buckets;

}hashtable;

int Hash(int key);
void AddHash(hashtable *m, int k, info v);
void InitHash(hashtable *m);
int FindHash(hashtable *m, int k);
void FreeHash(hashtable *m);
void ModifyHash(hashtable *m, int k, info newinfo);
info GetHashValue(hashtable *m, int k);
void DeleteHash(hashtable *m, int k);

//===============封装map
typedef struct Map
{
    hashtable h;
    void(*AddMap)(struct Map *This, int k, info v);
    int(*FindMap)(struct Map *This, int k);
    void(*FreeMap)(struct Map *This);
    info(*GetMapValue)(struct Map *This, int k);
    int (*CountMap)(struct Map *This);
    void (*ModifyMap)(struct Map *This, int k, info v);
    void (*DeleteMap)(struct Map *This, int k);

}map;
void InitMap(map *This);
void AddMap(struct Map *This, int k, info v);
int FindMap(struct Map *This, int k);
void FreeMap(struct Map *This);
info GetMapValue(struct Map *This, int k);
int CountMap(struct Map *This);
void ModifyMap(struct Map *This, int k, info v);
void DeleteMap(struct Map *This, int k);
