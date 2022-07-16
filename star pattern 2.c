/* Expected output if n=5
              *  *  *  *  *
           *  *  *  *  *
        *  *  *  *  *
     *  *  *  *  *
  *  *  *  *  *
*/
#include <stdio.h>
void main(){
	int n;
	printf("enter n:");
	scanf("%d",&n);
	for (int i=1;i<=5;i++){
		for (int j=n-1;j>=i;j--){
			printf("   ");
		}
		for (int k=1;k<=n;k++){
			printf("  *");
		}
		printf("\n");
	}
}
