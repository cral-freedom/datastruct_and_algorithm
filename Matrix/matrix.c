#include "stdio.h"
int GetValue(int *pResult,int col,int i,int j)
{
    return (*(pResult + col*i + j));
}
void print_matrix(int *a, int row, int col)
{
    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
            printf("%d ",GetValue(a,col,i,j));
        printf("\n");
    }
}

int find_matrix_max(int *a, int row, int col, int *rpos, int *cpos)
{
	int i,j,max=*a;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			if(max < *(a + i*col + j))
			{
				max = *(a + i*col + j);
				*rpos = i;
				*cpos = j;
			}
		}
	}
	return max;		
}
void main()
{
    int b[2][3] = {{6,14,33},{19,2,21}};
	int max,rpos,cpos;
	
    print_matrix(b[0],2,3);
	//因为int*p=a[0]=&a[0][0]=*a;所以还可写成：
	//print_matrix(&b[0][0],2,3); 
	// print_matrix(*b,2,3);

	max = find_matrix_max(b[0],2,3,&rpos,&cpos);
    printf("max = a[%d][%d] = %d\n",rpos,cpos,max);
}