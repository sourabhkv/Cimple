#include <stdio.h>
int iter=0,count=1;
int convertB_D(int num){
	iter++;
	if (iter!=1)
		count*=2;
	if ((num/10)==0)
		return (num*count);
	return ((num%10)*count+convertB_D(num/10));
}

void main(){
	int N,D;
	printf("enter number in binary:");
	scanf("%d",&N);
	D=convertB_D(N);
	printf("decimal = %d\n",D);
}
