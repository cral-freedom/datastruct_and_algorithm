#include "floyd_warshall.h"

//有向图
void init_Graph_FW(pG_FW *pG, int vexnum, int edgnum)
{
	int i,j;
	(*pG)->vexnum = vexnum;
	(*pG)->edgnum = edgnum;
	(*pG)->matrix = (int **)malloc(sizeof(int *)*vexnum);
	(*pG)->dis = (int **)malloc(sizeof(int *)*vexnum);
	(*pG)->path = (int **)malloc(sizeof(int *)*vexnum);
	//邻接矩阵初始化
	for(i=0; i<vexnum; i++)
	{
		(*pG)->matrix[i] = (int *)malloc(sizeof(int)*vexnum);
		(*pG)->dis[i] = (int *)malloc(sizeof(int)*vexnum);
		(*pG)->path[i] = (int *)malloc(sizeof(int)*vexnum);
		for(j=0; j<vexnum; j++)
		{
			if(i == j)
				(*pG)->matrix[i][j] = 0;
			else
				(*pG)->matrix[i][j] = INT_MAX;
		}
	}		
}

void print_matrix(int** matrix,int len, char ch)
{
	int row,col;
	if(ch == 'm')
		printf("the matrix:\n");
	else if(ch == 'd')
		printf("dist matrix:\n");
	for(row=0; row<len; row++)
	{
		for(col=0; col<len; col++)
		{
			if(matrix[row][col] != MAX_INT)
				printf("%d   ",matrix[row][col]);
			else	
				printf("INF   ");
		}
		printf("\n");
	}
}

void print_path(pG_FW pG)
{
	int i, j, k;
	printf("the shortest way of vertexs:\n");
	for(i=0; i<pG->vexnum; i++){
		for(j=0; j<pG->vexnum; j++){
			if(i == j)	
				continue;
			//打印路径信息
			printf("path: v%d",i+1);
			k = pG->path[i][j];
			while(k != j)
			{
				printf("-->v%d",k+1);
				k = pG->path[k][j];
			}
			printf("-->v%d : %d\n",j+1, pG->dis[i][j]);
		}
	}
}


void creat_Graph_FW(pG_FW *pG)
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
		if(KIND == 2)//如果是无向图
			(*pG)->matrix[end-1][start-1] = weight;
		edgenum++;
	}
}

void Floyd_Washall(pG_FW *pG)
{
	int i, j, k;
	int vexnum = (*pG)->vexnum;	

	//D矩阵和P矩阵初始化
	for(i=0; i<vexnum; i++)
	{
		for(j=0; j<vexnum; j++)
		{
			(*pG)->dis[i][j] = (*pG)->matrix[i][j];
			(*pG)->path[i][j] = j;//各边的终点的下标
		}
	}

	for(k=0; k<vexnum; k++){
		for(i=0; i<vexnum; i++){
			for(j=0; j<vexnum; j++){
				if(	(*pG)->dis[i][k] != MAX_INT && (*pG)->dis[k][j] != MAX_INT
					&& (*pG)->dis[i][j] > (*pG)->dis[i][k] + (*pG)->dis[k][j] )
				{
					(*pG)->dis[i][j] = (*pG)->dis[i][k] + (*pG)->dis[k][j];
					(*pG)->path[i][j] = (*pG)->path[i][k];
				}
			}
		}
	}
}

