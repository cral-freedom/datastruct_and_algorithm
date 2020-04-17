#include "quicksort.h"
//对Obj的收益率进行，降序排序

void swap(elemtype *p1, elemtype *p2)
{
	elemtype tmp;
	tmp = *p1; *p1 = *p2; *p2 = tmp;
}

int partition(elemtype arr[], int l, int h)
{
	int i=l,j=h,mid=(l+h)/2;
	float pivot = arr[mid].pw_rate;
	while(i < j)
	{
		while(arr[i].pw_rate > pivot)
			i++;
		while(arr[j].pw_rate < pivot)
			j--;
		if(arr[i].pw_rate == pivot && arr[j].pw_rate == pivot) break;
		if(i < j)
			swap(&arr[i],&arr[j]);
	}
	return j;
}
void quick_sort(elemtype arr[], int l, int h)
{
	int j;
	if(l < h)
	{
		j = partition(arr,l,h);
		quick_sort(arr,l,j-1);
		quick_sort(arr,j+1,h);
	}

}

