/*
Author-Atharva Joshi
Roll Number-23306

Problem Statement
Create a Singly Linked List
1)Insert
2)Display
3)Display
4)Display in Reverse
5)Revert(SLL w/o addn DS)
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct LinkedList
{
	int Data;
	struct LinkedList *next;
}LinkedList;

void Insert(LinkedList **head,int position,int Data)
{
	LinkedList *Node;
	Node=(LinkedList *)malloc(sizeof(LinkedList));
	if(Node == NULL)
	{
		printf("Memory Allocation Failed\n");
		return;
	}
	Node->Data=Data;
	if(*head == NULL)
	{
		Node->next = NULL;
		*head = Node;
	}
	else
	{
		if(position == 1)
		{
			Node->next = *head;
			*head = Node;
			printf("Element Added\n\n");
		}
		else if(position == -1)
		{
			LinkedList *temp = *head;
			while(temp->next != NULL)
				temp=temp->next;
			temp->next = Node;
			Node->next = NULL;
			printf("Element Added\n\n");
		}
		else
		{
			int count = 1;
			LinkedList *p = *head;
			LinkedList *q;
			while(p->next != NULL && count < position)
			{
				q = p;
				p = p->next;
				count++;
			}
			if(count == position)
			{
				Node->next = p;
				q->next = Node;
				printf("Element Added");
			}
			else
			{
				printf("List Does not Contain the given Position,Data Not Added\n\n");
				free(Node);
			}
		}
	}
}

void displayList(LinkedList **head)
{
	if(*head == NULL)
	{
		printf("List Empty\n");
	}
	else
	{
		printf("[");
		LinkedList *temp = *head;
		while(temp != NULL)
		{
			printf("%d ",temp->Data);
			temp = temp->next;
		}
		printf("]\n");
	}

}

void Delete(LinkedList **head,int position)
{
	if(*head == NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		if(position == 1)
		{
			LinkedList *p = *head;
			*head = p->next;
			p->next = NULL;
			free(p);
			printf("Data Deleted\n");
		}
		else if(position == -1)
		{
			LinkedList *p = *head;
			LinkedList *q;
			while(p->next != NULL)
			{
				q = p;
				p = p->next;
			}
			q->next = NULL;
			free(p);
			printf("Data Deleted\n");
		}
		else
		{
			int count = 1;
			LinkedList *p = *head;
			LinkedList *q;
			while(p->next != NULL && count < position)
			{
				q = p;
				p = p->next;
				count++;
			}
			if(count == position)
			{
				q->next = p->next;
				p->next = NULL;
				free(p);
				printf("Data Deleted\n");
			}
			else
				printf("List Does not Contain the given Position,Data Not Deleted\n");
		}
	}
}



void deleteAll(LinkedList **rHead)
{
	LinkedList *temp = *rHead;
	while(temp != NULL)
	{
		LinkedList *temp1=temp;
		temp=temp->next;
		free(temp1);
	}
	*rHead = NULL;
}

void Revert(LinkedList **head)
{
	if(*head==NULL)
	{
		*head = NULL;
	}
	else
	{
		LinkedList *temp = *head;
		LinkedList *Node;
		LinkedList *rhead;
		Node=(LinkedList *)malloc(sizeof(LinkedList));
		Node->Data = temp->Data;
		Node->next = NULL;
		rhead = Node;
		while(temp->next != NULL)
		{
			temp=temp->next;
			Node=(LinkedList *)malloc(sizeof(LinkedList));
			Node->Data = temp->Data;
			Node->next = rhead;
			rhead=Node;
		}
		temp=*head;
		*head = rhead;
		deleteAll(&temp);

	}
}

void displayrev(LinkedList *head)
{
	if(head !=NULL)
	{
		displayrev(head->next);
		printf("%d ",head->Data);
	}
}

int main(void) {
	LinkedList *Head=NULL;
	int choice1,choice2,Data,Position;
	do
	{
		printf("\n\nPress 1 to Insert an Element to the List\n");
		printf("Press 2 to Display the List\n");
		printf("Press 3 to Delete An Element from the List\n");
		printf("Press 4 to Reverse the List\n");
		printf("Press 5 to display Reverse\n");
		printf("Press 6 to Exit\n");
		scanf("%d",&choice1);
		switch(choice1)
		{
			case 1:
				printf("Enter Data You want to add:");
				scanf("%d",&Data);
				printf("\n\nPress 1 to Add Element to the Begning of the List\n");
				printf("Press 2 to Add Element to the End of the List\n");
				printf("Press 3 to Add Element at a given Position of the List\n");
				printf("Press 4 to Abort\n");
				scanf("%d",&choice2);
				switch(choice2)
				{
					case 1:
						Insert(&Head,1,Data);
						break;
					case 2:
						Insert(&Head,-1,Data);
						break;
					case 3:
						printf("Enter Postion(Start 1) :");
						scanf("%d",&Position);
						Insert(&Head,Position,Data);
						break;
					case 4:
						printf("Aborted\n");
						break;
					default:
						printf("Enter Valid Choice\n");
				}
				break;
			case 2:
				displayList(&Head);
				break;


			case 3:
				printf("\n\nPress 1 to Delete an Element at the Begning of the List\n");
				printf("Press 2 to Delete an Element at the End of the List\n");
				printf("Press 3 to Delete an Element at a given Position of the List\n");
				printf("Press 4 to Abort\n");
				scanf("%d",&choice2);
				switch(choice2)
				{
					case 1:
						Delete(&Head,1);
						break;
					case 2:
						Delete(&Head,-1);
						break;
					case 3:
						printf("Enter Postion(Start 1) :");
						scanf("%d",&Position);
						Delete(&Head,Position);
						break;
					case 4:
						printf("Aborted\n");
						break;
					default:
						printf("Enter Valid Choice\n");
				}
				break;

			case 4:
				printf("Reversing the List\n");
				Revert(&Head);
				break;
			case 5:
				printf("Displaying Reversed List\n");
				printf("[");
				displayrev(Head);
				printf("]");
				break;
			case 6:
				break;
			default:
				printf("Enter Valid Choice\n");
		}
	}
	while(choice1!=6);
	return 0;
}

