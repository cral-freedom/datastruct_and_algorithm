#ifndef _DIJKSTRA_H
#define _DIJKSTRA_H
#pragma once //保证头文件只被编译一次

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define MAX_INT 0x7fffffff

//记录起点到每个顶点的最短路径的信息
typedef struct _dis
{
	char path[50];
	int value;
	int visit;
}Dis;

typedef struct _graph_dj
{
	int vexnum;
	int edgnum;
	int **matrix;
	Dis *dis;
}*pG_DJ;

void init_Graph_Dj(pG_DJ *pG, int vexnum, int edgnum);
void print_matrix(pG_DJ pG);
void print_path(pG_DJ pG, int begin);
void creat_Graph_Dj(pG_DJ *pG);
void Dijkstra(pG_DJ *pG,int begin);

#endif