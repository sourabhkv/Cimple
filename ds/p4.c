#include<stdio.h> 
#include<stdlib.h>
#include<ctype.h>
#include<math.h> 
#define MAX 60
void push(float [], int *, float);
float pop(float[], int *);
float eval(char[]);
float oper(char, float, float);

int main(){
	char expr[MAX];
	printf("enter the postfix expression\n");	//fgets(expr,80,stdin);
	scanf("%s",expr);
	printf("\n the original postfix expression is %s", expr); 
	printf("\n %f\n",eval(expr));
	return 0;
}

float eval(char expr[]){
	char c; 
	int pos;
	float result,s[MAX]; 
	float op1, op2, r;
	int top=-1;
	for(pos=0;(c=expr[pos])!='\0';pos++)
	{
		if(isdigit(c))
			push(s,&top,(c-'0'));
		else
		{
			op2=pop(s,&top); 
			op1=pop(s,&top); 
			r=oper(c,op1,op2);
 			push(s,&top,r);
		}
	}
	result=pop(s,&top);
	return result;
}


float oper(char symb, float op1, float op2)
{
	switch(symb)
	{
		case '+':return(op1+op2); 
		case '-': return(op1-op2); 
		case '*': return(op1*op2);
		case '/': return(op1/op2);
		case '^': return((float)pow(op1,op2));
		case '%': return((float)((int)op1%(int)op2)); 
		default: printf("invalid operation\n"); exit(1);
	}
}

void push(float items[], int *top, float e)
{
	items[++(*top)]=e;
}

float pop(float items[], int *top)
{
	return items[(*top)--];
}
