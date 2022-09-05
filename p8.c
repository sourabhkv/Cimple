#include <stdio.h>
#include <stdlib.h>
void concat(char s1[50],char s2[50])
{
	int i,j;
	for (i=0;s1[i]!='\0';i++);
	for (j=0;s2[j]!='\0';i++,j++)
		s2[i]=s2[j];
	s2[i]='\0';
	printf("%s\n",s2);
}

void length(char s1[50]){
	int i;
	for (i=0;s1[i]!='\0';i++);
	printf("Length of %s = %d\n",s1,i);
}

void compare(char s1[50],char s2[50])
{
	int i=0;
	while (s1[i]==s2[i] && s1[i]!='\0')
		i++;
	if (s1[i]>s2[i])
		printf("%s>%s\n",s1,s2);
	else if (s2[i]>s1[i])
		printf("%s>%s\n",s2,s1);
	else
		printf("%s==%s\n",s1,s2);
}

void main(){
	int ch;
	char s1[50],s2[50];
	printf("1. concat  2.length  3.compare\nEnter choice:");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			printf("enter str1:");
			scanf("%s",s1);
			printf("enter str2:");
			scanf("%s",s2);
			concat(s1,s2);
			break;
		case 2:
			printf("enter str:");
			scanf("%s",s1);
			length(s1);
			break;
		case 3:
			printf("enter str1:");
			scanf("%s",s1);
			printf("enter str2:");
			scanf("%s",s2);
			break;
		case 4:
			exit(0);
	}
}
