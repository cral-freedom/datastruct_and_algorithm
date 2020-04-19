#ifndef _FLOYD_WARSHALL_H
#define _FLOYD_WARSHALL_H
#pragma once //保证头文件只被编译一次

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define MAX_INT 0x7fffffff
#define KIND 1 //1为有向图，2为无向图

typedef struct _graph_fw
{
	int vexnum;
	int edgnum;
	int **matrix;//邻接矩阵
	int **dis;//任意两顶点间的最短路径权值和 
	int **path;//记录各最短路径的信息
}*pG_FW;

void init_Graph_FW(pG_FW *pG, int vexnum, int edgnum);
void print_matrix(int** matrix,int len, char ch);
void print_path(pG_FW pG);
void creat_Graph_FW(pG_FW *pG);
void Floyd_Washall(pG_FW *pG);

#endif