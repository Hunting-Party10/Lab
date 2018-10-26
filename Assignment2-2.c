/*
 ============================================================================
 Name        : Matrixptr.c
 Author      : Atharva Joshi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define max 20

void accept(int *matrix,int r,int c)
{
	int i,j;
	printf("Enter the Elements of the matrix \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",(matrix+i*c+j));
		}
		printf("Row %d complete\n",(i+1));
	}
}

void display(int *matrix,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",*(matrix+i*c+j));
		}
		printf("\n");
	}
}

int addition(int *matrixA,int *matrixB,int *ans,int row1,int col1,int row2,int col2)
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
				*(ans+i*col1+j)=*(matrixA+i*col1+j)+*(matrixB+i*col1+j);
			}
		}
		return 0;
		}

}
void multiply(int *matrixA,int *matrixB,int *ans,int row1,int col1,int row2,int col2)
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
				t=t+(*(matrixA+i*col1+j))*(*(matrixB+j*col2+k));
			}
			*(ans+i*col1+k)=t;
			k++;
		}
	}

}

void transpose(int *matrix,int *resultant,int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			*(resultant+j*row+i)=*(matrix+i*col+j);
		}
	}

}

void saddle(int *matrix,int row,int col)
{

	if((row==1)&&(col==1))
	{
		printf("(%d,%d) Element:%d",row-1,col-1,*matrix);
	}
	else
	{
		int i,j;
		int c=0;
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++)
				{
					int max1=*(matrix+i*col+j),min=*(matrix+i*col+j);
					int x;
					for(x=0;x<col;x++)
					{
						if(max1<*(matrix+x*col+j))
						{
							max1=*(matrix+x*col+j);
						}
					}
					for(x=0;x<row;x++)
					{
						if(min>*(matrix+i*col+x))
						{
							min=*(matrix+i*col+x);
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
	printf("\n");


}

int main(void) {
	int choice,i,c=0;
	int *matrixA,*matrixB,*resultant;
	int i1=20,j1=20,i2=20,j2=20;
	do
		{
		printf("\n\nMatrix Operations\n \n");
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
				printf("Enter Rows of Matrix A\n");
				scanf("%d",&i1);
				printf("Enter Columns of Matrix A\n");
				scanf("%d",&j1);
				if(c!=0)
				{
					free(matrixA);
				}
				matrixA=(int *)malloc(sizeof(int)*i1*j1);
				accept(matrixA,i1,j1);
				printf("Enter Rows of Matrix B\n");
				scanf("%d",&i2);
				printf("Enter Columns of Matrix B\n");
				scanf("%d",&j2);
				if(c!=0)
				{
					free(matrixB);
				}
				matrixB=(int *)malloc(sizeof(int)*i2*j2);
				accept(matrixB,i2,j2);
				c++;
				break;

			case 2:
				if(c==0)
				{
					printf("Please Enter a Matrix\n");
							break;
				}
				printf("Matrix A is\n");
				display(matrixA,i1,j1);
				printf("Matrix B is\n");
				display(matrixB,i2,j2);
				break;

			case 3:
				if(c==0)
				{
					printf("Please Enter a Matrix\n");
					break;
				}
				printf("Matrix A is\n");
				display(matrixA,i1,j1);
				printf("Matrix B is\n");
				display(matrixB,i2,j2);
				resultant=(int *)malloc(sizeof(int)*i2*j2);
				i=addition(matrixA,matrixB,resultant,i1,j1,i2,j2);
				if(i==0)
				{
					printf("Answer is\n");
					display(resultant,i1,j1);
					printf("\n");
				}
				free(resultant);
				break;

			case 4:
				if(c==0)
				{
					printf("Please Enter a Matrix\n");
					break;
				}
				printf("Matrix A is\n");
				display(matrixA,i1,j1);
				printf("Matrix B is\n");
				display(matrixB,i2,j2);
				printf("For AB\n");
				if(i1==j2)
				{
					resultant=(int *)malloc(sizeof(int)*i2*j1);
					multiply(matrixA,matrixB,resultant,i1,j1,i2,j2);
					display(resultant,i2,j1);
					printf("\n");
					free(resultant);

				}
				else
				{
					printf("Matrix cannot be multiplied");
				}
				printf("For BA\n");
				if(j1==i2)
				{
					resultant=(int *)malloc(sizeof(int)*i1*j2);
					multiply(matrixB,matrixA,resultant,i2,j2,i1,j1);
					display(resultant,i1,j2);
					printf("\n");
					free(resultant);
				}
				else
				{
					printf("Matrix cannot be multiplied");
				}

				break;

			case 5:
				if(c==0)
				{
					printf("Please Enter a Matrix\n");
					break;
				}
				printf("Matrix A is\n");
				display(matrixA,i1,j1);
				printf("Matrix B is\n");
				display(matrixB,i2,j2);
				printf("Transpose of Matrix A is\n");
				resultant=(int *)malloc(sizeof(int)*max*max);
				transpose(matrixA,resultant,i1,j1);
				display(resultant,j1,i1);
				free(resultant);
				printf("Transpose of Matrix B is\n");
				resultant=(int *)malloc(sizeof(int)*max*max);
				transpose(matrixB,resultant,i2,j2);
				display(resultant,j2,i2);
				free(resultant);

				break;

			case 6:
				if(c==0)
				{
					printf("Please Enter a Matrix\n");
					break;
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

			default:printf("Enter Valid Option");
			}
		}
	while(choice!=7);
	return 0;
}
