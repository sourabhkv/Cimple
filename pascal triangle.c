/*

OUTPUT

enter no. of rows :4
            1
         1     1
      1     2     1
   1     3     3     1
1     4     6     4     1

enter no. of rows :7
                     1
                  1     1
               1     2     1
            1     3     3     1
         1     4     6     4     1
      1     5     10     10     5     1
   1     6     15     20     15     6     1
1     7     21     35     35     21     7     1


*/

#include <stdio.h>
int fact(int n)
{
	int fact=1;
	if (n>0){
		for (int s=1;s<=n;s++){
			fact*=s;
		}
		return fact;
	}
	else
		return fact;
}

void main()
{
	int i,j,k,n,r;
	printf("enter no. of rows :");
	scanf("%d",&n);
	for (i=0;i<=n;i++)
	{
		for (k=n-1;k>=i;k--)
		{
			printf("   ");
		}
		for (j=0;j<i+1;j++)
		{
			r=fact(i)/((fact(i-j))*(fact(j)));
			printf("%d     ",r);
		}
		printf("\n");
	}
}
