# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# define null 0

struct tree
{
	int data;
   int check;
   struct tree *left;
   struct tree *right;
};

typedef struct tree node;

void create(node *root,node *left,node *right);
void display(node *root);
void assign(node *root,node *left,node *right);

int data;

void main()
{
	node *root=null;
   printf("\n\n\tEnter a integer(if over press '-999')=");
   scanf("%d",&data);
   while(data!=-999)
   {
   	if(root==null)
      {
      	root=(node*)malloc(sizeof(node));
         assign(root,null,null);
      }
      else
   		create(root,null,null);
   	printf("\n\n\tEnter a integer(if over press '-999')=");
   	scanf("%d",&data);
   }
   printf("\n\n\tDisplay the inorder traversal=\n\n\t");
   display(root);
   getch();
}

void create(node *root,node *left,node *right)
{
	if(root->data>data)
   {
   	if(root->left!=left)
      	create(root->left,left,root);
      else
      {
      	root->left=(node*)malloc(sizeof(node));
         assign(root->left,left,root);
      }
   }
   else
   {
   	if(root->right!=right)
      	create(root->right,root,right);
      else
      {
      	root->right=(node*)malloc(sizeof(node));
         assign(root->right,root,right);
      }
   }
}

void assign(node *root,node *left,node *right)
{
	root->data=data;
	root->left=left;
   root->right=right;
   root->check=0;
   printf("\n\nroot= %x  left= %x  right= %x",root,root->left,root->right);
}

void display(node *root)
{
	if(root!=null)
   {
   	if(root->check==0)
      {
   		display(root->left);
         if(root->check==0)
         {
         	printf("%d  ",root->data);
      		root->check=1;
         	display(root->right);
         }
      }
   }
}
