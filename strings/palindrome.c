#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main(){
	char st[20];
	printf("enter string:");
	scanf("%s",st);
	int r=strlen(st)/2;
	for (int i=0;i<r;i++){
		if (st[i]==st[strlen(st)-i-1]){
			continue;
		}
		else{
			printf("%s is not palindrome",st);
			exit(0);
		}
	}
	printf("%s is Palindrome",st);
}
