/*

OUTPUT

enter no. of rows :5
               1
            1     1
         1     2     1
      1     3     3     1
   1     4     6     4     1
   
  

*/

#include <stdio.h>
void main()
{
	int i,j,k,n,c;
	printf("enter no. of rows :");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		c=1;
		for (k=n-1;k>=i;k--)
		{
			printf("   ");
		}
		for (j=0;j<=i;j++)
		{
			printf("%d     ",c);
			c=c*(i-j)/(j+1);
		}
		printf("\n");
	}
}
