#ifndef _PRIQUEUE_H
#define _PRIQUEUE_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAXSIZE 30

typedef struct _item
{
	char name[10];	//数据部分
	int prio;	//优先级	
}Item;

typedef struct _heap
{
	int capcity;
	int size;
	Item *pItem;	//piro[0]空着，下标从1开始
}*pQueue;


void pQ_init(pQueue *pQ);
void pQ_print(pQueue Q);
int is_empty(pQueue Q);
int is_full(pQueue Q);
void EnQueue(pQueue *pQ, Item item);
void DeQueue(pQueue *pQ, Item *item);
void exam_queue(pQueue *pQ);


#endif