/*
OUTPUT


enter row:3
enter column:3
Matrix A
enter a:1
enter a:0
enter a:0
enter a:3
enter a:2
enter a:78
enter a:4
enter a:2
enter a:7
Matrix B
enter b:3
enter b:5
enter b:0
enter b:7
enter b:-4
enter b:4
enter b:8
enter b:4
enter b:2
Result
A                                       B                                       C
1       0       0                       3       5       0                       4       5       0
3       2       78                      7       -4      4                       10      -2      82
4       2       7                       8       4       2                       12      6       9

*/

#include <stdio.h>
void main()
{
	int row,column;
	printf("enter row:");
	scanf("%d",&row);
	printf("enter column:");
	scanf("%d",&column);
	int a[row][column],b[row][column],c[row][column];
	printf("Matrix A\n");
	for (int i=0;i<row;i++){
		for (int j=0;j<column;j++){
			printf("enter a:");
			scanf("%d",&a[i][j]);
		}
	}
	printf("Matrix B\n");
	for (int i=0;i<row;i++){
		for (int j=0;j<column;j++){
			printf("enter b:");
			scanf("%d",&b[i][j]);
			c[i][j]=a[i][j]+b[i][j];
		}
	}

	printf("Result\n");
	printf("A\t\t\t\t\tB\t\t\t\t\tC\n");
	for (int i=0;i<row;i++){
		for (int j=0;j<column;j++)
			printf("%d\t",a[i][j]);
		printf("\t\t");
		for (int j=0;j<column;j++)
			printf("%d\t",b[i][j]);
		printf("\t\t");
		for (int j=0;j<column;j++)
			printf("%d\t",c[i][j]);
		printf("\n");
	}
}
