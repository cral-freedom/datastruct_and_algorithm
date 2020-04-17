#include "dijkstra.h"

//有向图
void init_Graph_Dj(pG_DJ *pG, int vexnum, int edgnum)
{
	int i,j;
	(*pG)->vexnum = vexnum;
	(*pG)->edgnum = edgnum;
	(*pG)->matrix = (int **)malloc(sizeof(int *)*vexnum);
	(*pG)->dis = (Dis *)malloc(sizeof(Dis)*vexnum);
	//邻接矩阵初始化
	for(i=0; i<vexnum; i++)
	{
		(*pG)->matrix[i] = (int *)malloc(sizeof(int)*vexnum);
		for(j=0; j<vexnum; j++)
		{
			if(i == j)
				(*pG)->matrix[i][j] = 0;
			else
				(*pG)->matrix[i][j] = INT_MAX;
		}
	}
	//最短路径信息初始化
	for(i=0; i<vexnum; i++)
	{
		(*pG)->dis[i].visit = 0;
		(*pG)->dis[i].value = 0;
	}
}

void print_matrix(pG_DJ pG)
{
	int row,col;
	int vnum = pG->vexnum;
	printf("the matrix:\n");
	for(row=0; row<vnum; row++)
	{
		for(col=0; col<vnum; col++)
		{
			if(pG->matrix[row][col] != MAX_INT)
				printf("%d   ",pG->matrix[row][col]);
			else	
				printf("INF   ");
		}
		printf("\n");
	}
}

void print_path(pG_DJ pG, int begin)
{
	int i;
	char buff[50];
	printf("the shortest path while v%d is the begin\n",begin);
	for(i=0; i<pG->vexnum; i++)
	{
		if(pG->dis[i].value != INT_MAX)
			printf("%s = %d\n",pG->dis[i].path,pG->dis[i].value);
		else
			printf("%s is none\n",pG->dis[i].path);
	}
}

void creat_Graph_Dj(pG_DJ *pG)
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

void Dijkstra(pG_DJ *pG,int begin)
{
	int i,visit_count=0;//已计算完成的点的个数
	int tmp,min;//tmp保存当前dis数组中value最小的点的下标
	char buff[50]="";

	//先选中起点
	(*pG)->dis[begin-1].visit = 1;
	visit_count++; 
	for(i=0; i<(*pG)->vexnum; i++)
	{
		(*pG)->dis[i].value = (*pG)->matrix[begin-1][i];
		sprintf((*pG)->dis[i].path,"v%d-->v%d",begin,i+1);
	}

	//计算起点到其它所有顶点的最短路径
	//更新和记录dis[i]中的visit和value信息
	while(visit_count != (*pG)->vexnum)
	{
		tmp = 0;min = INT_MAX;

		//在所有unvisit的顶点中找出最小的value，并记下其对应的下标
		for(i=0; i<(*pG)->vexnum; i++)
		{
			if(!((*pG)->dis[i].visit) && (*pG)->dis[i].value < min)
			{
				min = (*pG)->dis[i].value;
				tmp = i;
			}
		}//每经过一次循环，在unvisit中选中一个点


		(*pG)->dis[tmp].visit = 1;//选中tmp对应的顶点
		visit_count++;
		//更新剩下的顶点的路径信息
		for(i=0; i<(*pG)->vexnum; i++)
		{
			if(!((*pG)->dis[i].visit) && (*pG)->matrix[tmp][i]!=INT_MAX 
			&& ((*pG)->dis[tmp].value + (*pG)->matrix[tmp][i] < (*pG)->dis[i].value))
			{
				(*pG)->dis[i].value = (*pG)->dis[tmp].value + (*pG)->matrix[tmp][i];
				sprintf(buff,"%s-->v%d",(*pG)->dis[tmp].path,i+1);
				strcpy((*pG)->dis[i].path,buff);
			}
		}
	}		
}

