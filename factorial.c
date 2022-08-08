#include <stdio.h>
void main(){
	int n,fact=1;
	printf("enter n:");
	scanf("%d",&n);
	if (n>0){
		for (int i=1;i<=n;i++){
			fact*=i;
		}
		printf("%d ! = %d",n,fact);
	}
}
