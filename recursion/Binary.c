#include <stdio.h>
int Binary(int a[], int key, int low, int high){
	int mid;
	if (low>high)
		return -1;
	mid = (low + high)/2;
	if (a[mid]==key)
		return mid;
	else if (a[mid]>key)
		return Binary(a , key, low , mid-1);
	else
		return Binary(a, key, mid+1, high);
}

void main(){
	int a[10],i,n,key,res;
	printf("enter length of array:");
	scanf("%d",&n);
	for(i=0 ; i<n ; i++)
		scanf("%d",&a[i]);
	printf("\nenter key:");
	scanf("%d",&key);
	res = Binary(a, key, 0 , n-1);
	if (res==-1)
		printf("key not found\n");
	else
		printf("%d found at %d index\n",key,res);
}
