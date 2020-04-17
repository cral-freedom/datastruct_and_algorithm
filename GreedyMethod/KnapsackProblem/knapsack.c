#include "knapsack.h"
#include "stdlib.h"

int init_Objs(pObj *objs, int n)
{
	int i,w=0,p=0;
	float rate;
	*objs = (Obj *)malloc(sizeof(Obj)*n);
	if(*objs)
	{
		printf("enter each obj's weight and profit:\n");
		for(i=0; i<n; i++)
		{
			printf("obj[%d]'s weight and profit:",i);	
			scanf("%d%d",&w,&p);
			(*objs)[i].weight = w;
			(*objs)[i].profit = p;
			(*objs)[i].pw_rate = (float)p/w;
		}
		return 0;
	}
	return -1;
}

void init_sack(pSack *S, int objn) 
{
	int i;
	*S = (pSack)malloc(sizeof(pSack));
	if(*S)
	{	
		if(init_Objs(&((*S)->pObjs), objn) == 0)
		{
			(*S)->capicity = MaxWeight;
			(*S)->weight_sum = 0;
			(*S)->profit_sum = 0;	
			(*S)->obj_num = objn;
			printf("sack init success\n");
		}
	}
}

void print_sack(pSack S)
{
	int i,objn = S->obj_num;
	printf("weight_sum:%d\tprofit_sum:%d\tcapcity:%d\tobj_num:%d\n",S->weight_sum,S->profit_sum,S->capicity,S->obj_num);
	for(i=0; i<objn; i++)
		printf("S->pObjs[%d]	weight:%d\tprofit:%d\tpw_rate:%f\n"
		,i,S->pObjs[i].weight,S->pObjs[i].profit,S->pObjs[i].pw_rate);

}

void SnapSack(pSack S)
{
	int i = 0;
	while( S->capicity - S->weight_sum > S->pObjs[i].weight)
	{
		S->profit_sum += S->pObjs[i].profit;
		S->weight_sum += S->pObjs[i].weight;
		i++;
	}
	if(S->weight_sum < S->capicity)
	{
		S->profit_sum += S->pObjs[i].pw_rate * (S->capicity - S->weight_sum);
		S->weight_sum = S->capicity;
	}
}