#include "stdio.h"
#include "stdlib.h"

void insert_sort(int arr[], int len)
{
	int i,j,k;
	for(i=1; i<len; i++)//从第i个数开始插入
	{
		j=0;
		while(j<i && arr[i] >= arr[j]) 
			j++;
		printf("i:%d\tj:%d\n",i,j);
		//若需要插入,插入到arr[j]前面
		//具体操作：a[j~i-1]的值向后移，a[i]填入a[j]原来的位置
		if(j<i)
		{
			int tmp = arr[i],k=i;//保存a[i]的值
			for(;k>j;k--)
				arr[k] = arr[k-1];
			arr[k] = tmp; 
		}	
		//如果待插入的数比有序数组中的数大，则j=i，不用插入
	}
}

//从后往前找，同时挪位，降低代码复杂度
void insert_sort2(int arr[], int len)
{
	int i,j,tmp;
	for(i=1; i<len; i++)
	{
		tmp = arr[i];//保存待插入的值
		j = i-1;
		while(j>=0 && arr[j] > tmp)
		{
			arr[j+1] = arr[j];//若大于待插入的值，则向后移
			j--;
		}
		if(j != i-1)
			arr[j+1] = tmp;
	}
}

//因为需要插入的数组已经是有序的，所以可以用二分查找来寻找插入位置
int find_insertpos(int arr[], int len, int key)//查找插入的位置
{
	int ibegin = 0, iend = len - 1, mid = -1;
	while(ibegin <= iend)
	{
		mid = (ibegin+iend)/2;
		if(arr[mid] < key)
			ibegin = mid + 1;
		else
			iend = mid - 1;			
	}
	return mid;
}
void insert_sort3(int arr[], int len)
{
	int i,j,index=-1,tmp;
	for(i=1; i<len; i++)
	{
		index = find_insertpos(arr,i,arr[i]);
		// printf("index:%d\n",index);
		tmp = arr[i];
		for(j=i;j>index;j--)
			arr[j] = arr[j-1];
		arr[index] = tmp;	
	}
}

void main()
{
	int i,arr[7] = {43, 20, 13, 50, 7, 18, 34};
	int len = sizeof(arr)/sizeof(arr[0]);
	// insert_sort(arr,len);
	insert_sort3(arr,len);
	for(i=0;i<7;i++)
		printf("%d ",arr[i]);
}