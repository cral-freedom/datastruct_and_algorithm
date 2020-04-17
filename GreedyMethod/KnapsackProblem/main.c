#include "knapsack.h"
#include "quicksort.h"
void main()
{
	pSack S;
	init_sack(&S,ObjN);
	quick_sort(S->pObjs,0,ObjN-1);
	print_sack(S);

	SnapSack(S);
	printf("max_profit:%f\n",S->profit_sum);		
}