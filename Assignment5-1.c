/*
 ============================================================================
 Name        : Database.c
 Author      : Atharva Joshi
 Version     :
 Copyright   : Your copyright notice
 Description : Implement the following data base operations
 	 	 	 1)Display
 	 	 	 2)Add
 	 	 	 3)Modify
 	 	 	 4)Search
 	 	 	 5)Delete

 ============================================================================


 */

#include <stdio.h>
#include <stdlib.h>
void append(char filename[],int id,char name[],char name2[],long phone,long sal){
	FILE *fp=NULL;
	fp=fopen(filename,"a");
	fprintf(fp," %d %s %s %ld %ld",id,name,name2,phone,sal); //Writing User Entered data into the file
	fclose(fp);
}

int search(char filename[],int search){
	FILE *fp1=NULL;
	fp1=fopen(filename,"r");
	if(fp1==NULL)
	{
		printf("File does not exist");
		return -2;
	}
	int n=1;
	while(!feof(fp1))//check for EOF
		{
			int id;
			char name1[20];
			char name2[20];
			long phone_no;
			long salary;
			fscanf(fp1,"%d",&id);
			if(id==search)//check whether id exists
			{
				fclose(fp1);
				return n;//returns the entry number of found record

			}
			fscanf(fp1,"%s%s%ld%ld",name1,name2,&phone_no,&salary);//taking file pointer ahead
			n++;
		}
	fclose(fp1);
	return -1;
}

int modify(char filename[],int n){

	FILE *fp1=NULL;//source file
	FILE *fp2=NULL;//destination file
	fp1=fopen(filename,"r");
	fp2=fopen("temp.txt","w");
	if(fp1==NULL)
		return 1;
	int c=1;
	while(!feof(fp1))//check for EOF
	{
		int id;
		char name1[20];
		char name2[20];
		name2[0]='\0';
		long phone_no;
		long salary;
		fscanf(fp1,"%d",&id);
		fscanf(fp1,"%s",name1);
		fscanf(fp1,"%s",name2);
		fscanf(fp1,"%ld",&phone_no);
		fscanf(fp1,"%ld",&salary);
		if(c==n)
		{
			printf("Enter New First Name:");
			while(getc(stdin)!='\n');
			gets(name1);
			printf("Enter New Second Name:");
			gets(name2);
			printf("Enter New Contact Number:");
			scanf("%ld",&phone_no);
			printf("Enter New Salary:");
			scanf("%ld",&salary);
			fprintf(fp2," %d %s %s %ld %ld",id,name1,name2,phone_no,salary);//writes new data into the file
		}
		else
		{
			fprintf(fp2," %d %s %s %ld %ld",id,name1,name2,phone_no,salary);//copies the same data
		}
		c++;
	}
	fclose(fp1);
	fclose(fp2);
	int check1=remove(filename);//deletes the original file
	int check2=rename("temp.txt",filename);//renames the temp file to the user entered fle name
	if(check1==0 && check2==0)
		return 0;
	else
		return 1;
}

int delete(char filename[],int n){

	FILE *fp1=NULL;//source file
	FILE *fp2=NULL;//destination file
	fp1=fopen(filename,"r");
	fp2=fopen("temp.txt","w");
	if(fp1==NULL)
		return 1;
	int c=1;
	while(!feof(fp1))
	{
		int id;
		char name1[20];
		char name2[20];
		name2[0]='\0';
		long phone_no;
		long salary;
		fscanf(fp1,"%d",&id);
		fscanf(fp1,"%s",name1);
		fscanf(fp1,"%s",name2);
		fscanf(fp1,"%ld",&phone_no);
		fscanf(fp1,"%ld",&salary);
		if(id!=n)//copies only when record number is not same otherwise it skips
		{
			fprintf(fp2," %d %s %s %ld %ld",id,name1,name2,phone_no,salary);
		}
		c++;
	}
	fclose(fp1);
	fclose(fp2);
	int check1=remove(filename);//deletes the old file
	int check2=rename("temp.txt",filename);//renames the updated file
	if(check1==0 && check2==0)//check whether operation is sucessful
		return 0;
	else
		return 1;
}

void displaytail()//display table structure
{
	int i;
	for(i=0;i<58;i++)
	{
		printf("-");
	}
	printf("\n");
}

