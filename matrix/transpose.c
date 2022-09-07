/*
OUTPUT

enter order of matrix mxn:3 4
enter elements of matrix
1
2
3
4
5
6
7
8
9
10
11
12
matrix A
1       2       3       4
5       6       7       8
9       10      11      12

transposed matrix of A
1       5       9
2       6       10
3       7       11
4       8       12
*/

#include <stdio.h>
void main(){
	int m,n,i,j;
	printf("enter order of matrix mxn:");
	scanf("%d %d",&m,&n);
	int a[m][n],b[n][m];
	printf("enter elements of matrix\n");
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			b[j][i]=a[i][j];
		}
	}
	
	printf("\nmatrix A\n");
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\ntransposed matrix of A\n");
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
}
