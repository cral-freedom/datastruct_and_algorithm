#include "stdio.h"
void main()
{
	int a,b;
	float c;
	printf("input a b:");
	scanf("%d%d",&a,&b);
	c = (float)a/b;//将a转化成浮点数，再除以b
	printf("%f",c);


}