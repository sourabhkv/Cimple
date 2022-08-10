#include <stdio.h>
void main()
{
	int i,j,n;
	printf("enter no. of rows :");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		for (j=1;j<i+1;j++)
		{
			printf("%d",j);
		}
		printf("\n");
	}
}
