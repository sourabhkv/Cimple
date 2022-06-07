#include <stdio.h>
void main(){
	printf("Program to calculate area of circle \n");
	//area=3.14*r^2
	float r,area;
	printf("enter radius :");
	scanf("%f",&r);
	if (r>=0){
		area=3.14159*r*r;
		printf("area of circle having radius %f = %f",r,area);
	}
	else{
		printf("enter positive radius");
	}
}
