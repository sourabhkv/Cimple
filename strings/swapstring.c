/*
OUTPUT
enter string 1:python
enter string 2:C#
After swapping
C# is string 1
python is string 2
*/

#include <stdio.h>
#include <string.h>
void main()
{
	char s1[20],s2[20],temp[20]={'\0'};
	int i;
	printf("enter string 1:");
	scanf("%s",s1);
	printf("enter string 2:");
	scanf("%s",s2);

	for (i=0;i<=strlen(s1);i++)
		temp[i]=s1[i];

	for (i=0;i<=strlen(s2);i++)
		s1[i]=s2[i];

	for (i=0;i<=strlen(temp);i++)
		s2[i]=temp[i];
	
	printf("After swapping\n");
	printf("%s is string 1\n",s1);
	printf("%s is string 2\n",s2);
}
