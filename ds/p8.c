#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

#define MAX 30

struct tree
{
	int info;
	struct tree *left;
	struct tree *right;
};
typedef struct tree *NODE;

#define MALLOC(p,s,t)\
	p=(t)malloc(s);\
	if(p==NULL)\
	 { \
		printf("Insufficient Memory\n"); \
		exit;\
                }

NODE Create(NODE, int);
NODE CreateTree(NODE, int);
void Preorder(NODE);
void Postorder(NODE);
void Inorder(NODE);
int Search(NODE,int);
int n;

int main()
{
	int choice, done, flag, key;
	NODE root;
	root=NULL;
	done=0;
	while(!done)
	 {
		printf("Binary Search Tree Operations\n\n");
	 	printf("1.CreateBST\n2.Preorder Traversal\n3.Inorder Traversal\n");
	 	printf("4.Postorder Traversal\n5.Search Item\n6.Exit\n");
	 	printf("enter choice\n");
	 	scanf("%d",&choice);
	 	switch (choice)
	 	{
	 		case 1: //printf("Enter no. of data elements\n");
	 			//scanf("%d",&n);
	 			root=Create(root,n);
	 			break;
	 		case 2: Preorder(root);
	 			printf("\n");
	 			break;
	 		case 3: Inorder(root);
	 			printf("\n");
	 			break;
	 		case 4: Postorder(root);
	 			printf("\n");
	 			break;
	 		case 5: printf("Enter the key to search\n");
	 			scanf("%d", &key);
	 			flag= Search(root,key);
	 			if(flag==1)
	 			printf("key found\n");
	 			else
	 			printf("key not found\n");
	 			break;
	 		case 6:done=1;
	 			   break;
	 		default: printf("Invalid Choice\n");
	 	 }
	 }
     return 0;
}

NODE Create(NODE root, int n)
{
	int i,item;
	//NODE q;
	if(root==NULL)
	{
		printf("Enter no. of data elements\n");
	    scanf("%d",&n);
	  for(i=1;i<=n;i++)
	   {
			printf("Enter data element\n");
			scanf("%d", &item);
			root=CreateTree(root,item);
	   }
	   return root;
	 }
	else
		printf("Tree already has some data\n");
}


NODE CreateTree(NODE root, int item)
{
	if(root == NULL)
	 {
	  	MALLOC(root,sizeof(struct tree),NODE);
	  	root->info=item;
	  	root->left=root->right=NULL;
	 }
	else if(item == root->info)
	 	printf("Duplicate Entry\n");
	else if(item < root->info)
	 	root->left=CreateTree(root->left,item);
	else
	 	 root->right=CreateTree(root->right,item);
	return root;
 }


int Search(NODE root, int key)
{
	if(root == NULL)
		return 0;
	else if(key == root->info)
		return 1;
	else if(key < root->info)
		return Search(root->left,key);
	else
		return Search(root->right,key);
}


void Preorder(NODE root)
{
	if(root!=NULL)
	 {
		printf("%d\t", root->info);
	 	Preorder(root->left);
	 	Preorder(root->right);
	 }
}

void Inorder(NODE root)
{
	if(root!=NULL)
	 {
	 	Inorder(root->left);
		printf("%d\t", root->info);
	 	Inorder(root->right);
	 }
}

void Postorder(NODE root)
{
	if(root!=NULL)
	 {
	 	Postorder(root->left);
	 	Postorder(root->right);
		printf("%d\t", root->info);
	 }
}
