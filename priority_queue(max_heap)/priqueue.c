#include "priqueue.h"

// priority queue implemented by max_heap
void pQ_init(pQueue *pQ)
{
	*pQ = (pQueue)malloc(sizeof(pQueue));
	if(*pQ)
	{
		(*pQ)->piro = (int *)malloc(sizeof(int)*(MAXSIZE+1));
		if((*pQ)->piro)
		{
			(*pQ)->capcity = MAXSIZE;
			memset((*pQ)->piro,-1,sizeof(int)*(MAXSIZE+1));
			(*pQ)->size = 0;
			printf("init success\n");
		}
	}
}

void pQ_print(pQueue Q)
{
	int i;
	printf("Q->size:%d\n",Q->size);
	for(i=1; i<=10; i++)
		printf("%d ",Q->piro[i]);
	printf("\n");
}

typedef int swaptype;
void swap(swaptype *p1, swaptype *p2)
{
	swaptype tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int is_empty(pQueue Q)
{
	return Q->size==0;
}
int is_full(pQueue Q)
{
	return Q->size==Q->capcity;
}
void DeQueue(pQueue *pQ, int *elem)
{
	int i,j;
	if(!is_empty(*pQ))
	{
		*elem = (*pQ)->piro[1];

		//调整位置
		(*pQ)->piro[1] = (*pQ)->piro[(*pQ)->size]; //最后一个调到前面
		(*pQ)->piro[(*pQ)->size] = -1;

		i = 1,j=1;
		while((*pQ)->piro[i*2+1] != -1)
		{
			if((*pQ)->piro[i*2] >= (*pQ)->piro[i*2+1])
				j = i*2;
			else  
				j = i*2 + 1;

			swap(&((*pQ)->piro[j]),&((*pQ)->piro[i]));
			i = j; 		
		}

		(*pQ)->size--;
	}
}

void EnQueue(pQueue *pQ, int elem)
{
	int i,tmp;
	if(!is_full(*pQ))
	{	
		(*pQ)->size++;	
		(*pQ)->piro[(*pQ)->size] = elem;

		i = (*pQ)->size;
		while(i>=2 && (*pQ)->piro[i] > (*pQ)->piro[i/2] ) //新添项的优先级比父节点要大
		{
			// 调整位置
			swap(&((*pQ)->piro[i]),&((*pQ)->piro[i/2]));
			i /= 2;
		}
	}
}

void exam_queue(pQueue *pQ)
{
	int a[] = {13,43,11,9,30,20};
	int i,len = sizeof(a)/sizeof(a[0]);
	pQ_init(pQ);
	for(i=0; i<len; i++)
		EnQueue(pQ,a[i]);
}

