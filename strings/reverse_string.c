/*
OUTPUT

enter string:racecar
Reverse string = racecar

*/
#include <stdio.h>
#include <string.h>
void main()
{
	int len=0;
	char st[50];
	printf("enter string:");
	gets(st);
	printf("Reverse string = ");
	for (int i=strlen(st)-1;i>=0;i--)
		printf("%c",st[i]);
}
