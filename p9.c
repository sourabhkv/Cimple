#include <stdio.h>
struct student{
	char name[30];
	int rollno,marks;
};

void main(){
	struct student s[20];
	int i,n;
	float total=0,avg_marks;
	printf("enter number of students:");
	scanf("%d",&n);
	printf("Enter rollno\tname\tmarks");
	for (i=0;i<n;i++){
		scanf("%d %s %d",&s[i].rollno,s[i].name,&s[i].marks);
	
	}
	
	for (i=0;i<n;i++)
		total+=s[i].marks;
	
	avg_marks=total/n;
	printf("the average marks: %f\n",avg_marks);
	printf("The students above avg marks\nName \t\t Marks");
	for (i=0;i<n;i++){
		if (s[i].marks>avg_marks)
			printf("%15s \t\t %d\n",s[i].name,s[i].marks);
	}
	printf("The students below avg marks\nName \t\t Marks");
	for (i=0;i<n;i++){
		if (s[i].marks<avg_marks)
			printf("%15s \t\t %d\n",s[i].name,s[i].marks);
	}
}
	
