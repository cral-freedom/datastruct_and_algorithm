#include "stdio.h"

int list[9] = {12, 5, 61, 32, 23, 53, 19, 26, 8};
void sorted(int a[],int len)	//选择排序
{
	int i,j,tmp;
	for(i=0; i<len; i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(a[i] > a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

int IBinSearch(int a[], int len, int key)//迭代法
{
	int l=0,h=len-1,mid=(l+h)/2;
	while(l <= h)
	{
		if(a[mid] == key)
			return mid;
		else if(a[mid] < key)
			l = mid + 1;
		else if(a[mid] > key)
			h = mid - 1;

		mid = (l+h)/2;	
	}
	return 0;
}

int RBinSearch(int l, int h, int key)//递归法
{
	int mid = (l+h)/2;
	if(l>=h && list[l] != key)
		return 0;
		
	if(list[mid] == key)
		return mid;
	else if(list[mid] < key)
		return RBinSearch(mid+1,h,key);
	else if(list[mid] > key)
		return RBinSearch(l,mid-1,key);
}
void main()
{
	int i,len = sizeof(list)/sizeof(list[0]);
	int pos,key;
	sorted(list,len);
	// for(i=0;i<len;i++)
	// 	printf("%d ",list[i]);
	printf("what do you want to search:");
	scanf("%d",&key);
	// pos = IBinSearch(list,len,key);
	pos = RBinSearch(0,len-1,key);
	printf("pos:%d\n",pos);
}