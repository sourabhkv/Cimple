#include <stdio.h>
void main(){
	int n,digit;
	printf("enter number :");
	scanf("%d",&n);
	printf("reversed = ");
	while (n>0){
		digit=n%10;
		printf("%d",digit);
		n=n/10;
	}
}
