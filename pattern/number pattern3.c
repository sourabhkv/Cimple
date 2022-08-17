/*
Pattern problem 2
OUTPUT
enter n:4
1 
2 2 
3 3 3 
4 4 4 4 

*/
#include <stdio.h>
void main(){
	int n,i,j;
	printf("enter n:");
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		for (j=1;j<=i;j++){
			printf("%d ",i);
		}
		printf("\n");
	}
}
