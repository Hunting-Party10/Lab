
/*
Author-Atharva Joshi
Roll Number-23306

Write a program to create a sparse matrix and perform the following operations on it
1)Addition of two sparse Matrix
2)Simple Transpose
3)Fast Transpose
*/
#include<stdio.h>
struct SparseMatrix
{
	int row;
	int col;
	int value;
};

void addData(int n,struct SparseMatrix s[])
{
	int i,j,count=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			int t;
			printf("Enter data for Row:%d Col:%d -",(i+1),(j+1));
			scanf("%d",&t);
			if(t!=0)
			{
				count++;
				s[count].row=i;
				s[count].col=j;
				s[count].value=t;
			}

		}
	}
	s[0].row=n;
	s[0].col=n;
	s[0].value=count;
}

void displayMatrix(struct SparseMatrix s[])
{
	int i,j;
	int count=1;
	for(i=0;i<s[0].row;i++)
	{
		for(j=0;j<s[0].col;j++)
		{
			if(s[count].row==i && s[count].col==j && count<s[0].value)
			{
				printf("%d ",s[count].value);
				count++;
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
	printf("\n");
}
void tail()
{
	int i;
	for(i=0;i<20;i++)
	{
			printf("-");
	}
	printf("\n");
}
void head()
{
	tail();
	printf("|Object     |Row  |Column|Value   |\n");
	tail();
}
void displaySparse(struct SparseMatrix s[])
{
	int n=s[0].value;
	int i;
	for(i=0;i<=n;i++)
	{
		printf("|Sparse[%-2d]  |%-5d|%-6d|%-8d|",i,s[i].row,s[i].col,s[i].value);
	}
}

void add(struct SparseMatrix sp1[],struct SparseMatrix sp2[],struct SparseMatrix result[])
{
	int i=1,j=1;
	result[0].row=sp1[0].row;
	result[0].col=sp1[0].col;
	int count=1;
	while(i<=sp1[0].value && j<=sp2[0].value)
	{
		if(sp1[i].row == sp2[j].row)
		{
			if(sp1[i].col >sp2[j].col)
			{
				result[count].row=sp2[j].row;
				result[count].col=sp2[j].col;
				result[count++].value=sp2[j++].value;
			}
			else if(sp1[i].col <sp2[j].col)
			{
				result[count].row=sp1[i].row;
				result[count].col=sp1[i].col;
				result[count++].value=sp2[i++].value;
			}
			else
			{
				result[count].row=sp1[i].row;
				result[count].col=sp1[i].col;
				result[count++].value=sp2[i++].value+sp1[j++].value;
			}
		}
		else if(sp1[i].row > sp2[j].row)
		{
			result[count].row=sp2[j].row;
			result[count].col=sp2[j].col;
			result[count++].value=sp2[j++].value;
		}
		else
		{
			result[count].row=sp1[i].row;
			result[count].col=sp1[i].col;
			result[count++].value=sp1[i++].value;
		}
	}
	if(i<=sp1[0].value)
	{
		while(i<=sp1[0].value)
		{
			result[count].row=sp1[i].row;
			result[count].col=sp1[i].col;
			result[count++].value=sp1[i++].value;
		}
	}
	if(j<=sp2[0].value)
	{
		while(j<=sp2[0].value)
		{
			result[count].row=sp2[j].row;
			result[count].col=sp2[j].col;
			result[count++].value=sp2[j++].value;
		}
	}
	result[0].value=count;
}
void simpleTranspose(struct SparseMatrix s[],struct SparseMatrix result[])
{
	int j,i,count=1;
	result[0].value=s[0].value;
	result[0].col=s[0].col;
	result[0].row=s[0].row;
	for(j=0;j<=s[0].col;j++)
	{
		for(i=1;i<=s[0].value;i++)
		{
			if(s[i].col==j)
			{
				result[count].row=s[i].col;
				result[count].col=s[i].row;
				result[count++].value=s[i].value;
			}
		}
	}
}

void fastTranspose(struct SparseMatrix s[],struct SparseMatrix result[])
{
	result[0].value=s[0].value;
	result[0].col=s[0].col;
	result[0].row=s[0].row;
	int numberofcols=s[0].col;
	int numberofterms=s[0].value;
	if(numberofterms!=0)
	{
		int row[numberofcols];
		int startpos[numberofcols];
		int i;
		for(i=0;i<numberofcols;i++)
			row[i]=0;
		for(i=1;i<=numberofterms;i++)
			row[s[i].col]++;
		startpos[0]=1;
		for(i=1;i<numberofcols;i++)
			startpos[i]=startpos[i-1]+row[i-1];
		for(i=1;i<=numberofterms;i++)
		{
			int temp=startpos[s[i].col]++;
			result[temp].row=s[i].col;
			result[temp].col=s[i].row;
			result[temp].value=s[i].value;
		}
	}
}

int main()
{
	int n;
	printf("Enter Size of matrix:");
	scanf("%d",&n);
	struct SparseMatrix sp1[n*n+1],sp2[n*n+1],result[n*n+1];
	int c=0;
	int choice;
	do
	{
		printf("\nSparse Matrix Operations\n");
		printf("Press 1 to Enter Matrix\n");
		printf("Press 2 to display Matrix\n");
		printf("Press 3 to Add Matrix\n");
		printf("Press 4 to Perform Simple Transpose\n");
		printf("Press 5 to perform Fast Transpose\n");
		printf("Press 6 to exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter data for Matrix A\n");
				addData(n,sp1);
				printf("Data Added\n");
				printf("Enter data for Matrix B\n");
				addData(n,sp2);
				printf("Data Added\n");
				c++;
				break;
			case 2:
				if(c==0)
					printf("Please Enter values first\n");
				else
				{
					printf("Matrix A is \n");
					displayMatrix(sp1);
					printf("Matrix B is \n");
					displayMatrix(sp2);
				}
				break;
			case 3:
				if(c==0)
					printf("Please Enter values first\n");
				else
				{
					add(sp1,sp2,result);
					printf("Matrix A is \n");
					displayMatrix(sp1);
					printf("Matrix B is \n");
					displayMatrix(sp2);
					printf("A+B is \n");
					displayMatrix(result);
				}
				break;
			case 4:
				if(c==0)
					printf("Please Enter values first\n");
				else
				{
					printf("Matrix A is \n");
					displayMatrix(sp1);
					printf("Transpose of Matrix A is \n");
					simpleTranspose(sp1,result);
					displayMatrix(result);
					printf("Matrix B is \n");
					displayMatrix(sp2);
					printf("Transpose of Matrix B is \n");
					simpleTranspose(sp2,result);
					displayMatrix(result);
				}
				break;
			case 5:
				if(c==0)
					printf("Please Enter values first\n");
				else
				{
					printf("Matrix A is \n");
					displayMatrix(sp1);
					printf("Fast Transpose of Matrix A is \n");
					fastTranspose(sp1,result);
					displayMatrix(result);
					printf("Matrix B is \n");
					displayMatrix(sp2);
					printf("Fast Transpose of Matrix B is \n");
					fastTranspose(sp2,result);
					displayMatrix(result);
				}
				break;
			case 6:
				break;

			default:
				printf("Enter Valid option\n\n");
		}

	}
	while(choice!=6);
	return 0;
}

