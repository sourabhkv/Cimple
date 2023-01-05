#include <stdio.h>
void toh(int , char , char ,char);
int count=0;
void toh(int n , char A, char B,char C)
{
	if (n>0){
		toh(n-1,A,C,B);
		printf("disk %d moved from %c --> %c\n",n,A,C);
		count++;
		toh(n-1,B,A,C);
	}
}

void main(){
	int n;
	printf("enter n:");
	scanf("%d",&n);
	toh(n,'A','B','C');
	printf("no of steps = %d\n",count);
}
