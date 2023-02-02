// Header Circular Linked list

#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>


#define MALLOC(p,s,t) \
if (!((p) = (t) malloc(s))) {\
fprintf(stderr, "Insufficient Memory\n"); \
exit(EXIT_FAILURE); \
}

struct List
{
	int info;
	struct List *next;
};

typedef struct List *NODE;
int count = 0;
NODE InsertFront(NODE, int);
NODE InsertRear(NODE, int);

NODE DeleteFront(NODE);
NODE DeleteRear(NODE);

void Display(NODE);


void main()
{
	int item, choice, done;
	NODE head;
	MALLOC(head, sizeof(struct List), NODE);
	head->info = 0;
	head->next=head;
	done = 0;
	while (!done)
	{
		printf("\nHEADER CIRCULAR LINKED LIST OPERATIONS\n");
		printf("\n1.InsertFront\n2.InsertRear\n");
		printf("3.DeleteFront\n4.DeleteRear\n");
		printf("5.Display\n6.Exit\n");
		printf("Enter Choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1: printf("Enter the element to be inserted: ");
					scanf("%d", &item);
					head = InsertFront(head, item);
					break;

			case 2:	printf("Enter the element to be inserted: ");
					scanf("%d", &item);
					head=InsertRear(head,item);
					break;

			case 3: head = DeleteFront(head);
					break;
			case 4: head=DeleteRear(head);
					break;

			case 5:	Display(head);
					break;
			case 6: done = 1;
					break;
			default:printf("Enter a valid Choice\n");
					break;
		}
	}
}

NODE InsertFront(NODE head, int item)
{
	NODE q, first;
	MALLOC(q, sizeof(struct List), NODE);
	q->info = item;
	if(head->next==head)
	{
		q->next=head->next;
		head->next=q;
	}
	else
	{
	    first=head->next;
	    head->next=q;
	    q->next=first;
	}
	head->info=++count;
	return head;

}

NODE InsertRear(NODE head, int item)
{
	NODE q,cur;
	MALLOC(q, sizeof(struct List), NODE);
	q->info = item;
	if(head->next==head)
	{
		q->next=head->next;
		head->next=q;

	}
	else
	{
	    cur=head->next;
	    while(cur->next!=head)
	    {
	    	cur=cur->next;
	    }
	    cur->next=q;
	    q->next=head;
	}
	head->info=++count;
	return head;

}

NODE DeleteFront(NODE head)
{
	NODE first;

	if(head->next==head)
	{
		printf("list is empty\n");
	    return head;
	}
	first=head->next;
	printf("the deleted item is:%d\n",first->info);
   	head->next=first->next;
              head->info=--count;
	free(first);
	return head;
}


NODE DeleteRear(NODE head)
{
	NODE prev,cur;
	if(head->next==head)
	{
		printf("list is empty\n");
		return head;
	}
	cur=head->next;
	prev=head;
	while(cur->next!=head)
	{
		prev=cur;
		cur=cur->next;
	}
	prev->next=head;
	printf("The deleted item is:%d\n", cur->info);
	head->info=--count;
	free(cur);
	return head;
}

void Display(NODE head)
{

	NODE first;
	if(head->next==head)
	{
		printf("List is Empty\n");
		return ;
	}
	first=head->next;
	printf("The contents of header circular linked list is: \n");
	while(first!=head)
	{
		printf("|%d|%d|-->",first->info, first->next);
	    first=first->next;
	}
	printf("\nThe number of nodes in the list: %d", head->info);
	printf("\n");

}
