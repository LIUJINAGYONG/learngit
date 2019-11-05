/********
循环队列
/*******/
##ifndef MaxSize
#define MaxSize 10
#endif
typedef int ElemType;

typedef struct Queue
{
	ElemType data[MaxSize];
	int front;
	int rear;
}Queue;

//初始化队列

int InitQueue(Queue *Q)
{
	Q->front = 0;
	Q->rear = 0;

	return 1;
}

//当前队列的长度

int QueueLength(Queue *Q)
{
	return (Q->rear - Q->front + MaxSize)%MaxSize;
}


int QueueLength(Queue Q)
{
	return (Q.rear - Q.front + MaxSize)%MaxSize;
}

///入队

int InsertQueue(Queue *Q,ElemType x)
{
	if ((Q->rear + 1)%MaxSize == Q->front)
	{
		/* code */
		return 0;
	}

	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1)%MaxSize; //rear 指针向后移动一位；

	return 1;

}

//出队
int DeleteQueue(Queue *Q,ElemType &x)
{
	if ((Q->rear == Q->front)
	{
		/* code */
		return 0;
	}

	x = Q->data[Q->front];
	Q->front = (Q->front + 1)%MaxSize; // front指针向后移动一位；

	return 1;
｝


//链式队列 时间复杂度 ：O(1)

typedef struct QNode
{
	ElemType data;
	struct QNode *next;
	
}QNode,*QNodeptr;

typedef struct LinkQueu
{

	QNodeptr front;
	QNodeptr rear;

}LinkQueu,*LinkQueu;

//入队
LinkQueu InLinkQueu(LinkQueu Q,ElemType x)
{	
	QNodeptr s = (QNodeptr)malloc(sizeof(QNode));
	if (s ==NULL)
	{
		/* code */
		return  NULL;
		exit(1);
	}

	s->data = x;
	s->next = NULL;
Q->rear->next = s;
Q->rear = s;
    return Q;
}

//出队
LinkQueu DeleteQueue(LinkQueu Q,ElemType &x)
{	
	QNodeptr p;
	p = Q->front->next;
	if (Q->rear == Q->front)
	{
		/* code */
		return NULL;
		exit(1);
	}
	x = p->data;
	Q->front->next = p->next;
	if (p == Q->rear)
	{
		Q->rear = Q->front;
	}
	free(p);

	return Q;
}



//队列避免数组茶如何删除数据时移动数据