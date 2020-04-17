#ifndef _QUICKSORT_H
#define _QUICKSORT_H

#include "knapsack.h"
typedef Obj elemtype;
void swap(elemtype *p1, elemtype *p2);
int partition(elemtype arr[], int l, int h);
void quick_sort(elemtype arr[], int l, int h);

#endif // !_QUICKSORT_H
