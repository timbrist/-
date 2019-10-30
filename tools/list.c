//====================list.c============
#include"list.h"
//===================================linklist=========================================
void InitLinkList(linknode *list)
{
    if (list == NULL) return;
    //TODO:自定义数据结构初始化--------
    list->value.id = NULLVALUE;
    list->value.total = NULLVALUE;    
    //-----------------------------
    list->next = NULL;
}
void AddNode(linknode *list, Value v)
{
    linknode *head = list;
    if (head->value.id == NULLVALUE && head->value.total == NULLVALUE)
    {
        head->value = v;
        head->next = NULL;
    }
    else
    {
        linknode *newnode = (linknode *)malloc(sizeof(linknode));
        newnode->next = NULL;
        newnode->value = v;
        while (head->next != NULL)
            head = head->next;
        head->next = newnode;
    }
}
void InsertNode(linknode *list, Value v, int i)
{
    int j = 1;
    linknode *head = list;
    while (head != NULL && j < i)
    {
        head = head->next;
        ++j;
    }
    if (head == NULL || j > i)
        return;
    linknode *newnode = (linknode *)malloc(sizeof(linknode));
    newnode->value = v;
    newnode->next = head->next;
    head->next = newnode;
}
int CountList(linknode *list)
{
    linknode *head = list;
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        ++count;
    }
    return count;
}
int Partition(Value *a, int low, int high, int pivotkey)
{
    while (low < high)
    {
        while (low < high && a[high].total <= pivotkey)
            high--;
        Value tmp = a[high]; a[high] = a[low]; a[low] = tmp;
        while (low < high && a[low].total >= pivotkey)
            low++;
        tmp = a[high]; a[high] = a[low]; a[low] = tmp;
    }
    return low;
}
void QSort(Value *a, int low, int high)
{
    if (low > high) return;
    int pivot = low;
    int pivotkey = a[low].total;
    pivot = Partition(a, low, high, pivotkey);
    QSort(a, low, pivot - 1);
    QSort(a, pivot + 1, high);
}
void SortList(linknode *list)
{
    int size = CountList(list);
    Value *arr = (Value *)malloc(size * sizeof(Value));
    int i = 0;
    linknode *head = list;
    while (head != NULL)
    {
        arr[i] = head->value;
        head = head->next;
        ++i;
    }
    QSort(arr, 0, size - 1);
    linknode *head2 = list;
    i = 0;
    while (head2 != NULL)
    {
        head2->value = arr[i];
        head2 = head2->next;
        ++i;
    }
    free(arr);
}
void PrintList(linknode *list)
{
    linknode * head = list;
    while (head != NULL)
    {
        //修改需要显示排序的内容
        printf("学号:%d\t", head->value.num);
        printf("姓名:%s\t", head->value.name);
        printf("选修课:%d\t", head->value.elective);
        printf("实验课:%d\t", head->value.experiment);
        printf("必修课:%d\t", head->value.required);
        printf("总分:%d\n", head->value.total);
        
        head = head->next;
    }
}
linknode *FindPrevious(linknode *list, Value v)// 复用需要修改 Value v 需要匹配的值
{
    linknode * p = list;
    //while(p->next != NULL && p->next->value.id != v.id) //多加一个分号 我晕了:w
    while(p->next != NULL && p->next->value.num != v.num) //根据需要操作的key修改
        p = p->next;
    return p;
}
void DeleteNode(linknode *node, Value v)
{
    linknode *p = FindPrevious(node, v);
    linknode *tmp;
    if(p->next != NULL)
    {
        tmp = p->next;
        p->next = tmp->next;
        free(tmp);
    }
}

void DeleteList(linknode *list, int position)
{
    int j = 1;
    linknode *head = list;
    linknode *p;
    while(head->next != NULL && j < position)
    {
        head = head->next;
        ++j;
    }
    if(head->next == NULL || j > position)
        return;
    p = head->next;
    head->next = p->next;
    free(p);
}
void DeleteListValue(linknode *list, int onlykey)
{
    linknode * p = list;  
    while(p->next != NULL && p->next->value.num != onlykey) //根据需要操作的key修改
        p = p->next;
    
    linknode *tmp;
    if(p->next != NULL)
    {
        tmp = p->next;
        p->next = tmp->next;
        free(tmp);
    }
}
void ModifyList(linknode *list, Value oldValue, Value newValue)
{
    linknode * head = list;
    while(head != NULL)
    {
       //if(head->value.id == oldValue.id)
       if(head->value.num == oldValue.num)//根据需要操作的key来修改
       {
           head->value = newValue;
       }
       head = head->next;
    }
}
linknode  *FindNode(linknode *list, Value v)
{
    linknode *head = list;
    //while(head != NULL && head->value.id != v.id)
    while(head != NULL && head->value.num != v.num)//根据需要操作的key来修改
        head = head->next;
    return head;      
}
void ModifyListValue(linknode *list, int onlykey, Value newv)
{

    linknode * head = list;
    while(head != NULL)
    {
       //if(head->value.id == oldValue.id)
       if(head->value.num == onlykey)//根据需要操作的key来修改
       {
           head->value = newv;
       }
       head = head->next;
    }
}

Value GetListValue(linknode *list, int onlykey)
{
    linknode *head = list;
    //while(head != NULL && head->value.id != v.id)
    while(head != NULL && head->value.num != onlykey)//根据需要操作的key来修改
        head = head->next;
    return head->value;
}

void FreeList(linknode *list)
{
    linknode *position = list->next;
    linknode *tmp;
    list->next = NULL;
    while (position != NULL)
    {
        tmp = position->next;
        free(position);
        position = tmp;
    }
}
//=====================list========================
void InitList(list *This)
{
    This->Add = Add;
    This->Insert = Insert;
    This->Count = Count;
    This->Sort = Sort;
    This->Print = Print;
    This->Free = Free;
    This->Delete = Delete;
    This->Delete2 = Delete2;
    This->DeleteValue = DeleteValue;
    This->Modify = Modify;
    This->Modify2 = Modify2;
    This->GetValue = GetValue;
    This->l.value.id = NULLVALUE;
    This->l.value.total = NULLVALUE;
}
void Add(struct List*This, Value v)
{
    AddNode(&This->l, v);
}
void Insert(struct List*This, Value v, int position)
{
    InsertNode(&This->l, v, position);
}
int Count(struct List*This)
{
    return CountList(&This->l);
}
void Sort(struct List*This)
{
    SortList(&This->l);
}
void Print(struct List*This)
{
    PrintList(&This->l);
}
void Free(struct List*This)
{
    FreeList(&This->l);
}

void Delete(struct List *This, int position)
{
    DeleteList(&This->l, position);
}
void Delete2(struct List *This, Value v)
{
    DeleteNode(&This->l, v);
}
void DeleteValue(struct List *This, int onlykey)
{
    DeleteListValue(&This->l, onlykey);
}
void Modify2(struct List *This, Value oldValue, Value newValue)
{
    ModifyList(&This->l,oldValue, newValue);
}
Value GetValue(struct List *This, int onlykey)
{
    return GetListValue(&This->l, onlykey);
}
void Modify(struct List *This, int onlykey ,Value newv)
{
    ModifyListValue(&This->l,onlykey, newv);
}

