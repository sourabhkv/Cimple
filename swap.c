//swap values without temp variable
#include <stdio.h>
void main()
{
	int a,b;
	a=10,b=5;
	printf("Before swapping a=%d b=%d\n",a,b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("After swapping a=%d b=%d",a,b);
}
