
typedef int ElemType;
typedef struct BiTreeNode
{
	ElemType data;
	struct BiTreeNode*  Lchild;
	struct BiTreeNode*  Rchild;
}BiTreeNode,*BiTree;

//先序遍历
void PreOrder(BiTree T)
{
	if (T == NULL)
	{
		/* code */
		return -1;

	}
	PreOrder(T);
	PreOrder(T->Lchild);
	PreOrder(T->Rchild);
}


void MidOrder(BiTree T)
{
	if (T == NULL)
	{
		/* code */
		return -1;
	}
	PreOrder(T->Lchild);
	PreOrder(T);
	PreOrder(T->Rchild);
}

void LatOrder(BiTree T)
{
	if (T == NULL)
	{
		/* code */
		return -1;
	}
	PreOrder(T->Lchild);
	PreOrder(T->Rchild);
	PreOrder(T);	
}