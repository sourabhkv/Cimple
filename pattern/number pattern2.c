/*

output
enter no. of rows :5
        1
      1   2
    1   2   3
  1   2   3   4
1   2   3   4   5


*/
#include <stdio.h>
void main()
{
	int i,j,k,n;
	printf("enter no. of rows :");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		for (k=n-1;k>=i;k--)
		{
			printf("  ");
		}
		for (j=1;j<i+1;j++)
		{
			printf("%d   ",j);
		}
		printf("\n");
	}
}
