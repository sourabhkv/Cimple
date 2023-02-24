#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

/*Function to allocate a new node on the heap memory */
#define MALLOC(p,s,t) \
if (!((p) = (t) malloc(s))) {\
fprintf(stderr, "Insufficient Memory\n"); \
exit(EXIT_FAILURE); \
}


/*A binary tree node has data,pointer to left child and a pointer to right child */
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

typedef struct tree *NODE;


// Function to create tree and insert nodes in level order
NODE CreateTree(int arr[], NODE root, int i, int n)
{
	NODE q;
   // Initial condition for recursion
   if (i < n)
   {
	   MALLOC(q, sizeof(struct tree), NODE);
	   q->data= arr[i];
	   q->left=q->right=NULL;

       root = q;
       // insert left child
       root->left = CreateTree(arr, root->left, 2 * i + 1, n);
       // insert right child
       root->right = CreateTree(arr, root->right, 2 * i + 2, n);
   }
   return root;
}

// Function to print tree nodes in PreOrder fashion ( Node-Left-Right)
void PreOrder(NODE root)
{
	if(root!=NULL)
	 {
		printf("%d\t", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	 }
}

// Function to print tree nodes in InOrder fashion ( Left-Node-Right)
void InOrder(NODE root)
{
	if(root!=NULL)
	 {
	 	InOrder(root->left);
		printf("%d\t", root->data);
	 	InOrder(root->right);
	 }
}

// Function to print tree nodes in PostOrder fashion ( Left-Right-Node)
void PostOrder(NODE root)
{
	if(root!=NULL)
	 {
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d\t", root->data);
	 }
}

//Function to test the above mentioned functions
void main()
{
	int arr[]= {1,2,3,4,5,6};
	/*To find the length of the array in C,
	divide the total array size by the size of one data type*/
	int n= sizeof(arr)/sizeof(arr[0]);

	NODE root;
	root=NULL;
	root= CreateTree(arr, root, 0, n);
	printf("Complete Binary Tree Construction with Traversals\n\n");
	printf("The Preorder traversal of tree is :\n ");
	PreOrder(root);
	printf("\nThe Inorder traversal of tree is :\n ");
	InOrder(root);
	printf("\nThe Postorder traversal of tree is :\n ");
	PostOrder(root);

}
