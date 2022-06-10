//Check whether number is odd or even
include <stdio.h>
void main(){
	//Check even or odd
	int n;
	printf("enter number :");
	scanf("%d",&n);
	printf("%d",n);
	if (n%2==0){
		printf("%d is even",n);
	}
	else{
		printf("%d is odd",n);
	}
}
