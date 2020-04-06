#ifndef _PRIQUEUE_H
#define _PRIQUEUE_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAXSIZE 30

// typedef struct _item
// {
// 	char *data;	//数据
// 	int prio;	//优先级	
// }Item;
typedef struct _heap
{
	int capcity;
	int size;
	int *piro;	//piro[0]存放个数，下标从1开始
}*pQueue;


void pQ_init(pQueue *pQ);
void pQ_print(pQueue Q);
int is_empty(pQueue Q);
int is_full(pQueue Q);
void EnQueue(pQueue *pQ, int elem);
void DeQueue(pQueue *pQ, int *elem);
void exam_queue(pQueue *pQ);


#endif