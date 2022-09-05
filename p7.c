#include <stdio.h>
void main(){
	int a[10],i,j,temp,n;
	printf("enter n:");
	scanf("%d",&n);
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("original elements\n");
	for (i=0;i<n;i++)
		printf("%d\t",a[i]);
		
	for (i=0;i<n;i++){
		for (j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("After sorting\n");
	for (i=0;i<n;i++)
		printf("%d\t",a[i]);
}
