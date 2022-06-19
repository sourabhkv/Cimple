#include <stdio.h>
void main(){
	//Check prime
	int n;
	printf("enter year :");
	scanf("%d",&n);
	if (n%100==0){
		if (n%400==0){//centurian year divisible by 400 are leap year
			printf("%d is leap year",n);
		}
		else{//1700,1800,1900 are divisible by 4 but still not leap year
			printf("%d is not leap year",n);
		}
	}
	else if (n%4==0){
		printf("%d is leap",n);
	}
	else{
		printf("%d is not leap year",n);
	}
}
