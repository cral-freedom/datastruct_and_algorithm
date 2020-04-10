#include "stdio.h"
void main()
{
	// char str[] = {0,1,2,3};
	// char *pc = str;
	// int *pi = (int *)str;
	// printf("*pc:%d\t*pi:%x",*pc,*pi);

	int i;
	int a[3][3] = {4,5,6,7,8,9,10,11,12};	
	int ** p;
	p = (int**)a;		/* 不做强制类型转换会报错 */
	printf("a:%d\tp:%d\n",a,p);
	printf("*a:%d\t*p:%d\n",*a,*p);
	printf("%d\t",**a);
	printf("%d\n",**p);//*p=4，地址为4的空间，无权访问	
}