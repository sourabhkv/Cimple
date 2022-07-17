#include <stdio.h>
void main(){
	int count=1,n;
	printf("enter upper limit :");
	scanf("%d",&n);
	for (int i=3;i<n;i+=2){//skipping even numbers except 2 i.e. included in count default value
		int factor=0;
		for (int j=1;j<i+1;j++){
			if (i%j==0){
				factor=factor+1;
				if (factor>2){
					break;
				}
			}
		}
		if (factor==2){
			count+=1;
		}
	}
	printf("%d",count);
}
