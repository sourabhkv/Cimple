#include <stdio.h>
#include <math.h>
void main(){
	int n,factor=0;
	printf("enter n:");
	scanf("%d",&n);
	int r=sqrt(n);
	if (n==2){//skipping 2  only even prime
		printf("2 is prime");
	}
	else if (n!=2 && n>2){
		for (int i=3;i<=r;i+=2){//leaving even numers
			if (n%i==0){
				factor=factor+1;
				break;
			}
		}
		if (factor==0){
			printf("%d is prime",n);
		}
		else if (factor>0){
			printf("%d is not prime",n);
		}
	}
}
