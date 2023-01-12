/*Labprogram 5

 Singly Linked List (SLL) of Integer Data
a. Create a SLL stack of N integer.
b. Display of SLL
c. Linear search.
d. Create a SLL queue of N Students Data
e. Concatenation of two SLL of integers

*/


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
NODE f, r, list1=NULL, list2=NULL;


//stack Operations
NODE Push(NODE, int);
NODE Pop(NODE, int *);
void DisplayStack(NODE);
void Search(NODE);

//Queue Operations
void enqueue(int);
int dequeue();
void DisplayQueue(NODE);

// Concatenation of two linked list operations
void Concat(NODE,NODE);
NODE Concatenate(NODE, NODE);
void DisplayConcatenatedList(NODE);


int main()
{

    int choice;
    while(1)
    {
    	printf("1. SLLStack\n");
        printf("2. SLLQueue\n");
        printf("3. ConcatenateLists\n");
        printf("4. Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
			case 1: SLLStack();
					break;
			case 2: SLLQueue();
					break;
			case 3: Concat(list1, list2);
					break;
			case 4: exit(0);
					break;
			default: printf("Please enter a valid choice\n");
        }
    }
    return 0;

}

void  SLLStack()
{
	int item, choice=0;
	int d;
	NODE first;
	first = NULL;



    printf("\n----------------------------------------------\n");
    while(choice != 5)
    {
        printf("\n\nSTACK OPERATIONS USING LINKED LIST\n");
        printf("\n1.Push\n2.Pop\n3.DisplayStack\n4.Search\n5.Exit");
        printf("\n Enter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter element to push: ");
					scanf("%d", &item);
					first = Push(first, item);
					break;

            case 2:first = Pop(first, &d);
					if (d == -1)
						printf("Stack Underflow\n");
					else
						printf("Popped element = %d\n", d);
            	    break;

            case 3:DisplayStack(first);
                   break;
            case 4:Search(first);
                   break;
            case 5:printf("Exit\n");
					break;

            default:printf("Please Enter valid choice ");
					break;

        }
    }
}


NODE Push(NODE first, int item)
{
	NODE q;
	MALLOC(q, sizeof(struct List), NODE);
	q->info = item;
	q->next = first;
	first = q;
	return first;
}

NODE Pop(NODE first, int *item)
{
	if (first == NULL)
		*item = -1;
	else
	{
		*item = first->info;
		first = first->next;
	}
	return first;
}

void DisplayStack(NODE first)
{
	if(first==NULL)
	{
		printf("Stack is Empty\n");

	}
	else
	{
		printf("The Stack elements are: \n");
		while (first != NULL)
		{
			printf("%d ", first->info);
			first = first->next;
		}
	}
}


void Search(NODE first)
{
    int item,i=0;
    int flag=0;
    if(first == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d",&item);
        while (first->next!=NULL)
        {
            if(first->info==item)
            {

                printf("Item found at location %d \n",i+1);
                flag=1;
            }
            i++;
            first=first->next;

        }
       if(first->next==NULL && first->info==item)
    	   printf("Item found at location %d \n",i+1);

       if(flag==0)
       {

    	   printf("Item not found\n");
       }
    }
}

void SLLQueue()
{
    int choice,item;
    f=r=NULL;
    while(choice != 4)
    {

        printf("\nQUEUE OPERATIONS USING LINKED LIST\n");
        printf("\n----------------------------------------------\n");
        printf("\n1.Enqueue\n2.Dequeue\n3.DisplayQueue\n4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element: ");
					scanf("%d", &item);
					enqueue(item);
					break;

            case 2:item = dequeue();
				if (item == -1)
					printf("Queue Empty\n");
				else
					printf("Deleted element is: %d\n", item);
				break;

            case 3:DisplayQueue(f);
					break;
            case 4:printf("Exit....\n");
            	   break;

            default:printf("Please Enter valid choice: ");
					break;
         }
    }
}

void enqueue(int item)
{
	NODE q;
	MALLOC(q, sizeof(struct List), NODE);
	q->info = item;
	q->next = NULL;
	if (f == NULL)
		f = r = q;
	else
	{
		r->next = q;
		r = q;
	}
}

int dequeue()
{
	int item;
	if (f == NULL)
		item = -1;
	else
	{
		item = f->info;
		f = f->next;
	}
	return item;
}

void DisplayQueue(NODE f)
{
	if(f==NULL)
	{
		printf("Empty Queue\n");
	}
	else
	{
		while (f != NULL)
		{
			printf("%d ", f->info);
			f = f->next;
		}
		printf("\n");
	}
}



void DisplayConcatenatedList(NODE list1)
{
	NODE first;
	        if(list1==NULL)
	        {
	                printf("\nList is empty\n");
	                return;
	        }
	        first=list1;
	        while(first!=NULL)
	        {
	                printf("%d ", first->info);
	                first=first->next;
	        }
	        printf("\n");
}


NODE Concatenate(NODE list1, NODE list2)
{

	NODE first=NULL;
	        if(list1==NULL)
	        {
	                list1=list2;
	                return list1;
	        }
	        if(list2==NULL)
	                return list1;
	        first=list1;
	        while(first->next!=NULL)
	                first=first->next;
	        first->next=list2;
	        return list1;
}



void Concat(NODE list1, NODE list2)
{
    NODE first,q;
    first=NULL;
    int n,i;
    printf ("Number of elements in list1:");
    scanf("%d",&n);
    if(n!=0)
    {
		printf("Enter the elements:\n");
		for(i=0;i<n;i++)
		{
			MALLOC(q, sizeof(struct List), NODE);
			scanf("%d",&q->info);
			q->next=NULL;
			if(list1==NULL)
				list1=q;
			else
				first->next=q;
			first=q;
		}
	}

    printf ("Number of elements in list2:");
    scanf("%d",&n);
    if(n!=0)
    {
		printf("Enter the elements:\n");
		for(i=0;i<n;i++)
		{
			MALLOC(q, sizeof(struct List), NODE);
			scanf("%d",&q->info);
			q->next=NULL;
			if(list2==NULL)
				list2=q;
			else
				first->next=q;
		    first=q;
		}
    }

       list1 = Concatenate(list1,list2);

       printf("\nConcatenated Linked List is: \n");
       DisplayConcatenatedList(list1);

}
