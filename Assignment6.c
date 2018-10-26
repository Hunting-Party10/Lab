/*
Name        : Assignment6.c
Author      : Atharva Joshi
Problem Statement:
Accept Student Info(ROll No,Name)
1)Display data in Ascending order of Roll No (Bubble Sort)
2)Display data in Descending order of Name(Selection Sort)
3)Display data of roll number satisfied by user(Binary Search with and without recursion)
4)Display Number of passes,test cases(Worst Average Best case)

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME 25
struct Student
{
	int roll_no;
	char name[NAME];
	int age;
	int marks;
};

void displaytail()//display table structure
{
	int i;
	for(i=0;i<52;i++)
		printf("-");
	printf("\n");
}
void displayhead()//displays table structure
{
	displaytail();
	printf("|Roll Number  |Student Name             |Marks|Age |\n");
	displaytail();
}

void write_data(struct Student stud[50],int c,int roll,char name[],int marks,int age)
{
	stud[c].roll_no=roll;
	strcpy(stud[c].name,name);
	stud[c].age=age;
	stud[c].marks=marks;
}

void bubble_sort(struct Student stud[50],int c){
	int passes=1;
	int i,j;
	printf("Pass %d-",passes);
	for(j=0;j<c;j++)
		printf("\t%d ",stud[j].roll_no);
	printf("\n");
	int tcomparisons=0,tswaps=0;
	for(i=0;i<c;i++)
	{
		int comparisons=0;
		int swaps=0;
		for(j=0;j<c-i-1;j++)
		{
			comparisons++;
			if(stud[j].roll_no>stud[j+1].roll_no)
			{

				swaps++;
				struct Student temp=stud[j];
				stud[j]=stud[j+1];
				stud[j+1]=temp;
			}

		}
		passes++;
		printf("Pass %d-",passes);
		for(j=0;j<c;j++)
			printf("\t%d ",stud[j].roll_no);
		printf("\tComarisons=%d,Swaps=%d",comparisons,swaps);
		printf("\n");
		if(swaps==0)
			break;
		else
		{
			tcomparisons+=comparisons;
			tswaps+=swaps;
		}
	}
	printf("Sort Summary\nTotal Comparisons=%d\nTotal Array Swaps=%d\n\n",tcomparisons,tswaps);
	if(tswaps==0)
		printf("Best Case\n\n");
	else
		printf("Average Case\n\n");
}

void selection_sort(struct Student stud[50],int c)
{
	int passes=1;
	int i,j;
	printf("Pass %d :",passes);
	for(j=0;j<c;j++)
		printf("\t%s ",stud[j].name);
	printf("\n");
	int tcomparisons=0,tswaps=0;
	for(i=0;i<c-1;i++)
	{
		int diff=0;
		int index=-1;
		int comparisons=0;
		int swaps=0;
		for(j=i+1;j<c;j++)
		{
			comparisons++;
			if(strcmp(stud[i].name,stud[j].name)<diff)
				{
					diff=strcmp(stud[i].name,stud[j].name);
					index=j;
				}
		}
		if(index!=-1)
		{
			swaps++;
			struct Student temp=stud[i];
			stud[i]=stud[index];
			stud[index]=temp;
			passes++;
			printf("Pass %d :",passes);
			for(j=0;j<c;j++)
				printf("\t%s ",stud[j].name);
			printf("Comarisons=%d,Swaps=%d",comparisons,swaps);
			printf("\n");
			tcomparisons+=comparisons;
			tswaps+=swaps;
		}
		else
			break;
	}
	printf("Sort Summary\nTotal Comparisons=%d\nTotal Array Swaps=%d\n\n",tcomparisons,tswaps);
	if(tswaps==0)
		printf("Best Case\n\n");
	else
		printf("Average Case\n\n");
}

int nrbinary_search(struct Student stud[50],int c,int query)
{
	//int passes=0;
	int low=0;
	int high=c;
	int mid;
	while(low<=high)
	{
		mid=(low+high-1)/2;
		if(query<stud[mid].roll_no)
			high=mid-1;
		else if(query<stud[mid].roll_no)
			low=mid+1;
		else
			return mid;
	}
	return -1;
}

void display(struct Student stud){
	printf("|%-13d|%-25s|%-5d|%-4d|\n",stud.roll_no,stud.name,stud.marks,stud.age);
	displaytail();
}
int validate(struct Student stud[50],int c,int query)
{
	if(c==0)
		return -1;
	else
	{
		int i;
		for(i=0;i<c;i++)
		{
			if(stud[i].roll_no==query)
				return 1;
		}
		return -1;
	}
}

int rbinary_search(struct Student stud[50],int low,int high,int query)
{
	if(low>high)
		return -1;
	int mid=(low+high-1)/2;
	if(query<stud[mid].roll_no)
		return rbinary_search(stud,0,mid-1,query);
	else if(query>stud[mid].roll_no)
		return rbinary_search(stud,mid+1,high,query);
	else
		return mid;
}

int main(void) {
	struct Student stud[50];
	int i;
	int index;
	int count=0;
	int choice;
	int choice1;
	int query;
	int flag;
	char name[NAME];
	do
	{
		printf("\n\n");
		printf("Student DataBase\n");
		printf("Press 1 to add data\n");
		printf("Press 2 to display data in ascending order of Roll Number(Bubble Sort)\n");
		printf("Press 3 for descending order of Name(Insertion Sort)\n");
		printf("Press 4 for Searching a roll no\n");
		printf("Press 5 to Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			do
			{
				printf("Enter Roll Number-");
				scanf("%d",&query);
				flag=validate(stud,count,query);
				if(flag!=-1)
					printf("Roll Number Repeated Please Enter Again!\n");
			}
			while(flag!=-1);
			printf("Enter Student Name-");
			while(getc(stdin)!='\n');
			gets(name);
			printf("Enter Student Age-");
			scanf("%d",&choice1);
			printf("Enter Student marks-");
			scanf("%d",&flag);
			write_data(stud,count,query,name,choice1,flag);
			count++;
			printf("\n");
			break;

		case 2:
			if(count==0)
				printf("Please Enter Data First\n");
			else
			{

				bubble_sort(stud,count);
				displayhead();
				for(i=0;i<count;i++)
					display(stud[i]);
				printf("\n\n");
			}

			break;

		case 3:
			if(count==0)
				printf("Please Enter Data First\n");
			else
			{

				selection_sort(stud,count);
				displayhead();
				for(i=0;i<count;i++)
					display(stud[i]);
			}
			break;

		case 4:
			if(count==0)
				printf("Please Enter Data First\n");
			else
			{
				bubble_sort(stud,count);
				printf("Enter Roll Number you want to Search:");
				scanf("%d",&query);
				printf("Press 1 for Recursive Binary Search\n");
				printf("Press 2 for Non-Recursive Binary Search\n");
				scanf("%d",&choice1);
				switch(choice1)
				{
					case 1:
						index=rbinary_search(stud,0,count,query);
						if(index!=-1)
						{
							displayhead();
							display(stud[index]);
						}
						else
							printf("Record Not Found\n");
						printf("\n\n");
						break;
					case 2:
						index=nrbinary_search(stud,count,query);
						if(index!=-1)
						{
							displayhead();
							display(stud[index]);
						}
						else
							printf("Record Not Found\n");
						printf("\n\n");
						break;
				}
			}
			break;
		case 5:
			break;
		}
	}
	while(choice!=5);
	return 0;
}
