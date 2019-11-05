//顺序栈定义 时间复杂度O(1)
typedef int SElemType;

typedef struct SqStack
{
	SElemType data[MAXSIZE];
	int top;
}SqStack;

top == -1;//空栈
top == MAXSIZE -1//满栈

//入栈
int push(SqStack *s,SElemType e)
{
	if (s->top == MAXSIZE-1)
	{
		return 0;
	}
	s->top++;
	s->data[s->top] = e;

	return 1;

}

//出栈
int pop(SqStack *s,SElemType &x)
{
	if (s->top == -1)
	{
		/* code */
		return 0;
	}
	x = s->data[s->top];
	s->top--;
	return 1;
}



//双端栈栈定义
typedef int SElemType;

typedef struct SqStack
{
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqdoubleStack;


int dbpush(SqdoubleStack *s, int stacknum,SElemType x)
{
	if (s->top1 + 1 == s->top2)
	{
		/* code */
		return 0;
	}
	if (stacknum == 1)
	{
		/* code */
		s->data[++s->top1] = x;
		return 1;
	}
	else if (stacknum == 2)
	{
		/* code */
		s->data[--s->top2] = x;
		return 1;
	}
	else
		return 0;
}

int dbpop(SqdoubleStack *s, int stacknum ,SElemType &x)
{
	if ( stacknum == 1)
	{
		/* code */
		if (s->top1 == -1)
		{
			/* code */
			return 0;
		}
		else
		{
			x = s->data[s->top1--];
		}
	}
	else if (stacknum == 2)
	{
		/* code */
		if (s->top2 == MAXSIZE-1)
		{
			/* code */
			return 0;
		}
		else
		{
			x = s->data[s->top2++] 
		}
	}
	return 1;
}



//链栈  时间复杂度O(1)
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
	
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
	int count; 
	LinkStackPtr top;
}LinkStack;

int push(LinkStack *s,SElemType x)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (p == NULL)
	{

		return -1;
	}
	p->data = x;
	p->next = s->top;

	s->top = p;
	s->count++;
	return 1;
}

int pop(LinkStack *s,SElemType &x)  
{	
	LinkStackPtr p; //p指针用来保存要删除的节点
	if (s->top == NULL)
	{
		/* code */
		return -1;
	}
	 x = s->top->data ;
	 p = s->top;
	 s->top = s->top->next;
	 free(p);
	 s->count--;

	 return 1;
}