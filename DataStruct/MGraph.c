/**************** */
/*    邻接矩阵     */
/*************** **/
typedef char VertexType;
typedef int  EdgeType;
#define MAXSIZE 100
#define INFINITY 6666666666

typedef struct MGraph
{
    VertexType vexs[MAXSIZE];
    EdgeType   arc[MAXSIZE][MAXSIZE];
    int numVertexes,numEdges;
}MGraph;

/*建立无向图的邻接矩阵 */ 
// 时间复杂度 O(n*n)

void CreateMGraph(MGraph *G)
{
    int i,j,k,w;
    printf("请输入顶点数与变数");
    scanf("%v %e",&G->numVertexes,&G->numEdges)
    for (  i = 0; i < (G->numVertexes); i++)
    {
        scanf(&(G->vexs[i]));
    }

     for (  i = 0; i < (G->numVertexes); i++)
     {
        for ( j = 0; j < (G->numVertexes); j++)
            {
                G->arc[i][j] = INFINITY;
            }
     }
    for ( k = 0; i < G->numEdges; k++)
    {
        printf("输入边的下标i和j和权值");
        scanf(i,j,w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];//无向图，矩阵对称
    }
    
    

}


void DFS(MGraph G,int i )
{   

    int j;
    int visited[i] = 1;
    printf("%c\n",G.vexs[i]);
    for (int j = 0; i < numEdges; ++j)
    {
        /* code */
        if (arc[i][j] == 1 && visited[j] == 0 )
        {
            DFS(G,j)
        }
    }
}

void DFSTraverse(MGraph G) //深度遍历
{
    int i;
    for ( i = 0; i < G.numVertexes; ++i)//初始化顶点为未访问状态
    {
        /* code */
        visited[i] = -1;
    }

    for ( i = 0; i < G.numVertexes; ++i)
    {
        /* code */
        if (visited[i] == -1)
        {
            DFS(G,i);
        }
    }
}


/**************** */
/*    邻接表     */
/*************** **/

typedef struct EdgeNode  //边表节点
{
    int adjvex;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode  //顶点表节点
{
    VertexType data;
    EdgeNode *firstedge;
}VertexNode;

typedef struct MGraphAdjList  //邻接矩阵定义
{
    VertexNode AdjList[MAXSIZE];
    int numVertexes;
    int numEdges;
}MGraphAdjList;

/*建立邻接表*/

void CreateMGraphAdjList(MGraphAdjList *G)
{
   int i,j;
   EdgeNode* e = NULL;
    scanf("%d %d",&G->numVertexes,&G->numEdges); //输入顶点数与变边

    for (int i = 0; i < G->numVertexes; ++i)  //建立顶点表
    {
        scanf(&G->AdjList[i].data);
        G->AdjList[i].firstedge = NULL;
    }

    for (int k = 0; k < G->numEdges; ++k)
    {   
        scanf("%d %d",i,j);//输入下标值

        /* code */
         e = (EdgeNode*)mallloc(sizeof(EdgeNode));//动态分配一个边表节点

         e->adjvex = j;
         e->next = G->AdjList[i].firstedge;
         G->AdjList[i].firstedge = e;
         
         e = (EdgeNode*)mallloc(sizeof(EdgeNode));
         e->adjvex = i;
         e->next = G->AdjList[j].firstedge;
         G->AdjList[j].firstedge = e;

    }
    
}

void DFS(MGraphAdjList *G,int i) //时间复杂度 O(n+e) 适合稀疏矩阵
{   
    EdgeNode *p = NULL;
    visited[i] = 1;
    printf("%s\n",G->AdjList[i].data);

    p = G->AdjList[i].firstedge;

    while(p != NULL)
    {   if (visited[p->adjvex] != 1)
        {
            DFS(G,p->adjvex);
        }
        p = p->next;
    }
}

void DFSTraverse(MGraphAdjList *G)
{   
    int i;
    for ( i = 0; i < G->numVertexes; ++i)
    {
        /* code */
        visited[i] = -1;
    }
    for ( i = 0; i < G->numVertexes; ++i)
    {
        if (visited[i] = -1)
        {
        /* code */
        DFS(G,i)
        }
    }
    
}