/*
 ============================================================================
 Name        : MatrixOps.c
 Author      : Atharva Joshi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, ANSI-style
 ============================================================================
 */

#include <stdio.h>
#define max 20

void def(int matrix[max][max])
{
	int i,j;
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			matrix[i][j]=0;
		}
	}
}

void accept(int matrix[max][max],int row,int col)
{
	int i,j;
	printf("Enter the Elements of the matrix \n");
	for(i=0;i<row;i++)
	{
		printf("Enter Row %d\n",(i+1));
		for(j=0;j<col;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
		printf("Row %d complete\n",(i+1));
	}

}

void display(int matrix[max][max],int row,int col)
{
	int i,j;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				printf("%d ",matrix[i][j]);
			}
			printf("\n");
		}

}

int addition(int matrix1[max][max],int matrix2[max][max],int ans[max][max],int row1,int col1,int row2,int col2)
{
	if((row1!=row2)&&(col1!=col2))
	{
		printf("Matrix Cannot be Added due to different orders\n");
		return 1;
	}
	else
	{
		int i,j;
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col1;j++)
			{
				ans[i][j]=matrix1[i][j]+matrix2[i][j];
			}
		}
		return 0;
	}
}

int multiply(int matrix1[max][max],int matrix2[max][max],int ans[max][max],int row1,int col1,int row2,int col2)
{
	if((col1==row2)&&(col2==row1))
	{

		int i,j;
			for(i=0;i<row1;i++)
			{

				int k=0;
				while(k<col2)
				{
					int t=0;
					for(j=0;j<col1;j++)
					{
						t=t+(matrix1[i][j]*matrix2[j][k]);
					}
					ans[i][k]=t;
					k++;
				}
			}
		return 0;
	}
	else
	{
		printf("Matrix Cannot be Multiplied due to different orders\n\n\n\n");
		return 1;
	}

}

void transpose(int matrix[max][max],int ans[max][max],int row,int col)
{
	int i,j;
	for(i=0;i<col;i++)
	{
		for(j=0;j<row;j++)
		{
			ans[i][j]=matrix[j][i];
		}
	}

}

void saddle(int matrix[max][max],int row,int col)
{
	int c=0;
	if((row==1)&&(col==1))
	{
		printf("(%d,%d) Element:%d\n",row-1,col-1,matrix[0][0]);
	}
	else
	{
		int i,j;
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++)
				{
					int max1=matrix[i][j],min=matrix[i][j];
					int x;
					for(x=0;x<col;x++)
					{
						if(max1<matrix[x][j])
						{
							max1=matrix[x][j];
						}
					}
					for(x=0;x<row;x++)
					{
						if(min>matrix[i][x])
						{
							min=matrix[i][x];
						}
					}
					if(max1==min)
					{
						printf("(%d,%d) Element:%d,",i,j,min);
						c++;
					}
				}
			}
			if(c==0)
				{
				printf("No Saddle points Exist!");
				}
	}

	printf("\n\n");
}

int main()
{
	int choice,c=0;
	int matrixA[20][20],matrixB[20][20],ans[20][20];
	int i1=20,j1=20,i2=20,j2=20,i;
	do
	{
	printf("\n\nMatrix Operations \n \n");
	printf("1)Enter Matrix\n");
	printf("2)Display Matrix\n");
	printf("3)Addition\n");
	printf("4)Multiplication\n");
	printf("5)Transpose\n");
	printf("6)Saddle Point\n");
	printf("7)Exit\n");
	scanf("%d",&choice);
	switch(choice)
		{
		case 1:
				c++;
				printf("Enter Rows of Matrix A\n");
				scanf("%d",&i1);
				printf("Enter Columns of Matrix A\n");
				scanf("%d",&j1);
				accept(matrixA,i1,j1);
				printf("Enter Rows of Matrix B\n");
				scanf("%d",&i2);
				printf("Enter Columns of Matrix B\n");
				scanf("%d",&j2);
				accept(matrixB,i2,j2);
				break;

		case 2:
				if(c==0)
				{
					def(matrixA);
					def(matrixB);
				}
				printf("Matrix A is\n");
				display(matrixA,i1,j1);
				printf("Matrix B is\n");
				display(matrixB,i2,j2);
				break;

		case 3:
				if(c==0)
				{
					def(matrixA);
					def(matrixB);
				}
				printf("Matrix A is\n");
				display(matrixA,i1,j1);
				printf("Matrix B is\n");
				display(matrixB,i2,j2);
				i=addition(matrixA,matrixB,ans,i1,j1,i2,j2);
				if(i==0)
				{
					printf("Answer is\n");
					display(ans,i1,j1);
					printf("\n");
				}
				break;

		case 4:
				if(c==0)
				{
					def(matrixA);
					def(matrixB);
				}
				printf("Matrix A is\n");
				display(matrixA,i1,j1);
				printf("Matrix B is\n");
				display(matrixB,i2,j2);
				printf("For AB\n");
				i=multiply(matrixA,matrixB,ans,i1,j1,i2,j2);
				if(i==0)
				{
					printf("Answer is\n");
					display(ans,i1,j2);
					printf("\n");
				}
				printf("For BA\n");
				int i=multiply(matrixB,matrixA,ans,i2,j2,i1,j1);
				if(i==0)
				{
					printf("Answer is\n");
					display(ans,i2,j1);
					printf("\n");
				}
				break;

		case 5:
				if(c==0)
				{
					def(matrixA);
					def(matrixB);
				}
				printf("Matrix A is\n");
				display(matrixA,i1,j1);
				printf("Transpose of A is\n");
				transpose(matrixA,ans,i1,j1);
				display(ans,j1,i1);
				printf("Matrix B is\n");
				display(matrixB,i2,j2);
				printf("Transpose of B is\n");
				transpose(matrixB,ans,i2,j2);
				display(ans,j2,i2);
				break;

		case 6:
				if(c==0)
				{
					def(matrixA);
					def(matrixB);
				}
				printf("Matrix A is\n");
				display(matrixA,i1,j1);
				printf("Saddle Point of Matrix A is:");
				saddle(matrixA,i1,j1);
				printf("Matrix B is:\n");
				display(matrixB,i2,j2);
				printf("Saddle Point of Matrix B is:");
				saddle(matrixB,i1,j1);
				break;

		case 7:
				break;

		default:
				printf("Enter Valid Option\n");

		}
	}
	while(choice!=7);
	return 0;
}
