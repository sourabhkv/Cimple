#include <stdio.h>
void main(){
	int a[10][10],b[10][10],c[10][10],i,j,k,m,n,p,q;
	printf("enter order of matrix A:");
	scanf("%d %d",&m,&n);
	printf("enter order of matrix B:");
	scanf("%d %d",&p,&q);
	if (n!=p)
		printf("Matrix multiplication not possible\n");
	else
		printf("enter elements of matrix A\n");
		for (i=0;i<m;i++){
			for (j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		printf("\nenter elements of matrix B\n");
		for (i=0;i<p;i++){
			for (j=0;j<q;j++){
				scanf("%d",&b[i][j]);
			}
		}
		for (i=0;i<m;i++){
			for (j=0;j<q;j++){
				c[i][j]=0;
				for (k=0;k<n;k++){
					c[i][j]+=a[i][k]*b[k][j];
				}
			}
		}
		printf("\nA\n");
		for (i=0;i<m;i++){
			for (j=0;j<n;j++){
				printf("%d",a[i][j]);
			}
			printf("\n");
		}
		printf("\nB\n");
		for (i=0;i<p;i++){
			for (j=0;j<q;j++){
				printf("%d",b[i][j]);
			}
			printf("\n");
		}
		printf("\nC\n");
		for (i=0;i<m;i++){
			for (j=0;j<n;j++){
				printf("%d",c[i][j]);
			}
			printf("\n");
		}
}
				
