//===============map.c=================================
#include"map.h"

//===============================hashmap=====================
void InitHash(hashtable *m)
{
    m->buckets = (bucket *)malloc(HASH_TABLE_SIZE * sizeof(bucket));
    for (int i = 0; i < HASH_TABLE_SIZE; ++i)
    {
        m->buckets[i].key = NULLKEY;
    }
}

int Hash(int key)
{
    return key % HASH_TABLE_SIZE;
}
void AddHash(hashtable *m, int k, info v)
{
    
    int addr = Hash(k);
    //TODO: 开放定址法  
    while (m->buckets[addr].key != NULLKEY)
        addr = (addr + 1) % HASH_TABLE_SIZE;
    
    m->buckets[addr].key = k;
    m->buckets[addr].value = v;

}
int FindHash(hashtable *m, int k)
{
    int addr = Hash(k);
    while (m->buckets[addr].key != k)
    {
        addr = (addr + 1) % HASH_TABLE_SIZE;
        if (m->buckets[addr].key == NULLKEY ||
            addr == Hash(k))
        {
            return -1;
        }
    }
    return addr;
}
void FreeHash(hashtable *m)
{
    free(m->buckets);
}
info GetHashValue(hashtable *m, int k)
{
    return m->buckets[FindHash(m,k)].value;
}
void ModifyHash(hashtable *m, int k, info newinfo)
{
    m->buckets[FindHash(m, k)].value = newinfo;
}
void DeleteHash(hashtable *m, int k)
{
    int addr = Hash(k);
    while(m->buckets[addr].key != k)
    {
        addr = (addr +1 ) % HASH_TABLE_SIZE;
        if(m->buckets[addr].key == NULLKEY ||
           addr == Hash(k) )
        {
            return;
        }   
    }
    m->buckets[addr].key = NULLKEY;
}
//=========================================================

//===========================map=======================
void InitMap(map *This)
{
    This->AddMap = AddMap;
    This->FindMap = FindMap;
    This->FreeMap = FreeMap;
    This->GetMapValue = GetMapValue;
    This->CountMap = CountMap;
    This->ModifyMap = ModifyMap;
    This->DeleteMap = DeleteMap;
    This->h.count = 0;
    InitHash(&This->h);
}
void AddMap(struct Map *This, int k, info v)
{
    ++This->h.count;
    AddHash(&This->h, k, v);
}
int FindMap(struct Map *This, int k)
{
    return FindHash(&This->h, k);
}

void FreeMap(struct Map *This)
{
    FreeHash(&This->h);
}
info GetMapValue(struct Map *This, int k)
{
    return GetHashValue(&This->h, k);
}
int CountMap(struct Map *This)
{
    return This->h.count;
}
void ModifyMap(struct Map *This,int k, info v)
{
    ModifyHash(&This->h, k, v);
}
void DeleteMap(struct Map *This, int k)
{
    DeleteHash(&This->h, k);
}

