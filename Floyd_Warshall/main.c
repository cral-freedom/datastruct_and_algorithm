#include "floyd_warshall.h"

void main()
{
	int vexnum,edgnum;
	pG_FW pG;
	printf("input the vexnum and edgnum:");
	scanf("%d%d",&vexnum,&edgnum);
	init_Graph_FW(&pG,vexnum,edgnum);
	creat_Graph_FW(&pG);
	print_matrix(pG->matrix,vexnum,'m');//打印原邻接矩阵
	Floyd_Washall(&pG);
	print_path(pG);
	print_matrix(pG->dis,vexnum,'d');//打印最短距离
}