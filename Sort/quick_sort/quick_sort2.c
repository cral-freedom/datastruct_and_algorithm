#include "stdio.h"

void swap(int *p1, int *p2)
{
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int partition(int arr[],int l, int h)
{
	int i = l, j = h, mid = (l+h)/2;	//a[l:h]
	int pivot = arr[mid];

	while(i < j)
	{
		while(arr[i]<pivot)
			i++;
		while(arr[j]>pivot)
			j--;
		if(i < j)
		{
			printf("i:%d\tj:%d\tswap(%d,%d)\n",i,j,arr[i],arr[j]);
			swap(&arr[i],&arr[j]);
		}
		//swap之后，i++或j--重新使能，直到i=j退出循环
	}
	for(i=0; i<9; i++)
		printf("%d ", arr[i]);
	printf("\tj:%d\n",j);
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
	int i,a[]={27,70,82,100,29,5,14,33,50};
	int len = sizeof(a)/sizeof(a[0]);
	quick_sort(a,0,len-1);
	printf("\n");
	for(i=0; i<len; i++)
		printf("%d ", a[i]);
}