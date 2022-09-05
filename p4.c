#include <stdio.h>
void main(){
	int a[10],i,n,low,high,mid,found=0,key;
	printf("enter no:");
	scanf("%d",&n);
	printf("enter elements sorted\n");
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("enter key:");
	scanf("%d",&key);
	low=0;
	high=n-1;
	while (low<=high &&!found){
		mid=(low+high)/2;
		if (a[mid]==key)
			found=1;
		else if (a[mid]<key)
			low=mid+1;
		else
			high=mid-1;
	}
	if (found==1)
		printf("%d key found at %d\n",key,mid+1);
	else
		printf("not found\n");
}
