#include <stdio.h>
#include <math.h>
void main(){
	int degree,i;
	float x,nume,deno,sum=0,term,pi=3.14159;
	printf("enter angle:");
	scanf("%d",&degree);
	x=degree*pi/180;
	nume=x;
	deno=1;
	i=2;
	do{
		term=nume/deno;
		nume=-nume*x*x;
		deno=deno*i*(i+1);
		sum=sum+term;
		i=i+2;
	}while(fabs(term)>=0.00001);
	printf("sin%d= %.3f\n",degree,sum);
	printf("sin%d =%.3f\n",degree,sin(x));
}
