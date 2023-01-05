#include <stdio.h>
#include <string.h>
#define MAX 6
void push(int stack[], int *top , int ele){
	if (*top==-1)
		printf("stack underflow\n");
	else{
		++(*top);
		stack[*top]=ele;
	}
	return;
}

void display(int stack[] , int top){
	int i;
	if (top==-1)
		printf("stack is empty\n");
	else{
		printf("the stack elemets are \n");
		for(i=top ; i>=0 ; i--)
			printf("%d\t",stack[i]);
	}
}

int pop(int stack[], int *top){
	int temp;
	if (*top==-1)
		printf("stack underflow\n");
	else{
		temp = stack[*top];
		(*top)--;
		return temp;
	}
}

void main(){
	int stack[MAX], ele,top=-1,deleted_item ,flag=1,done=0,choice;
	while(!done){
		printf("\n1.push\n2.pop\n3.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter the element to be pushed\n");
				scanf("%d",&ele);
				push(stack,&top,ele);
				display(stack,top);
				break;
			case 2:
				deleted_item = pop(stack,&top);
				printf("Item selected = %d\n",deleted_item);
				display(stack,top);
				break;
			case 3:
				done=1;
				break;
			default:
				printf("invalid statement");
				break;
		}
	}
}
