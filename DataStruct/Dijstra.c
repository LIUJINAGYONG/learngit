

/*
算法解决目标：
	Dijkstra算法的思想来看，他能够在一个有权值的网图中寻找一条从开始顶点出发访问
	网图中其余所有顶点的最短路径。从整体来看该路径保证了该网图中所有顶点均被访问且路径的
	权值和最小，从局部来看，除了开始顶点之外，其余每一个顶点到开始顶点的路径也是最短路径，
	也就是说任意一个顶点到开始顶点的路径权值和也是最小的.
	总体来说就是该算法既能保证整体的路径最短，也能保证局部的路径最短。

算法思想：
	依次找出离顶点路径最短的点，每找到一个点之后对该点进行标记，并记录与顶点
	的最短距离，从此以后找下一个点与顶点最短路径时对该点不再进行选择，再找下
	一个点时
	以先局部找出任意一点到顶点的最短路径，再整体找出最短路径
实现步骤：
	(1)根据算法思想需要用三个一维数组来来分别保存已经标记的顶点、存储最短路径的权值、存储最短路径顶点的下标,并且初始化所有顶点
	(2)
	(3)

*/

#define MAXVEX  9
#define INFINITY 65535

typedef int MixPath[MAXVEX]; //存储最短路径的下标
typedef int ShortPathTable[MAXVEX];//存储最短路径的权值和

void Dijkstra(MGrapph G ,int v0,int* p,int* D)
{
	/*初始化*/
	int flag[MAXVEX];
	int min;
	for (int v = 0; v < G.numVertexes; ++v)
	{
		/* code */
		flag[v] = 0;
		D[v] = G.mat[v0][v];
		p[v] = 0;
	}
	p[v0] = 0;
	D[v0] = 0;
	//min = D[v0];
	flag[v0] = 1;//标记最短路径顶点的下标

	for (int i = 1; i < G.numVertexes ; ++i)
	{
		min = INFINITY;
		for (int w = 0; w < G.numVertexes; w++)
		{
			if (!flag[w] && G.mat[i][w] < INFINITY)
			{
				D[w] = G.mat[i][w];
				p[w]
			}

			for ( int k = 0; k < ; k++)
			{
				if (G.mat[v0][k] < min + G.mat[v])
				{
					/* code */
				}
				
			}
			
			
		}
		
	}
}


