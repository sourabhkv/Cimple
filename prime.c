//Check prime
#include <stdio.h>
void main(){
	int n,i,factor;
	factor=2;
	printf("enter number :");
	scanf("%d",&n);
	if (n>1){
		for (i=2;i<n;i++){
			if (n%i==0){
				factor=factor+1;
				break;
			}
		}
		if (factor==2){
			printf("%d is prime",n);
		}
		else{
			printf("%d is not prime",n);
		}
	}
	else if (n==1){
		printf("1 is composite");
	}
	else{
		printf("Enter valid number");
	}
}
