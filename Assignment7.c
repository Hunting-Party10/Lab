/*
Author-Atharva Joshi
Roll Number-23306
Write a program to accept Mobile Infor(Number,Name,Bill)
Perform the following operations on it
1)Display Data in Descending order of name using Recursive QuickSort
2)Display Position of pivot for every pass
3)DIsplay Total number of Comparisons and passes
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME 25
struct Customer
{
	long phone_no;
	char name[NAME];
	int bill;
	int id;
};
void tabletail()//display table structure
{
	int i;
	for(i=0;i<64;i++)
		printf("-");
	printf("\n");
}
void tablehead()//displays table structure
{
	tabletail();
	printf("|Phone Number|Customer Name            |Bill       |Customer-ID|\n");
	tabletail();
}
void display(struct Customer c)
{
	printf("|%-12ld|%-25s|Rs %-8d|%-11d|\n",c.phone_no,c.name,c.bill,c.id);
	tabletail();
}

void write_data(struct Customer customer[50],int c,long phone,char name[],int bill,int id)
{
	customer[c].phone_no=phone;
	strcpy(customer[c].name,name);
	customer[c].bill=bill;
	customer[c].id=id;
}
int validate(struct Customer customer[50],int c,int query)
{
	if(c==0)
		return -1;
	else
	{
		int i;
		for(i=0;i<c;i++)
		{
			if(customer[i].phone_no==query)
				return 1;
		}
		return -1;
	}
}

int partition (struct Customer c[50], int low, int high,int summary[2]) 
{ 
    char pivot[NAME];
    strcpy(pivot,c[high].name);    // pivot 
    int i = (low - 1);  // Index of smaller element 
    int comp=0,swaps=0;
    int j;
    for (j = low; j <= high- 1; j++) 
    { 
        // If current element is less than or 
        // equal to pivot 
        comp++;
        if (strcmp(pivot,c[j].name)<0) 
        { 
            i++;    // increment index of smaller element 
            struct Customer temp=c[i];
            c[i]=c[j];
            c[j]=temp;
            swaps++;
        } 
    } 
    struct Customer temp=c[i+1];
    c[i+1]=c[high];
    c[high]=temp;
    swaps++;
    summary[0]+=comp;
    summary[1]+=swaps;
    return (i + 1); 
} 

void quickSort(struct Customer c[50],int low,int high,int count,int summary[2])
{
	if (low < high) 
    { 
        /* pi is partitioning index, c[p] is now 
           at right place */
        int pi = partition(c, low, high,summary);
        printf("\nPosition of New Pivot = %d\n",pi ); 
        int i;
        for (i = 0; i < count; ++i)
        {
        	printf("| %s |\t",c[i].name );
        }
        printf("\n");
  		
        // Separately sort elements before 
        // partition and after partition 
        quickSort(c, low, pi - 1,count,summary); 
        quickSort(c, pi + 1, high,count,summary); 
    }
}



int main(void) {
	struct Customer customer[50];
	int summary[2];
	int i;
	int count=0;
	int choice;
	int choice1;
	long query=0;
	int flag=0;
	char name[NAME];
	do
	{
		printf("\n\n");
		printf("Customer DataBase\n");
		printf("Press 1 to add data\n");
		printf("Press 2 to display Data\n");
		printf("Press 3 to display data in Descending order of Name(Recursive Quick Sort)\n");
		printf("Press 4 to Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			do
			{
				printf("Enter Phone Number-");
				scanf("%ld",&query);
				flag=validate(customer,count,query);
				if(flag!=-1)
				printf("Phone Number Repeated Please Enter Again!\n");
			}
			while(flag!=-1);
			printf("Enter Customer Name-");
			while(getc(stdin)!='\n');
			gets(name);
			printf("Enter Customer Bill-");
			scanf("%d",&choice1);
			printf("Enter Customer ID-");
			scanf("%d",&flag);
			write_data(customer,count,query,name,choice1,flag);
			count++;
			break;

		case 2:
			if(count==0)
				printf("Enter Data First\n");
			else
			{
				tablehead();
				for(i=0;i<count;i++)
				{
					display(customer[i]);
				}
			}
			break;

		case 3:
			if(count==0)
				printf("Enter Data First\n");
			else
			{
				printf("Running Recursive Quicksort\n\nPasses\n");
				summary[0]=0;
				summary[1]=0;
				quickSort(customer,0,count-1,count,summary);
				printf("\nQuicksort Complete:\nTotal Number of COmparisions = %d\nTotal Number of swaps = %d\n",summary[0],summary[1]);
				tablehead();
				for(i=0;i<count;i++)
				{
					display(customer[i]);
				}

			}
			break;

		case 4:
			break;
		default:
			printf("Enter valid Option");
		}

	}
	while(choice!=4);
	return 0;
}

