#include<stdio.h>
#include<stdlib.h>
typedef struct GeneralizedLinkedList
{
	int flag_bit;
	union inside
	{
		int index;
		struct GeneralizedLinkedList *in;
	}u;
	struct GeneralizedLinkedList *next;
}Node;

void deleteAll(Node *head)
{
	Node *current=head;
	while(current!=NULL)
	{
		if(current->flag_bit == 1)
		{
			deleteAll(current->u.in);
		}
		Node *t = current;
		current=current->next;
		free(t);
	}
}


Node* buildIndex(int chapters)
{
	int i;
	static int depth=0;
	Node *tempHead,*current;
	for (i = 1; i <= chapters; ++i)
	{
		int sub;
		if (i==1)
		{
			tempHead=(Node *)malloc(sizeof(Node));
			current=tempHead;
			current->next = NULL;
		}
		else{
			current->next=(Node *)malloc(sizeof(Node));
			current=current->next;
			current->next = NULL;
		}
		do
		{
			printf("Enter Number of Sub-Chapters for Chapter - %d (Press 1 if No Sub Chapter)(Recurrsion Level:%d):",i,depth+1);
			scanf("%d",&sub);
			if(sub < 1)
				printf("Please Enter Again!\n");
		}
		while(sub<1);
		if (sub == 1)
		{
			current->flag_bit = 0;
			current->u.index = i;
		}
		else
		{
			current->flag_bit = 1;
			depth++;
			current->u.in=buildIndex(sub);
			depth--;
		}
	}
	return tempHead;
}

void displayIndex(Node *head)
{
	static int depth;
	Node *current=head;
	int count=1;
	while(current != NULL)
	{
		for (int i = 0; i < depth; ++i)
				printf("\t");
		if (current->flag_bit == 0)
			printf("-%d\n",current->u.index);
		else
		{
			depth++;
			printf("-%d\n",count);
			displayIndex(current->u.in);
			depth--;
		}
		current=current->next;
		count++;
	}
}

int main()
{
	int choice,chapters;
	Node *head=NULL;
	do
	{
		printf("\n\nPress 1 to Build Index\n");
		printf("Press 2 to Display Index\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				deleteAll(head);
				printf("Enter Number of Main Chapters:");
				scanf("%d",&chapters);
				if(chapters>0)
					head=buildIndex(chapters);
				else
					printf("Enter Valid Number of Chapter\n");
				break;
			case 2:
				printf("\n\n");
				displayIndex(head);
				break;
			case 3:
				break;
			default:
				printf("Enter Valid Value\n");
		}
	}
	while(choice!=3);
}