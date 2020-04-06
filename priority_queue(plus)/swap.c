#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 30

typedef struct _stu elemtype; 
struct _stu
{
	char *name;
	int prio;
}stu;

typedef struct _heap
{
	int capcity;
	int size;
	struct _stu* pStu;
}*prioQueue;

void swap(elemtype *p1, elemtype *p2)
{
	elemtype tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


void main() 
{
	prioQueue pQ = (prioQueue)malloc(sizeof(prioQueue));
	pQ->capcity = MAXSIZE;
	pQ->size = 0;
	pQ->pStu = (struct _stu*)malloc(sizeof(stu)*(MAXSIZE+1));

	pQ->pStu[0].name = "zhou";
	pQ->pStu[0].prio = 1;
	pQ->pStu[1].name = "wang";
	pQ->pStu[1].prio = 2;

	swap(&(pQ->pStu[0]),&(pQ->pStu[1]));
	printf("pQ->pStu[0].name:%s\tpQ->pStu[0].prio:%d\n",pQ->pStu[0].name,pQ->pStu[0].prio);

}
