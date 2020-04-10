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
	while(i < j)
	{
		while(arr[i]<=pivot)
			i++;
		while(arr[j]>pivot)
			j--;
		if(i < j)
			swap(&arr[i],&arr[j]);
	}
	swap(&arr[l],&arr[j]);
	// printf("j:%d ",j);
	return j;
}

void quick_sort(int arr[],int l, int h)
{
	int j;
	if(l < h)
	{
		j = partition(arr,l,h);
		quick_sort(arr,l,j-1);
		quick_sort(arr,j+1,h);
	}
}

void main()
{
	// int i,a[]={14,23,27,70,82,100,3,5,14,29,33,50};
	int i,a[] = {10,16,8,12,15,6};
	int len = sizeof(a)/sizeof(a[0]);
	quick_sort(a,0,len-1);
	// printf("\n");
	for(i=0; i<len; i++)
		printf("%d ", a[i]);
}