#include "stdio.h"
#include "stdlib.h"

void merge(int *arr, int L, int M, int R)
{
	int left_size = M - L;
	int right_size = R - M + 1;
	int *L_arr = (int *)malloc(sizeof(int)*left_size);
	int *R_arr = (int *)malloc(sizeof(int)*right_size);
	int i=0,j=0,k=L;
	for(i=0; i<M; i++)
		L_arr[i-L] = arr[i];
	for(i=M; i<=R; i++)
		R_arr[i-M] = arr[i];
	
	i = 0;
	while(i<left_size && j<right_size)
	{
		if(L_arr[i] <= R_arr[j])
			arr[k++] = L_arr[i++];
		else
			arr[k++] = R_arr[j++];
	}
	while(i<left_size)
		arr[k++] = L_arr[i++];
	while(j<right_size)
		arr[k++] = R_arr[j++];	
}

void merge_sort(int *arr, int L, int R)
{
	if(L == R)
		return ;
	else
	{
		int M = (L+R)/2;
		merge_sort(arr,L,M);
		merge_sort(arr,M+1,R);
		merge(arr,L,M+1,R);
	}	
}

int* merge_2list(int A[], int B[], int alen, int blen)
{
	int i=0,j=0,k=0,clen = alen+blen;//要赋初值
	int *C = (int *)malloc(sizeof(int)*clen);
	// printf("alen:%d\tblen:%d\n",alen,blen);
	while(i<alen && i<blen)
	{
		if(A[i] <= B[j])
			C[k++] = A[i++];
		else
			C[k++] = B[j++];
	}
	for(;i<alen;i++)
		C[k++] = A[i++];
	for(;j<blen;j++)
		C[k++] = B[j++];
	return C;
}
void main()
{
	int i;
	int arr[]={14,23,27,70,82,100,3,5,14,29,33,50};
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("len:%d \n",len);
	merge_sort(arr,0,11);
	for(i=0; i<len; i++)
		printf("%d ",arr[i]);
}