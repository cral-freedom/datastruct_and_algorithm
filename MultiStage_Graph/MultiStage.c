#include "MultiStage.h"

void init_Graph_MS(pG_MS *pG, int vexnum, int edgnum)
{
	int i,j;
	(*pG)->vexnum = vexnum;
	(*pG)->edgnum = edgnum;
	(*pG)->matrix = (int **)malloc(sizeof(int *)*vexnum);
	(*pG)->vmsg = (VerMsg *)malloc(sizeof(VerMsg)*(vexnum+1));
	//邻接矩阵初始化
	for(i=0; i<vexnum; i++)
	{
		(*pG)->matrix[i] = (int *)malloc(sizeof(int)*vexnum);
		for(j=0; j<vexnum; j++)
		{
			if(i == j)
				(*pG)->matrix[i][j] = 0;
			else
				(*pG)->matrix[i][j] = INF;
		}
	}
	//
	for(i=1; i<=vexnum; i++) //顶点信息数组[1~vexnum]
	{
		(*pG)->vmsg[i].cost = 0;
		(*pG)->vmsg[i].next = 0;
	}
}

void print_matrix(pG_MS pG)
{
	int row,col;
	int vnum = pG->vexnum;
	printf("the matrix:\n");
	for(row=0; row<vnum; row++)
	{
		for(col=0; col<vnum; col++)
		{
			if(pG->matrix[row][col] != INF)
				printf("%d   ",pG->matrix[row][col]);
			else	
				printf("INF   ");
		}
		printf("\n");
	}
}

void print_path(pG_MS pG, int end)
{
	int i = 1;
	printf("the shortest route:v1-->");
	while(pG->vmsg[i].next != end)
	{
		printf("v%d-->",pG->vmsg[i].next);
		i = pG->vmsg[i].next;
	}
	printf("v%d = %d",end,pG->vmsg[1].cost);
}

void creat_Graph_MS(pG_MS *pG)
{
	int start,end,weight,edgenum;
	printf("input the start,end,and weight of each edges:\n");
	while(edgenum != (*pG)->edgnum)
	{
		scanf("%d%d%d",&start,&end,&weight);
		if(start<1 || end<1 || start>(*pG)->vexnum || end>(*pG)->vexnum || weight<0)
		{
			printf("the value is not legal, please input again\n");
			// scanf("%d%d%d",&start,&end,&weight);
			continue;
		}
		(*pG)->matrix[start-1][end-1] = weight;
		//如果是无向图，加上(*pG)->matrix[end-1][start-1] = weight;
		edgenum++;
	}
}

void ms_graph(pG_MS *pG,int end)
{
	int i,j,min;
	for(i=end-1; i>=1; i--)
	{
		min = INF;
		for(j=i+1; j<=end; j++)
		{
			if((*pG)->matrix[i-1][j-1]!=INF && 
			(*pG)->matrix[i-1][j-1] + (*pG)->vmsg[j].cost < min)
			{
				min = (*pG)->matrix[i-1][j-1] + (*pG)->vmsg[j].cost;
				(*pG)->vmsg[i].next = j;
			}
		}
		(*pG)->vmsg[i].cost = min;		
	}
}



