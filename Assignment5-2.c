/*
 ============================================================================
 Name        : File.c
 Author      : Atharva Joshi
 Version     :
 Copyright   : Your copyright notice
 Description :Implement TYPE and COPY commands using command line arguments
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void display(char filename[]){

	FILE *fp1=NULL;

	fp1=fopen(filename,"r");
	char ch=getc(fp1);
	while(!feof(fp1))
	{
		printf("%c",ch);
		ch=getc(fp1);
	}

	fclose(fp1);
	printf("\n");
}

int main(int argc,char *argv[]) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stdin,NULL,_IONBF,0);
	FILE *fp1=NULL;
	FILE *fp2=NULL;
	char ch;
	char cmd1[]="TYPE";
	char cmd2[]="COPY";
	switch(argc)
	{

	case 3:
		if(!strcmp(argv[1],cmd1))
		{
			fp1=fopen(argv[2],"r");
			if(fp1==NULL)
			{
				printf("File specified %s does not exist\n",argv[2]);
				return -1;
			}
			fclose(fp1);
			display(argv[2]);
			printf("File Read\nExiting Program\n");
			return 0;
		}
		else
		{
			printf("Invalid Command used\n");
		}


		break;

	case 4:
		if(!strcmp(argv[1],cmd2))
		{
			fp1=fopen(argv[2],"r");
			fp2=fopen(argv[3],"w");
			if(fp1==NULL)
			{
				printf("File specified %s does not exist\n",argv[2]);
				return -1;
			}
			ch=getc(fp1);
			while(!feof(fp1))
			{
				fputc(ch,fp2);
				ch=getc(fp1);
			}
			printf("Coyping Complete\nExiting Program\n");
			fclose(fp1);
			fclose(fp2);
			return 0;
		}
		else
		{
			printf("Invalid command used\n");
		}
		break;

	default:
		printf("Invalid Command Passed\n");
		return -1;
	}
	return 0;
}
