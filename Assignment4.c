/*
 ============================================================================
 Name        : Employee.c
 Author      : Atharva Joshi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Problem Sttement
 Write a program to create a data base which can
 1)Add
 2)Create
 3)Search
 4)Display
 5)Delete
 6)Modify
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee //Creating a structure
{
	int emp_id;
	char emp_name[20];
	long salary;
	long contact_no;

};

int digit_counter(long n)//counts the number of digits
{
	int count=0;
	while(n>0)
	{
		count++;
		n=n/10;
	}
	return count;
}

void display(struct Employee E)//displaying the data in a tabular format
{
	int digit_count;
	printf("\t|%d",E.emp_id);
	digit_count=digit_counter(E.emp_id);
	int i;
	for(i=0;i<11-digit_count;i++)//giving appropriate number of spaces
	{
		printf(" ");
	}
	printf("\t|");
	printf("%s",E.emp_name);
	digit_count=strlen(E.emp_name);
	for(i=0;i<13-digit_count;i++)//giving appropriate number of spaces
	{
		printf(" ");
	}
	printf("\t|");
	printf("%li",E.salary);
	digit_count=digit_counter(E.salary);
	for(i=0;i<10-digit_count;i++)//giving appropriate number of spaces
	{
		printf(" ");
	}
	printf("\t|");
	digit_count=digit_counter(E.contact_no);
	printf("%li",E.contact_no);
	for(i=0;i<14-digit_count;i++)//giving appropriate number of spaces
	{
		printf(" ");
	}
	printf("\t|\n");
	printf("\t");
	for(i=0;i<65;i++)//draws table border
	{
		printf("-");
	}
	printf("\n");
}

void modify(struct Employee E[50],int c,int max)
{
		printf("\tOriginal record is\n");
		int i;
		for(i=0;i<65;i++)
		{
			printf("-");
		}
		printf("\n");
		printf("\t|Employee ID\t|Employee Name\t|Salary    \t|Contact Number |\n");
		display(E[c]);
		printf("\tDo you want to modify\n");//confirming whether user wants to delete
		printf("\t1)Yes\n\t2)No");
		int ch;
		scanf("%d",&ch);
		if(ch==1)//overwriting over the given index
		{
			fseek(stdin,0,SEEK_END);
			printf("\tEnter Employee Name:");
			scanf("%s",&(E[c].emp_name));
			printf("\tEnter Employee Salary:Rs");
			scanf("%li",&(E[c].salary));
			int flag=1;
			do// code to check whether contact numbers are not the same
			{
				fseek(stdin,0,SEEK_END);
				printf("\tEnter Employee Contact Number:");
				scanf("%li",&(E[c].contact_no));
				if(max==0)
				{
					flag=1;
				}
				else
				{
					int i;
					flag=1;
					for(i=0;i<max;i++)
					{
						if((E[c].contact_no==E[i].contact_no)&&(i!=c))
						{
							flag=0;
							break;
						}
					}
				}
				if(flag==0)
				{
					printf("\tEmployee Contact number cannot be the same\n");
				}
				else
				{
					flag=1;
				}
			}
			while(flag==0);
		}
		else
		{
			printf("\tAborted\n");
		}

}

void add(struct Employee E[50],int c,int max)
{
	int flag=1;
	do
	{
		fseek(stdin,0,SEEK_END);
		printf("\tEnter Employee ID:");
		scanf("%d",&(E[c].emp_id));
		if(max==0)
		{
			flag=1;
		}
		else
		{
			int i;
			flag=1;
			for(i=0;i<max;i++)
			{
				if((E[c].emp_id==E[i].emp_id)&&(i!=c))
				{
					flag=0;
					break;
				}
			}
		}
		if(flag==0)
		{
			printf("\tEmployee ID cannot be the same\n");
		}
		else
		{
			flag=1;
		}
		int i;
		for(i=0;i<65;i++)
		{
			printf("-");
		}
			printf("\n");
						printf("\t|Employee ID\t|Employee Name\t|Salary    \t|Contact Number |\n");}
	while(flag==0);
	fseek(stdin,0,SEEK_END);
	printf("\tEnter Employee Name:");
	scanf("%s",&(E[c].emp_name));
	printf("\tEnter Employee Salary:Rs");
	scanf("%li",&(E[c].salary));
		do
		{
			fseek(stdin,0,SEEK_END);
			printf("\tEnter Employee Contact Number:");
			scanf("%li",&(E[c].contact_no));
			if(max==0)
			{
				flag=1;
			}
			else
			{
				int i;
				flag=1;
				for(i=0;i<max;i++)
				{
					if((E[c].contact_no==E[i].contact_no)&&(i!=c))
					{
						flag=0;
						break;
					}
				}
			}
			if(flag==0)
			{
				printf("\tEmployee Contact number cannot be the same\n");
			}
			else
			{
				flag=1;
			}
		}
		while(flag==0);


}

int search_id(struct Employee E[50],int c,int query)
{
	int index=-1;
	int i;
	for(i=0;i<c;i++)
	{
		if(E[i].emp_id==query)
		{
			index=i;
			break;
		}
	}
	return index;
}

int search_contact(struct Employee E[50],int c,long query)
{
	int index=-1;
	int i;
	for(i=0;i<c;i++)
	{
		if(E[i].contact_no==query)
		{
			index=i;
			break;
		}
	}
	return index;
}

void delete(int delete_index[50], int delete_counter,int index)
{
	delete_index[delete_counter]=index;
}

int main(void) {

	struct Employee E[50];
	int delete_index[50],delete_counter=0;

	int c=0,choice;
	long sea=0;
	int i;
	setbuf(stdout,NULL);
	setbuf(stdin,NULL);
	do
	{
		printf("\n\t--------Employee Portal--------\n\n");
		printf("\tPress 1 to Display all Records\n");
		printf("\tPress 2 to Add a record\n");
		printf("\tPress 3 to search for a Record\n");
		printf("\tPress 4 to modify a record\n");
		printf("\tPress 5 to delete a record\n");
		printf("\tPress 6 to Exit\n\t");
		fseek(stdin,0,SEEK_END);
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			if(c!=0)
			{
				printf("\t");
				for(i=0;i<65;i++)
				{
					printf("-");
				}
				printf("\n");
				printf("\t|Employee ID\t|Employee Name\t|Salary    \t|Contact Number |\n");
				for(i=0;i<c;i++)
				{
					int j;
					int flag=0;
					for(j=0;j<delete_counter;j++)
					{
						if(delete_index[j]==i)
						{
							flag=1;
							break;
						}
					}
					if(flag==0)
					{
						display(E[i]);
					}

				}
			}
			else
			{
				printf("\tPlease enter data first!\n");
			}

			break;

		case 2:
			if(c>=50)
			{
				printf("\tCannot Add,Memory Full\n");
			}
			else
			{
				if(delete_counter==0)
				{
					add(E,c,c);
					printf("\tRecord Added!\n");
					c++;
				}
				else
				{
					add(E,delete_index[delete_counter-1],c);
					delete_counter--;
					printf("\tRecord Added!\n");
				}

			}
			break;

		case 3:
			printf("\n\tWhat do you want to search for?\n");
			printf("\t1)Employee ID\n");
			printf("\t2)Contact Number\n\t");
			int ch;
			scanf("%d",&ch);
			switch(ch)
			{
			case 1:
				printf("\tEnter Employee ID:");
				int query;
				scanf("%d",&query);
				int flag;
				flag=search_id(E,c,query);
				if(flag!=-1)
				{
					printf("\t");
					for(i=0;i<65;i++)
					{
						printf("-");
					}
					printf("\n");
					printf("\t|Employee ID\t|Employee Name\t|Salary    \t|Contact Number  |\n");
					display(E[flag]);
					printf("\t");
					for(i=0;i<65;i++)
					{
						printf("-");
					}
					printf("\n");
				}
				else
				{
					printf("\tNo Such ID Exists");
				}
				break;

			case 2:
				printf("\tEnter Contact Number to be searched");
				scanf("%li",&sea);
				flag=search_contact(E,c,sea);
				if(flag!=-1)
				{
					printf("\t");
					for(i=0;i<65;i++)
					{
						printf("-");
					}
					printf("\n");
					printf("\t|Employee ID\t|Employee Name\t|Salary     \t|Contact Number  |\n");
					display(E[flag]);
					printf("\t");
					for(i=0;i<65;i++)
					{
						printf("-");
					}
					printf("\n");
				}
				else
				{
					printf("\tNo Such Contact number Exists");
				}
				break;

			default:
				printf("\tEnter Valid Choice");
			}
			break;

		case 4:
			printf("\n\tYou are now modifying an entry.\n");
			printf("\n\tWhat do you want to search for?\n");
			printf("\t1)Employee ID\n");
			printf("\t2)Contact Number\n\t");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					printf("\tEnter Employee ID:");
					int query;
					scanf("%d",&query);
					int flag;
					flag=search_id(E,c,query);
					if(flag!=-1)
					{
						modify(E,flag,c);
					}
					else
					{
						printf("\tNo Such ID Exists,Record Modification Failed");
					}
					break;

					case 2:
						printf("\tEnter Contact Number to be searched");
						scanf("%li",&sea);
						flag=search_contact(E,c,sea);
						if(flag!=-1)
						{
							modify(E,flag,c);
						}
						else
						{
							printf("\tNo Such Contact Number Exists,Record Modification Failed");
						}
						break;

						default:
							printf("\tEnter Valid Choice");
						}
			break;

		case 5:
			printf("\n\tYou are now modifying an entry.\n");
			printf("\n\tWhat do you want to search for?\n");
			printf("\t1)Employee ID\n");
			printf("\t2)Contact Number\n\t");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					printf("\tEnter Employee ID:");
					int query;
					scanf("%d",&query);
					int flag;
					flag=search_id(E,c,query);
					if(flag!=-1)
					{
						delete(delete_index,delete_counter,flag);
						delete_counter++;
						printf("\tRecord Deleted\n");
					}
					else
					{
						printf("\tNo Such ID Exists,Record Deletion Failed");
					}
					break;

				case 2:
					printf("\tEnter Contact Number to be searched");
					scanf("%li",&sea);
					flag=search_contact(E,c,sea);
					if(flag!=-1)
					{
						delete(delete_index,delete_counter,flag);
						delete_counter++;
						printf("\tRecord Deleted\n");
					}
					else
					{
						printf("\tNo Such Contact Number Exists,Record Deletion Failed");
					}
					break;

					default:
							printf("\tEnter Valid Choice");
						}
			break;

		case 6:
			break;

		default:
			printf("Enter Valid Option");

		}

	}
	while(choice!=6);

	return 1;
}

