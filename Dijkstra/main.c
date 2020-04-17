#include "dijkstra.h"

void main()
{
	int vexnum,edgnum;
	pG_DJ pG;
	printf("input the vexnum and edgnum:");
	scanf("%d%d",&vexnum,&edgnum);
	init_Graph_Dj(&pG,vexnum,edgnum);
	creat_Graph_Dj(&pG);
	print_matrix(pG);
	Dijkstra(&pG,1);
	print_path(pG,1);
}