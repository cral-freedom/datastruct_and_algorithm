#include "stdio.h"
#include "stdlib.h"
#include "string.h"
void swap(int *p1, int *p2)
{
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int partition(int arr[],int l, int h)
{
	int pivot = arr[l];
	int i = l, j = h;
	// printf("%d ",arr[h]);
	while(i < j)
	{
		do{
			i++;
		}while(arr[i]<=pivot);
		do{
			j--;
		}while(arr[j]>pivot);
		if(i < j)
			swap(&arr[i],&arr[j]);
	}
	swap(&arr[l],&arr[j]);
	return j;
}

//h位置的值总是最大的
void quick_sort(int arr[],int l, int h)
{
	int j;
	if(l < h)
	{
		j = partition(arr,l,h);
		quick_sort(arr,l,j);
		quick_sort(arr,j+1,h);
	}
}

void main()
{
	int i,a[]={14,23,27,70,82,100,3,5,14,29,33,50};
	int len = sizeof(a)/sizeof(a[0]);
	int *arr = (int *)malloc(sizeof(int)*(len+1));
	memcpy(arr,a,sizeof(int)*len);
	arr[len+1] = 0xffff;
	quick_sort(arr,0,len);
	for(i=0; i<len; i++)
		printf("%d ",arr[i]);
}