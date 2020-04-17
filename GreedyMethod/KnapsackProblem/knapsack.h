#ifndef _KNAPSACK_H
#define _KNAPSACK_H

#include "stdio.h"

#define ObjN 7	//设置目标个数
#define MaxWeight 15	//设置背包承重
typedef struct _obj	
{
	int weight;//重量
	int profit;//利润
	float pw_rate; //收益率
}Obj,*pObj;
//这里的目标不是单一的整体（可分割的）
//单一的整体：洗衣机、电脑；集合：可称重卖的商品，如白糖，花生油

typedef struct _pack
{
	int capicity;	//总容量
	int weight_sum;		//已放入的重量
	float profit_sum;		//已有收益

	pObj pObjs;		//目标物品
	int obj_num;		//物品个数
}*pSack;

int init_Objs(pObj *objs, int n);
void init_sack(pSack *S, int objn);
void print_sack(pSack S);
void SnapSack(pSack S);
#endif

