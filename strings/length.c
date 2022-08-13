/*
OUTPUT

enter string:hello
Length of string hello = 5

*/

#include <stdio.h>
void main()
{
	int len=0;
	char st[50];
	printf("enter string:");
	scanf("%s",st);
	while (st[len]!='\0')
		len++;
	printf("Length of string %s = %d",st,len);
}
