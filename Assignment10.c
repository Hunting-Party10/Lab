/*
Author-Atharva Joshi
Roll Number-23306

Problem Statement
Use CLL and perform
1)Addition of Polynomials
2)Multiplication of POlynomials
3)Evaluation of Polynomials
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct CircularLinkedList
{
	int Coefficient;
	int power;
	struct CircularLinkedList *next;
}CLL;

void deleteAll(CLL **head)
{
	if(*head !=NULL)
	{
		CLL *temp = (*head)->next;
		while(temp!=*head)
		{
			CLL *t = temp;
			temp = temp->next;
			free(t);
		}
		free(*head);

	}
	*head=NULL;
}

void buildpoly(CLL **head)
{
	int coeff,power;
	printf("Enter Power of the Highest Term:");
	scanf("%d",&power);
	if(power>=0)
	{
		printf("Enter Coefficient of x^%d :",power);
		scanf("%d",&coeff);
		*head=(CLL *)malloc(sizeof(CLL));
		(*head)->power=power;
		(*head)->Coefficient=coeff;
		(*head)->next=NULL;
		power--;
		while(power>=0)
		{
			printf("Enter Coefficient of x^%d :",power);
			scanf("%d",&coeff);
			if(coeff != 0)
			{
				CLL *temp = *head;
				while(temp->next != NULL)
					temp=temp->next;
				temp->next = (CLL *)malloc(sizeof(CLL));
				(temp->next)->power = power;
				(temp->next)->Coefficient = coeff;
				(temp->next)->next = NULL;
			}
			power--;
		}
		if((*head)->next != NULL)
		{
			CLL *last = (*head)->next;
			while(last->next != NULL)
				last = last->next;
			last->next = *head;
		}
		else
			(*head)->next=*head;
	}
	else
		printf("Please Enter Valid Power");
}

void displaypoly(CLL *head)
{
	if(head == NULL)
		printf("No Polynomial Exists\n");
	else
	{
		CLL *t=head;
		do
		{
			if(t->Coefficient>=0)
				printf("+%d",t->Coefficient);
			else
				printf("%d",t->Coefficient);
			if (t->power !=0)
			{
				printf("x^%d ",t->power );
			}
			t=t->next;
		}
		while(t != head);
		printf("\n");
	}
}

CLL* addition(CLL *poly1,CLL *poly2)
{
	if(poly1 == NULL || poly2 == NULL )
			printf("No Polynomial Exists\n");
	else
	{
		CLL *p1=poly1;
		CLL *temp=(CLL *)malloc(sizeof(CLL));
		CLL *rhead=temp;
		CLL *p;
		do
			{
				temp->power=p1->power;
				temp->Coefficient=p1->Coefficient;
				temp->next=(CLL *)malloc(sizeof(CLL));
				p=temp;
				temp=temp->next;
				p1=p1->next;
			} while (p1 != poly1);
		p->next=rhead;
		free(temp);	
		temp=NULL;
		CLL *p2=poly2;
		p=NULL;
		do
		{
			int coeff= p2->Coefficient;
			int power=p2->power;
			if(power > rhead->power)
			{
				CLL *trav=rhead;
				while(trav->next != rhead)
					trav=trav->next;
				temp=(CLL *)malloc(sizeof(CLL));
				temp->power=power;
				temp->Coefficient=coeff;
				trav->next=temp;
				temp->next=rhead;
				rhead=temp;
			}
			else
			{
				CLL *t=rhead;
				do
				{
					if(t->power > power)
					{
						p=t;
						t=t->next;
					}
					else if(t->power == power)
					{
						t->Coefficient+=coeff;
						break;
					}
					else
					{
						temp=(CLL *)malloc(sizeof(CLL));
						temp->power=power;
						temp->Coefficient=coeff;
						p->next=temp;
						temp->next=t;
						break;
					}
				}
				while(t != rhead);
			}
			p2=p2->next;
		}while(p2 != poly2);
		return rhead;
	}
}

CLL* multiplication(CLL *poly1,CLL *poly2)
{
	if(poly1 == NULL || poly2 == NULL )
		printf("No Polynomial Exists\n");
	else
	{
		CLL *finalans=(CLL *)malloc(sizeof(CLL));
		finalans->next=finalans;
		finalans->power=0;
		finalans->Coefficient=0;
		CLL *p1=poly1;
		do
		{
			int power=p1->power;
			int coeff=p1->Coefficient;
			CLL *tempans1=(CLL *)malloc(sizeof(CLL));
			CLL *t1=tempans1;
			CLL *p=NULL;
			CLL *p2=poly2;
			do
			{
				t1->power = p2->power + power;
				t1->Coefficient = p2->Coefficient * coeff;
				t1->next=(CLL *)malloc(sizeof(CLL));
				p=t1;
				t1=t1->next;	
				p2=p2->next;
			}
			while(p2 != poly2);
			p->next=tempans1;
			free(t1);
			CLL *tempans2=finalans;
			finalans=addition(tempans1,tempans2);
			deleteAll(&tempans1);
			deleteAll(&tempans2);
			p1=p1->next;
		}
		while(p1 != poly1);
		return finalans;
	}
	
}

int Evaluate(CLL *poly, int x)
{
	if(poly == NULL)
	{
		printf("No Polynomial Exists\n");
		return 0;
	}
	int ans=0;
	CLL *current= poly;
	do
	{
		ans+=(current->Coefficient)*pow(x,current->power);
		current=current->next;
	}
	while( current != poly);
	return ans;
}

int main(void) {
	int choice;
	int x,ans;
	CLL *poly1=NULL,*poly2=NULL,*result=NULL;
	do
	{
		printf("\n\nPress 1 to Enter Polynomial\n");
		printf("Press 2 to Display Polynomials\n");
		printf("Press 3 to Perform Addition of Polynomial\n");
		printf("Press 4 to Perform Multiplication of Polynomial\n");
		printf("Press 5 to Evaluate Polynomials\n");
		printf("Press 6 to Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				deleteAll(&poly1);
				deleteAll(&poly2);
				printf("Enter Polinomial 1\n");
				buildpoly(&poly1);
				printf("\nEnter Polinomial 2\n");
				buildpoly(&poly2);
				break;
			case 2:
				printf("Polynomial 1: ");
				displaypoly(poly1);
				printf("Polynomial 2: ");
				displaypoly(poly2);
				break;
			case 3:
				deleteAll(&result);
				printf("Polynomial 1: ");
				displaypoly(poly1);
				printf("Polynomial 2: ");
				displaypoly(poly2);
				printf("Addition is:\n");
				result=addition(poly1,poly2);
				displaypoly(result);
				break;
			case 4:
				deleteAll(&result);
				printf("Polynomial 1: ");
				displaypoly(poly1);
				printf("Polynomial 2: ");
				displaypoly(poly2);
				printf("Multiplication is:\n");
				result=multiplication(poly1,poly2);
				displaypoly(result);
				break;
			case 5:
				printf("Enter Value of x :");
				scanf("%d",&x);
				printf("Polynomial 1: ");
				displaypoly(poly1);
				ans=Evaluate(poly1,x);
				printf("Evaluation = %d\n",ans );
				printf("Polynomial 2: ");
				displaypoly(poly2);
				ans=Evaluate(poly2,x);
				printf("Evaluation = %d\n",ans );
				break;
			case 6:
				break;
			default:
				printf("Enter Valid Option\n");

		}
	}
	while(choice != 6);
	return 0;
}

