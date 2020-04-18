#include "MultiStage.h"

void main()
{
	int vexnum,edgnum;
	pG_MS pG;
	printf("input vexnum and edgnum:");
	scanf("%d%d",&vexnum,&edgnum);
	init_Graph_MS(&pG,vexnum,edgnum);
	creat_Graph_MS(&pG);
	print_matrix(pG);
	ms_graph(&pG,vexnum);
	print_path(pG,vexnum);
}