void displaydata(char filename[],int n)//used to display single data
{
		FILE *fp1=NULL;
		fp1=fopen(filename,"r");
		if(fp1==NULL)
		{
			printf("File does not exist");
			return;
		}
		int c=1;
		while(!feof(fp1))
		{
			int id;
			char name1[20];
			char name2[20];
			name2[0]='\0';
			long phone_no;
			long salary;
			fscanf(fp1,"%d",&id);
			fscanf(fp1,"%s",name1);
			fscanf(fp1,"%s",name2);
			fscanf(fp1,"%ld",&phone_no);
			fscanf(fp1,"%ld",&salary);
			if(c==n)
			{
				printf("|%-11d|",id);
				printf("%-10s",name1);
				printf(" %-9s|",name2);
				printf("%-11ld|",phone_no);
				printf("%-10ld|\n",salary);
				fclose(fp1);
				displaytail();
				return;
			}
			c++;
		}
}

void displaydb(char filename[]){//used to display entire database
	FILE *fp1=NULL;
	fp1=fopen(filename,"r");
	if(fp1==NULL)
	{
		printf("File does not exist");
		return;
	}
	while(!feof(fp1))
	{
		int id;
		char name1[20];
		char name2[20];
		name2[0]='\0';
		long phone_no;
		long salary;
		fscanf(fp1,"%d",&id);
		fscanf(fp1,"%s",name1);
		fscanf(fp1,"%s",name2);
		fscanf(fp1,"%ld",&phone_no);
		fscanf(fp1,"%ld",&salary);
		printf("|%-11d|",id);
		printf("%-10s",name1);
		printf(" %-9s|",name2);
		printf("%-11ld|",phone_no);
		printf("%-10ld|\n",salary);
	}
	displaytail();

	fclose(fp1);

}

void displayhead()//displays table structure
{
	int i;
	for(i=0;i<58;i++)
	{
		printf("-");
	}
	printf("\n");
	printf("|Employee ID|Employee Name       |Contact    |Salary    |\n");

}

int main()
{
	char file[20];
	int choice,sea;
	char name[20];
	int id;
	int i;
	char name2[20];
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stdin,NULL,_IONBF,0);
	printf("Enter File Name:");
	gets(file);
	do
	{
		printf("\nWelcome to Database Operations\n");
		printf("Press 1 to display Database\n");
		printf("Press 2 to Add data to the file\n");
		printf("Press 3 to search for a perticular data on the file\n");
		printf("Press 4 to modify data on the file\n");
		printf("Press 5 to delete data on the file\n");
		printf("Press 6 to Exit Operation\n");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
			{
				case 1:
					displayhead();
					displaydb(file);
					break;

				case 2:
					printf("Enter data you want Add\n");
					long phone,salary;
					do
					{
						printf("Enter ID:");
						scanf("%d",&id);
						i=search(file,id);
						if(i==-1)
							break;
						else
							printf("Enter Unique ID\n");
					}
					while(1);
					printf("Enter Name:");
					while(getc(stdin)!='\n');
					gets(name);
					printf("Enter Surname:");
					gets(name2);
					printf("Enter Phone Number:");
					scanf("%ld",&phone);
					printf("Enter Salary:");
					scanf("%ld",&salary);
					append(file,id,name,name2,phone,salary);
					printf("\nData Added");
					break;

				case 3:
					printf("Enter Employee ID you want to search:");
					scanf("%d",&sea);
					int flag=search(file,sea);
					if(flag!=-1)
					{
						displayhead();
						displaydata(file,flag);
					}
					break;
				case 4:

					printf("Enter Employee ID you want to search:");
					scanf("%d",&sea);
					flag=search(file,sea);
					if(flag!=-1)
					{
						displayhead();
						displaydata(file,flag);
						int ch;
						do
						{
							printf("Do you want to Modify?(1-Yes 2-NO)");//confirming
							scanf("%d",&ch);
							if(ch==1)
							{
								i=modify(file,flag);
								break;
							}
							else
							{
								printf("Aborted\n");
								break;
							}
						}
						while(1);
						if(i==0)
							printf("Success");
						else
							printf("Failed");;
					}
					break;
				case 5:
					printf("Enter Employee ID you want to search:");
					scanf("%d",&sea);
					flag=search(file,sea);
					if(flag!=-1)
					{
						displayhead();
						displaydata(file,flag);
						int ch;
						do
						{
							printf("Do you want to Delete?(1-Yes 2-NO)");
							scanf("%d",&ch);
							if(ch==1)
							{
								i=delete(file,flag);
								break;
							}
							else
							{
								printf("Aborted\n");
								break;
							}
						}
						while(1);
						if(i==0)
							printf("Success");
						else
							printf("Failed");
					}
					break;
				case 6:
					break;
			}
	}
	while(choice!=6);
	printf("File operations Complete\n");
	return 0;
}


