#include<stdio.h>
#include<string.h>
#define size 5

typedef struct GLL
{
	int flag;
	struct GLL *next;
	union inside
	{
		char data[size];
		struct GLL *inhead;
	}u;
}Node;


void deleteall(Node *head)
{
	Node *temp = head;
	while(temp != NULL)
	{
		if(temp->flag == 1)
			deleteall(temp->u.inhead);
		free(temp);
		temp = temp->next;
	}
}

Node* getnode()
{
	Node *new=(Node *)malloc(sizeof(Node));
	new->next=NULL;
	new->u.inhead=NULL;
	return new;
}

Node* create(Node *head,char str[])
{
	int i,j;
	Node *temp;
	for(i=0;str[i]!='\0';)
	{
		if(str[i]=='(' && i==0)
		{
			head=getnode();
			temp=head;
		}
		else
		{
			temp->next=getnode();
			temp=temp->next;
		}
		i++;
		j=0;
		while(str[i]!=',' && str[i]!='(' && str[i]!=')')
		{
			temp->u.data[j]=str[i];
			i++;
			j++;
		}
		temp->u.data[j]='\0';
		temp->flag=0;
		if(str[i]==('('))
		{
			temp->next=getnode();
			temp=temp->next;
			temp->flag=1;
			temp->u.inhead=create(NULL,&str[i]);
			while(str[i]!=')')
				i++;
			i++;
		}
		if(str[i]==')')
			return head;
	}
	return NULL;
}

void display(Node *temp)
{
	static int depth;
	depth++;
	int i;
	if(temp == NULL)
	{
		if(depth == 1)
		{
			printf("List is empty");
		}
		else
		{
			printf("Sublist is empty");
		}
	}
	else
	{
		while(temp != NULL)
		{
			if(temp->flag==0)
			{
				printf("\n");
				for(i=1;i<=depth;i++)
					printf("    ");
				printf("-%s",temp->u.data);
			}
			else
				display(temp->u.inhead);
			temp=temp->next;

		}
		depth--;
	}
}

int main()
{
	Node *head=NULL;
	int choice;
	char input[50];
	do
	{
		printf("\n\nPress 1 to Build Index\n");
		printf("Press 2 to Display Index\n");
		printf("Press 3 to Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				deleteall(head);
				printf("Enter Index of Book eg(1(1,2)2(1))");
				while(getc(stdin)!='\n');
				gets(input);
				head=create(head,input);
				break;
			case 2:
				if(input[0]!='(')
				{
					printf("Input Not Formated Properly");
					break;
				}
				display(head);
				break;
			case 3:
				break;
			default:
				printf("Please Enter Valid Option");
		}
	}
	while(choice != 3);
	return 0;
}


