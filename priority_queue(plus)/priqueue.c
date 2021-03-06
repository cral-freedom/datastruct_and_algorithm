#include "priqueue.h"

// priority queue implemented by max_heap
void pQ_init(pQueue *pQ)
{
	*pQ = (pQueue)malloc(sizeof(pQueue));
	if(*pQ)
	{
		(*pQ)->pItem = (Item *)malloc(sizeof(Item)*(MAXSIZE+1));
		if((*pQ)->pItem)
		{
			(*pQ)->capcity = MAXSIZE;
			memset((*pQ)->pItem,-1,sizeof(Item)*(MAXSIZE+1));
			(*pQ)->size = 0;
			printf("init success\n");
		}
	}
}

void pQ_print(pQueue Q)
{
	int i;
	printf("Q->size:%d\n",Q->size);
	for(i=1; i<=Q->size; i++)
		printf("(%s,%d) ",Q->pItem[i].name,Q->pItem[i].prio);
	printf("\n");
}

typedef Item swaptype;
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
void DeQueue(pQueue *pQ, Item *item)
{
	int i,j;
	if(!is_empty(*pQ))
	{
		*item = (*pQ)->pItem[1];

		//调整位置
		(*pQ)->pItem[1] = (*pQ)->pItem[(*pQ)->size]; //最后一个调到前面
		memset(&(*pQ)->pItem[(*pQ)->size],-1,sizeof(Item));//最后项的位置清空

		i = 1,j=1;
		while((*pQ)->pItem[i*2+1].prio != -1)
		{
			if((*pQ)->pItem[i*2].prio >= (*pQ)->pItem[i*2+1].prio)
				j = i*2;
			else  
				j = i*2 + 1;

			swap(&((*pQ)->pItem[j]),&((*pQ)->pItem[i]));
			i = j; 		
		}

		(*pQ)->size--;
	}
}

void EnQueue(pQueue *pQ, Item item)
{
	int i,tmp;
	if(!is_full(*pQ))
	{	
		(*pQ)->size++;	
		memcpy(&(*pQ)->pItem[(*pQ)->size],&item,sizeof(Item));

		i = (*pQ)->size;
		while(i>=2 && (*pQ)->pItem[i].prio > (*pQ)->pItem[i/2].prio ) //新添项的优先级比父节点要大
		{
			// 调整位置
			swap(&((*pQ)->pItem[i]),&((*pQ)->pItem[i/2]));
			i /= 2;
		}
	}
}

void exam_queue(pQueue *pQ)
{
	Item a[] = {{"zhou",1},{"wang",4},{"li",3}};
	int i,len = sizeof(a)/sizeof(a[0]);
	printf("len:%d\n",len);
	pQ_init(pQ);
	for(i=0; i<len; i++)
		EnQueue(pQ,a[i]);
}

