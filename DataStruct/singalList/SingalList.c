typedef int DataType;
typedef struct SLNode
{
    DataType data;
    struct SLNode* next;
}SLNode,*SignedList;

void SignedListCreatHead(SignedList &L,DataType a[],int length) //头插法
{
    SignedList s;
    L = (SLNode*)malloc(sizeof(SLNode));
    L->next = NULL;

    int i;
    
    for ( i = 0; i < length; i++)
    {   s = (SLNode*)malloc(sizeof(SLNode));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
    
}
void SignedListCreatHead(SignedList &L,DataType a[],int length) //尾插法
{
    SignedList r,s;
    L = (SLNode*)malloc(sizeof(SLNode));
    L->next = NULL;
    r = L;
    int i;
    for (int i = 0; i < length; i++)
    {
        s = (SLNode*)malloc(sizeof(SLNode));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
    
}

void LinklistInit(SignedList &L)
{
    L = (SLNode *)malloc(sizeof(SLNode));
    L->next = NULL;
}

void DestroyLinklist(SignedList &L) //销毁链表
{
    if (L == NULL)
    {
        return ;
    }
    SignedList pre,s;
    pre = L; s = L->next;
    while (s != NULL)
    {   //s = pre->next;
        //pre = pre->next->next;
        pre = s;
        s = s->next;
        free(pre);
    }
    
    
}