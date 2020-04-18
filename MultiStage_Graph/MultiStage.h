#ifndef _MULTISTAGE_H
#define _MULTISTAGE_H
#pragma once
#define INF 0x7fffffff

#include "stdio.h"
#include "stdlib.h"
typedef struct _vermsg
{
	int cost;	//当前顶点到终点的最短距离
	int next;	//最佳路径情况下，当前顶点的下一个点
}VerMsg;

typedef struct _mStage_graph
{
	int vexnum;
	int edgnum;
	int **matrix;
	VerMsg *vmsg;
}*pG_MS;

void init_Graph_MS(pG_MS *pG, int vexnum, int edgnum);
void print_matrix(pG_MS pG);
void print_path(pG_MS pG, int end);
void creat_Graph_MS(pG_MS *pG);
void ms_graph(pG_MS *pG,int end);

#endif // !