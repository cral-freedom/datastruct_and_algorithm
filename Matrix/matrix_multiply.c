#include "stdio.h"

//pMatrix[i][j]
// #define GetValue(pResult,col,i,j) (*((int*)pResult + col*i + j))
int GetValue(int **pResult,int col,int i,int j) 
{
	return (*((int*)pResult + col*i + j));
}


void MatrixMultiply(int (*pMatrix1)[2], int row1, int col1,
				int (*pMatrix2)[2], int row2, int col2, int (*pResult)[2])
{
	int i,j,k;
	for(i=0; i<row1; i++)
	{
		for(j=0; j<col2; j++)
		{
			pResult[i][j] = 0;
			for(k=0; k< col1; k++)
				pResult[i][j] += pMatrix1[i][k]*pMatrix2[k][j];
		}
	}
} 

void MatrixMultiplyGeneral(int **pMatrix1, int row1, int col1,
				int **pMatrix2, int row2, int col2, int **pResult)
{
	int i,j,k,sum,val1=0,val2=0;
	if(col1!=row2) return ;
	for(i=0; i<row1; i++)
	{
		for(j=0; j<col2; j++)
		{
			sum = 0;
			for(k=0; k< col1; k++)
			{
				val1 = GetValue(pMatrix1,col1,i,k);
				val2 = GetValue(pMatrix2,col2,k,j);
				sum += val1*val2;
				printf("%d*%d	",val1,val2);
				//pResult[i][j] = pMatrix1[i][k]*pMatrix2[k][j];
			}
			printf("\t%d\n",sum);
			*((int*)pResult + col2*i + j) = sum;
		}
	}
}

void print_matrix(int **a, int row, int col)
{
	int i,j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
			printf("%d ",GetValue(a,col,i,j));
		printf("\n");
	}
}
int main() {
	int a[2][2] = {{2,4},{1,6}};
	int b[2][3] = {{6,4,3},{2,2,1}};
	int c[2][3] = {0};
	MatrixMultiplyGeneral((int **)a,2,2,(int **)b,2,3,(int **)c);
	print_matrix((int **)c,2,3);
	

	return 0;
}