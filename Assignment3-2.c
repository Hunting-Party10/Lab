/*
 ============================================================================
 Name        : Stringptr.c
 Author      : Atharva Joshi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define max 50

void accept(char *str)
{
	fseek(stdin,0,SEEK_END);
	scanf("%s",str);
}

void display(char *str)
{
	fseek(stdin,0,SEEK_END);
	printf("%s\n",str);
}

int length(char *str)
{
		int l=0;
		int i=0;
		while(*(str+i)!='\0')
		{
			l++;
			i++;
		}
		return l;

}

void reverse(char *str,char *pal,int l)
{
	int i,j=l-1;
	for(i=0;i<l;i++)
	{
		*(pal+i)=*(str+j);
		j--;
	}
}

int cmp(char *str1,char *str2,int l1,int l2)
{
	if(l1!=l2)
	{
		return -1;
	}
	int i;
	for(i=0;i<l1;i++)
	{
		if(*(str1+i)!=*(str2+i))
		{
			return -1;
		}
	}
	return 0;
}

void copy(char *str,char *pal,int l)
{
	int i;
	for(i=0;i<l;i++)
	{
		*(pal+i)=*(str+i);

	}
}

int substring(char *str,char *sub,int length,int subl)
{
	int i,k=0;
		int counter=0;
		for(i=0;i<length;i++)
		{
			k=i;
			int j=0;
			while(k<=length)
			{
				if(j==subl)
				{
					counter++;
					break;
				}
				if(str[k++]!=sub[j++])
				{
					break;
				}
			}
		}
		return counter;
}

int main(void) {
	int l1,l2,choice;
	char *str,*pal,*sub;
	int c=0;
	do
		{
			l1=0;
			l2=0;

			printf("\n\nString Operations \n \n");
			printf("1)Enter String\n");
			printf("2)Display String\n");
			printf("3)Length\n");
			printf("4)Pallindrome\n");
			printf("5)String compare\n");
			printf("6)Reverse\n");
			printf("7)Copy\n");
			printf("8)Substring\n");
			printf("9)Exit\n");
			fseek(stdin,0,SEEK_END);
			scanf("%d",&choice);
			switch(choice)
				{
					case 1:
						printf("Enter String of Max 50 Characters\n");
						str=(char *)malloc(50*sizeof(char));
						scanf("%s",str);
						c++;
						break;

					case 2:
						if(c==0)
						{
							printf("Please Enter a string");
							break;
						}
						printf("String is:");
						display(str);
						break;

					case 3:
						if(c==0)
						{
							printf("Please Enter a string\n");
							break;
						}
						l1=length(str);
						printf("Length of the String is:%d\n",l1);
						break;

					case 4:
						if(c==0)
						{
							printf("Please Enter a string\n");
							break;
						}
						printf("String is:");
						display(str);
						l1=length(str);
						pal=(char *)malloc(l1*sizeof(char));
						reverse(str,pal,l1);
						int flag=cmp(str,pal,l1,l1);
						if(flag==0)
						{
							printf("Strings are the Palindrome\n");
						}
						else
						{
							printf("Strings are not Palindrome\n");
						}
						free(pal);
						break;

					case 5:
						if(c==0)
						{
							printf("Please Enter a string");
							break;
						}
						printf("String is:");
						display(str);
						printf("Enter String you want to compare with\n");
						pal=(char *)malloc(max*sizeof(char));
						scanf("%s",pal);
						l1=length(str);
						l2=length(pal);
						flag=cmp(str,pal,l1,l2);
						if(flag==0)
						{
							printf("Strings are the same\n");
						}
						else
						{
							printf("Strings are not same\n");
						}
						free(pal);
						break;

					case 6:
						if(c==0)
						{
							printf("Please Enter a string\n");
							break;
						}
						printf("Original String is:");
						display(str);
						l1=length(str);
						pal=(char *)malloc(l1*sizeof(char));
						reverse(str,pal,l1);
						printf("Reverse String is:");
						display(pal);
						free(pal);
						break;

					case 7:
						if(c==0)
						{
							printf("Please Enter a string\n");
							break;
						}
						printf("\nOriginal String is:");
						display(str);
						l1=length(str);
						pal=(char *)malloc(l1*sizeof(char));
						copy(str,pal,l1);
						printf("\nCopied String is: %s",pal);
						free(pal);
						break;

					case 8:
						if(c==0)
						{
							printf("Please Enter a string");
							break;
						}
						printf("Original String is:");
						display(str);
						printf("Enter Substring:");
						sub=(char *)malloc(50*sizeof(char));	
						accept(sub);
						int sl;
						sl=length(sub);
						int l1=length(str);
						if(sl>l1)
						{
							printf("Substring Length cannot exceed String length");
							break;
						}
						int counter;												
						counter=substring(str,sub,l1,sl);
						printf("Substring was found %d times\n",counter);
						free(sub);
						break;

					case 9:
						break;

					default:
						printf("Enter Valid Option");
				}
			}
	while(choice!=9);
	return 0;
}
