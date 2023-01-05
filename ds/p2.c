#include <stdio.h>
#define MAX 50
void create(int[] , int);
void display(int[], int);
void insert(int[], int *, int, int);
void delete(int[], int *, int);

void create(int a[], int n){
	int i;
	printf("enter elements of array\n");
	for (i=0 ; i<n ;i++)
		scanf("%d",&a[i]);
}

void display(int a[],int n){
	int i;
	printf("array elements are\n");
	for(i=0 ; i<n ; i++)
		printf("%d\t",a[i]);
}

void insert(int a[], int *n ,int ele,int pos){
	int i;
	printf("enter position\n");
	scanf("%d",&ele);
	if (*n >=MAX)
		printf("array is full");
	else if (*n ==0)
		printf("array is empty");
	else if (pos==*n)
		printf("invalid position");
	else{
		for (i=*n-1 ; i>=pos ; i--)
			a[i+1] = a[i];
		a[pos]=ele;
		(*n)++;
	}
}

void delete(int a[], int *n, int pos){
	int i;
	if (*n==0)
		printf("array is empty\n");
	else if (0>pos || pos>*n-1)
		printf("invalid selection");
	else{
		for(i=pos ; i<*n ;i++)
			(*n)--;
	}
}

void main(){
	int a[MAX],done=0,n=0,choice,pos,ele;
	while(!done){
		printf("1. create\t2.display\t3.insert\t4.delete\n");
		printf("\nenter your choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter length of array");
				scanf("%d",&n);
				create(a,n);
				break;
			case 2:
				display(a,n);
				break;
			case 3:
				insert(a,&n,ele,pos);
				break;
			case 4:
				printf("enter position of element");
				scanf("%d",&pos);
				delete(a,&n,pos);
				break;
			case 5:
				done=1;
				break;
		}
	}
}
