#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 30

#define MALLOC(p,s,t) \
if (!((p) = (t) malloc(s))) {\
fprintf(stderr, "Insufficient Memory\n"); \
exit(EXIT_FAILURE); \
}

//ID, Name, Branch, Area of specialization
struct List
{
    int ID;
    char Name[MAX];
    char Branch[MAX];
    char Specialization[MAX];
    struct List* next;
    struct List* prev;
}*top;

typedef struct List* NODE;
NODE front, rear;

//Stack Operations
void DLLStack();
NODE Push(NODE);
NODE Pop();
void DisplayStack(NODE);

//Queue Operations
void DLLQueue();
NODE InsRear  (NODE);
NODE DelFront (NODE);
void DisplayQueue(NODE);

// global variables to key in professor details
int  id;			// Professor id
char name[MAX];		// Professor name
char branch[MAX];   // Professors' branch
char specialization[MAX]; //Professors' specialization

void main()
{
    int choice;
    while(1)
    {
    	printf("DLL STACK AND QUEUE OPERATIONS\n");
    	printf("1. DLLStack\n");
        printf("2. DLLQueue\n");
        printf("3. Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
			case 1: DLLStack();
					break;
		    case 2: DLLQueue();
				    break;
		    case 3: printf(" Exit\n");
		            break;
			default:printf("Enter a valid choice\n");
					exit(0);
        }
    }
}


void DLLStack()
{
	int choice;

//	NODE first;
	top=NULL;
	while(choice!=4)
	{
		printf("\n\nSTACK OPERATIONS USING DOUBLY LINKED LIST\n");

		printf("1. Push\n");
		printf("2. Pop \n");
		printf("3. Display Stack\n");
		printf("4. Exit\n");
		printf("Enter the choice\n");
		scanf("%d", &choice);
		switch (choice)
				{
				case 1: top = Push(top);
						break;

				case 2: top = Pop();
						break;

				case 3: DisplayStack(top);
						break;

				case 4: printf("Exit\n");
						break;

				default:printf("Please Enter valid choice\n");
				}
	}
}




NODE Push(NODE top)
{

	NODE q;
	MALLOC(q, sizeof(struct List), NODE);

	printf("Enter the details of professor\n");
	printf("Enter Professor ID: ");
	scanf("%d", &id);
	printf("Enter Professor Name: ");
	scanf("%s",name);
	printf("Enter Professor Branch: ");
	scanf("%s",branch);
	printf("Enter Professor Specialization: ");
	scanf("%s",specialization);

	q->ID = id;
	strcpy(q->Name, name);
	strcpy(q->Branch, branch);
	strcpy(q->Specialization, specialization);

	if (top == NULL)
	{
	    q->next = NULL;
	    q->prev = NULL;
	    top = q;
	}
	else
	{
	    top->next = q;
	    q->prev = top;
	    top = q;
	}
	return(top);
}

NODE Pop()
{
	NODE temp;
    if (top == NULL)
    {
    printf("Stack is Empty\n");
    return NULL;

    }
    if(top->next == NULL && top->prev == NULL)
    {

        temp = top;
        top= NULL;
        printf("The Popped Element is \n");
        printf("%d\t%s\t%s\t\t%s\n",temp->ID,temp->Name, temp->Branch, temp->Specialization);
        free(temp);
        return(top);
    }

	temp = top;
	top = top->prev;
	top->next = NULL;
	printf("The Popped Element is\n");
	printf("%d\t%s\t%s\t\t%s\n",temp->ID,temp->Name, temp->Branch, temp->Specialization);
	free(temp);
	return(top);
}

void DisplayStack(NODE top)
{
	NODE temp;
	int count=0;
    temp = top;
    if (temp==NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
     while(temp!= NULL)
    {
    	printf("%d\t%s\t%s\t\t%s\n",temp->ID,temp->Name, temp->Branch, temp->Specialization);
        temp = temp->prev;
        count++;
    }
     printf("\n");
     printf("Count of Nodes = %d\n",count);

}

void DLLQueue()
{
	int choice;
    front=rear=NULL;

    while(choice!=4)
	{
		printf("\n\nQUEUE OPERATIONS USING DOUBLY LINKED LIST\n");

		printf("1. InsertRear \n");
		printf("2. DeleteFront\n");
		printf("3. DisplayQueue\n");
		printf("4.Exit\n");
		printf("Enter the choice\n");
		scanf("%d", &choice);
		switch (choice)
		{
				case 1:   rear = InsRear(rear);
						  break;

				case 2:	  front = DelFront(front);
						  break;

				case 3:	  DisplayQueue(front);
						  break;

				case 4:   printf("Exit\n");
						  break;

				default:  printf("Please Enter a Valid Choice\n\n");
						  break;
			}
		}

}

NODE InsRear(NODE rear)
{

    NODE q, cur;
	MALLOC(q, sizeof(struct List), NODE);

	printf("Enter the details of professor\n");
	printf("Enter Professor ID: ");
	scanf("%d", &id);
	printf("Enter Professor Name: ");
	scanf("%s",name);
	printf("Enter Professor Branch: ");
	scanf("%s",branch);
	printf("Enter Professor Specialization: ");
	scanf("%s",specialization);

	q->ID = id;
	strcpy(q->Name, name);
	strcpy(q->Branch, branch);
	strcpy(q->Specialization, specialization);

	q->next = NULL;

	if (front == NULL)
	{
			front=rear=q;
	        return rear;
	}
	cur = rear;
	while (cur->next != NULL)
			cur = cur->next;
	cur->next = q;
	q->prev=cur;
		return rear;

}

NODE DelFront(NODE front)
{
	NODE temp;
	if(front==NULL)
	{
		printf("List is Empty\n");
		return NULL;
	}
	temp=front;
	front=front->next;
	printf("%d\t%s\t%s\t\t%s\n",temp->ID,temp->Name, temp->Branch, temp->Specialization);
	free(temp);
	return front;

}

void DisplayQueue(NODE front)
{
    int count=0;
	if(front == NULL)
	printf("\nList is Empty\n");
	else
	while (front)
	   {
		printf("%d\t%s\t%s\t\t%s\n", front->ID, front->Name, front->Branch, front->Specialization);
		front = front->next;
		count++;
	   }
	printf("\n");
	printf("Count of Nodes = %d\n",count);
}
