/*
 ============================================================================
 Name        : SetOperations.c
 Author      : Atharva Joshi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void getSet(int set[],int n)
	{
		int temp;
		printf("Enter Elements\n");
		for(temp=0;temp<n;temp++)
		{
			scanf("%d",&set[temp]);
		}
	}

void Union(int setA[],int setB[],int resultant[],int a,int b)
		{
			int i,j;
			for(i=0;i<a;i++)
			{
				resultant[i]=setA[i];
			}
			for(j=0;j<b;j++)
			{
				int z=0,flag=0;
				for(z=0;z<i;z++)
				{
					if(resultant[z]==setB[j])
					{
						flag=1;
					}
				}
				if(flag==0)
				{
					resultant[i]=setB[j];
					i++;
				}
			}
			display(resultant,i);


		}

void Intersection(int setA[],int setB[],int resultant[],int a,int b)
		{
			int i,j,c=0;
			for(i=0;i<a;i++)
			{
				for(j=0;j<b;j++)
				{
					if(setA[i]==setB[j])
					{
						int flag=0;
						int z;
						for(z=0;z<=c;z++)
						{
							if(resultant[z]==setA[i])
							{
								flag=1;
								break;
							}
						}
						if(flag==0)
						{
							resultant[c]=setA[i];
							c++;
						}
					}
				}
			}
			display(resultant,c);

		}

void Difference(int setA[],int setB[],int resultant[],int a,int b)
		{
			int i,j,c=0;
			for(i=0;i<a;i++)
			{
				int flag=0;
				for(j=0;j<b;j++)
				{

					if(setA[i]==setB[j])
					{
						flag=1;
					}

				}
				if(flag==0)
					resultant[i]=setA[i];
				c++;
			}
			display(resultant,c);
		}

void symmetricDifference(int setA[],int setB[],int resultant[],int a,int b)
		{
			int resultant1[20];
			int resultant2[20];
			int x,y;
			Difference(setA,setB,resultant1,a,b);
			Difference(setB,setA,resultant2,b,a);
			int t;

			Union(resultant1,resultant2,resultant,a,b);


		}
void display(int resultant[],int n)
{
	int t;
	for(t=0;t<n;t++)
		{
			printf("%d\n",resultant[t]);
		}
	printf("\n\n");
}

int main(void) {
	int choice;
	int setA[10];
	int setB[10];
	int resultant[20];
	int a,b;
	do
	{
		printf("Set Operations \n \n");
		printf("1)Enter Set\n");
		printf("2)Union\n");
		printf("3)Intersection\n");
		printf("4)Difference\n");
		printf("5)Symmetric Difference\n");
		printf("6)Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
				printf("Enter Number of elements of Set A\n");
				scanf("%d",&a);
				getSet(setA,a);
				printf("Enter Number of elements of Set B\n");
				scanf("%d",&b);
				getSet(setB,b);
				break;
		case 2:
				Union(setA,setB,resultant,a,b);
				break;
		case 3:
				Intersection(setA,setB,resultant,a,b);
				break;
		case 4:
				Difference(setA,setB,resultant,a,b);
				break;
		case 5:
				symmetricDifference(setA,setB,resultant,a,b);
				break;
		case 6:
				break;
		default:
			printf("Enter Valid Option\n");
		}
	}while(choice!=6);
	return 1;
}
