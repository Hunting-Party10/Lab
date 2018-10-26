#include <stdio.h>
#include<stdlib.h>
#define size 50


typedef struct DoublyLinkedList
{
	struct DoublyLinkedList *next;
	struct DoublyLinkedList *prev;
	char data;
}DLL;

void Delete(DLL **head)
{
	while(*head != NULL)
	{
		DLL *t= *head;
		*head=(*head)->next;
		free(t);
	}
}

DLL* create()
{
	return malloc(sizeof(DLL));
}

int len(char data[])
{
	int i=0;
	while(data[i]!='\0')
		i++;
	return i;
}
DLL* buildList(char data[])
{
	DLL *head=create();
	head->prev=NULL;
	DLL *current=head;
	for (int i = 0; i < len(data); ++i)
	{
		current->data=data[i];
		current->next=create();
		DLL *t=current;
		current=current->next;
		current->prev=t;
	}
	DLL *t= current->prev;
	if(t == NULL)
	{
		free(head);
		return NULL;
	}
	else
	{
		t->next=NULL;
		free(current);
		return head;
	}
	
}

void Insert(DLL **head,int position,char Data)
{
	DLL *Node;
	Node=create();
	if(Node == NULL)
	{
		printf("Memory Allocation Failed\n");
		return;
	}
	Node->data=Data;
	Node->prev=NULL;
	if(*head == NULL)
	{
		Node->next = NULL;
		Node->prev = NULL;
		*(head) = Node;
	}
	else
	{
		if(position == 1)
		{
			Node->next = *head;
			(*head)->prev=Node;
			*head = Node;
			printf("Element Added\n\n");
		}
		else if(position == -1)
		{
			DLL *temp = *head;
			while(temp->next != NULL)
				temp=temp->next;
			temp->next = Node;
			Node->prev = temp;
			Node->next = NULL;
			printf("Element Added\n\n");
		}
		else
		{
			int count = 1;
			DLL *p = *head;
			while(p->next != NULL && count < position)
			{
				p = p->next;
				count++;
			}
			if(count == position)
			{
				p->prev->next=Node;
				Node->prev=p->prev;
				p->prev=Node;
				Node->next = p;
				printf("Element Added");
			}
			else
			{
				printf("String Does not Contain the given Position,Data Not Added\n\n");
				free(Node);
			}
		}
	}
}

void Display(DLL *str)
{
	if(str == NULL)
	{
		printf("No String Entered\n");
		return;
	}
	DLL *current=str;
	while(current != NULL)
	{
		printf("%c",current->data);
		current=current->next;
	}
	printf("\n");
}

void DisplayReverse(DLL *str)
{
	if(str == NULL)
	{
		printf("No String Entered\n");
		return;
	}
	DLL *current=str;
	while(current->next != NULL)
		current=current->next;
	while(current != NULL)
	{
		printf("%c",current->data);
		current=current->prev;
	}
	printf("\n");
}

void delete(DLL **head,char query)
{
	if(*head == NULL)
	{
		printf("No String Entered\n");
		return;
	}
	else
	{
		DLL *cur;
		if((*head)->data == query)
		{
			cur=*head;
			*head=(*head)->next;
			(*head)->prev=NULL;
			free(cur);
			return;
		}
		cur=*head;
		while(cur != NULL)
		{
			if(cur->data == query)
				break;
			cur=cur->next;
		}
		if(cur->data == query)
		{
			cur->prev->next=cur->next;
			free(cur);
			printf("Data Deleted\n");
		}
		else
		{
			printf("Data not found\n");
		}
	}
}

int main()
{
	int choice1,choice2,Position;
	char Data;
	char string[size];
	char temp;
	DLL *head=NULL;
	do
	{
		printf("\n\nPress 1 to Enter String\n");
		printf("Press 2 to Insert Character into the String\n");
		printf("Press 3 to Delete a Character\n");
		printf("Press 4 to Display\n");
		printf("Press 5 to Display in Reverse\n");
		printf("Press 6 to Exit\n");
		scanf("%d",&choice1);
		switch(choice1)
		{
			case 1:
				Delete(&head);
				printf("Enter a String:");
				scanf("%s",string);
				head=buildList(string);
				break;
			case 2:
				while(getc(stdin)!='\n');
				printf("Enter Data You want to add:");
				scanf("%c",&Data);
				printf("\n\nPress 1 to Add Element to the Begning of the String\n");
				printf("Press 2 to Add Element to the End of the String\n");
				printf("Press 3 to Add Element at a given Position of the String\n");
				printf("Press 4 to Abort\n");
				scanf("%d",&choice2);
				switch(choice2)
				{
					case 1:
						Insert(&head,1,Data);
						break;
					case 2:
						Insert(&head,-1,Data);
						break;
					case 3:
						printf("Enter Postion(Start 1) :");
						scanf("%d",&Position);
						Insert(&head,Position,Data);
						break;
					case 4:
						printf("Aborted\n");
						break;
					default:
						printf("Enter Valid Choice\n");
				}
				break;
			case 3:
				while(getc(stdin)!='\n');
				printf("Enter Data You want to Delete for:");
				scanf("%c",&Data);
				delete(&head,Data);
				break;
			case 4:
				Display(head);
				break;
			case 5:
				DisplayReverse(head);
				break;
			case 6:
				break;
			default:
				printf("Enter Valid Option\n");
		}
	}
	while(choice1 != 6);
	return 0;
}
