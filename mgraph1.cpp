#include<stdio.h>
typedef char VertexType;
typedef int EdgeType;
typedef int Boolean;
#define MAXVEX 100
#define INFINITY 65535
int visited[MAXVEX];

typedef struct
{
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes,numEdges;
} MGraph;

void CreateMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("输入顶点数和边数:\n");
	scanf("%d%d",&G->numVertexes,&G->numEdges);
	getchar();
	for(i=0;i<G->numVertexes;i++)
		scanf("%c",&G->vexs[i]);
	for(i=0;i<G->numVertexes ;i++)
		for(j=0;j<G->numVertexes ;j++)
		{
			G->arc[i][j]=INFINITY;
			if(i==j) G->arc[i][j]=0;
		}
	for(k=0;k<G->numEdges;k++)
	{
		printf("输入边(vi,vj)上的下标i，j和权值w：\n");
		scanf("%d%d%d",&i,&j,&w);
		G->arc[i][j]=G->arc[j][i]=w;
	}
}

void DFS(MGraph G,int i)
{
	int j;
	visited[i]=1;
	printf("%c",G.vexs[i]);
	for(j=0;j<G.numVertexes ;j++)
	{
		if(G.arc[i][j]<INFINITY&&!visited[j])
		{
			DFS(G,j);
		}
	}
}

void DFSTraverse(MGraph G)
{
	int i;
	for(i=0;i<G.numVertexes;i++)
		visited[i]=0;
	for(i=0;i<G.numVertexes;i++)
	{
		if(!visited[i]) DFS(G,i);
	}
}
//Prim算法生成最小生成树
void MiniSpanTree_Prim(MGraph G)
{
	int min,i,j,k;
	int adjvex[MAXVEX];
	int lowcost[MAXVEX];
	lowcost[0]=0;
	adjvex[0]=0;
	for(j=1;j<G.numVertexes ;j++)
	{
		adjvex[j]=0;
		lowcost[j]=G.arc[0][j];
	}
	for(i=1;i<G.numVertexes;i++)
	{
		min = INFINITY;
		j=1;k=0;
		while(j<G.numVertexes)
		{
			if(lowcost[j]!=0&&lowcost[j]<min)
			{
				min=lowcost[j];
				k=j;
			}
			j++;
		}
		
		printf("(%c,%c)",G.vexs[adjvex[k]],G.vexs[k]);
		lowcost[k]=0;
		for(j=1;j<G.numVertexes ;j++)
		{
			if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j])
			{
				lowcost[j]=G.arc[k][j];
				adjvex[j]=k;
			}
		}
	}
}
 
int main()
{
	MGraph G;
	CreateMGraph(&G);
	DFSTraverse(G);
	MiniSpanTree_Prim(G);
	return 0;
}

