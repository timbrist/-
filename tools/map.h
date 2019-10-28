//===========map.h
#pragma once
//============轮子: hashtable===================
#include<stdlib.h>
#define HASH_TABLE_SIZE 10007//素数
typedef char info;

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

//===============封装map
typedef struct Map
{
    hashtable h;
    void(*Add)(struct Map *This, int k, info v);
    int(*Find)(struct Map *This, int k);
    void(*Free)(struct Map *This);
    info(*GetValue)(struct Map *This, int k);
    int (*Count)(struct Map *This);
    void (*Modify)(struct Map *This, int k, info v);

}map;
void InitMap(map *This);
void Add(struct Map *This, int k, info v);
int Find(struct Map *This, int k);
void Free(struct Map *This);
info GetValue(struct Map *This, int k);
int Count(struct Map *This);
void Modify(struct Map *This, int k, info v);
