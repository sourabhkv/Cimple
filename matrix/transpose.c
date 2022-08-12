/*
OUTPUT

enter row:3
1
2
3
4
5
6
7
8
9
Before
1       2       3
4       5       6
7       8       9
Transposed
1       4       7
2       5       8
3       6       9

*/

#include <stdio.h>
void main()
{
	int row,temp;
	printf("enter row:");
	scanf("%d",&row);
	int matrix[row][row],trans[row][row];
	for (int i=0;i<row;i++)
		for (int j=0;j<row;j++)
			scanf("%d",&matrix[i][j]);
	printf("Before\n");
	for (int i=0;i<row;i++){
		for (int j=0;j<row;j++){
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
	printf("Transposed\n");

	for (int i=0;i<row;i++){
		for (int j=0;j<row;j++){
			trans[i][j]=matrix[j][i];
			printf("%d\t",trans[i][j]);
		}
		printf("\n");
	}
}
