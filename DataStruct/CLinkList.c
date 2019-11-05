

typedef int ElemType;
typedef struct  Node
{
	ElemType data;
	struct Node *next
}Node,*LinkList;

/*循环链表的创建*/

LinkList CLinklistCreate()
{	ElemType x;
	Node *L;//创建头节点
	L  = (LinkList)malloc(sizeof(Node));
	if ( L == NULL)
	{
		printf("malloc space error!\n", );
		exit(0);
	}
	L->next = L;

	Node *rear;//尾指针
	rear = L;
	Node *p;//数据存放指针

	while(1)
	{
		scanf("%d",&x);

		p = (LinkList)malloc(sizeof(Node));

		if (p = NULL)
		{
			/* code */
			exit(0);

		}
		p->data = x;
		rear->next = p;
		rear = p;

		rear->next = L;

	}

	return L;

}

/*循环链表的插入*/
LinkList LinkListInsert(LinkList CL,int i,ElemType data)
{	int k = 0;
	Node *s;
	rear = CL;
	Node *p;
	if ( i <= 0 || p == CL)
	{
		/* code */
		printf("error\n");
	}
	while(p->next != CL && k <(i-1))
	{
		p = p->next;
		k++;
	}
	s = (LinkList)malloc(sizeof(Node));

	s->data = data;
	s->next = p->next;
	p->next = s;

	return CL;

}

/*循环链表的删除*/
LinkList LinkListDelete(LinkList CL,int i)
{

    Node *p;
    p=CL;
    Node *r;
    int k=0;
    if(i<0 || p->next==CL)
    {
        printf("You  i or Node illegal!\n");
        exit(0);
    }
    while(p->next!=CL && k<i-1)
    {
        p=p->next;
        k++;
    }
   
    r = p->next;
    p->next = r->next;
    free(r); 

    return CL;
}

/*合并循环链表*/

LinkList MergeCLLinkList(LinkList CL_a,LinkList CL_b)
{
    Node *p,*q;
    p=CL_a;
    q=CL_b;
    while(p->next!=CL_a)//找到LA的表尾，用p指向它 
        p=p->next;
    while(q->next!=CL_b)//找到LB的表尾，用q指向它
        q=q->next;
    q->next=CL_a;//修改LB的表尾指针，使之指向表LA的头结点 
    p->next=CL_b->next;    //修改LA的表尾指针，CL_b->next的意思是跳过CL_b头结点
    free(CL_b);
    return CL_a;
}




