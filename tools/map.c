//===============map.c=================================
#include"map.h"

//===============================hashmap=====================
void InitHash(hashtable *m)
{
    m->buckets = (bucket *)malloc(HASH_TABLE_SIZE * sizeof(bucket));
    for (int i = 0; i < HASH_TABLE_SIZE; ++i)
    {
        m->buckets[i].key = -10007;
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
    while (m->buckets[addr].key != -10007)
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
        if (m->buckets[addr].key == -10007 ||
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
//=========================================================

//===========================map=======================
void InitMap(map *This)
{
    This->Add = Add;
    This->Find = Find;
    This->Free = Free;
    This->GetValue = GetValue;
    This->Count = Count;
    This->Modify = Modify;
    This->h.count = 0;
    InitHash(&This->h);
}
void Add(struct Map *This, int k, info v)
{
    ++This->h.count;
    AddHash(&This->h, k, v);
}
int Find(struct Map *This, int k)
{
    return FindHash(&This->h, k);
}

void Free(struct Map *This)
{
    FreeHash(&This->h);
}
info GetValue(struct Map *This, int k)
{
    return GetHashValue(&This->h, k);
}
int Count(struct Map *This)
{
    return This->h.count;
}
void Modify(struct Map *This,int k, info v)
{
    ModifyHash(&This->h, k, v);
}

