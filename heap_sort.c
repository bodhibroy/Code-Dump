										  /*HEAP SORT*/

# include <stdio.h>
# include <conio.h>
# include <ctype.h>
# include <stdlib.h>
# define null 0

struct node_type
{
	int data;
   int count;
   struct node_type *left;
   struct node_type *right;
};

typedef struct node_type node;

node *start;
int maxr;
int data,position,count=1;

void create(node **root);
void inorder(node *root);
void search(node *root);
void sort(node *root);
void display(node *root);
void display_tree(node *root,int r,int cl,int cr);

void main()
{
	node *root=null;
   maxr=0;
	do
   {
   	printf("\n\n\tEnter the data (if end press 999)=");
      scanf("%d",&data);
      if(data!=999)
      {
      	if(root!=null)
          	create(&root);
         else
         {
         	root=(node*)malloc(sizeof(node));
            root->data=data;
            root->count=count;
            root->left=null;
            root->right=null;
            count++;
         }
      }
   }while(data!=999);
   start=root;
   system("cls");
   display_tree(start,1,0,80);
   gotoxy(8,maxr);
   printf("\n\n\t");
   printf("\n\n\tThe created tree");
   //inorder(root);
   getch();
   count--;
   position=count;
   do
   {
   	search(root);
      sort(root);
      position--;
   }
   while(position!=root->count);
   system("cls");
   display_tree(start,1,0,80);
   gotoxy(8,maxr);
   printf("\n\n\tThe modified tree");
   //inorder(root);
   getch();
   printf("\n\n\tThe sorted tree=\n\n\t");
   do
   {
   	display(root);
      position++;
   }while(position<=count);
   getch();
}

void create(node **root)
{
	int temp1,temp2=count;
	if(*root!=null)
   {
   	do
      {
      	temp1=temp2%2;
         temp2/=2;
      }while(temp2!=(*root)->count);
   	if(temp1==0)
      {
      	create(&((*root)->left));
         if((*root)->left->data>(*root)->data)
         	(*root)->data=((*root)->data+(*root)->left->data)-((*root)->left->data=(*root)->data);
      }
      else
      {
      	create(&(*root)->right);
         if((*root)->right->data>(*root)->data)
         	(*root)->data=((*root)->data+(*root)->right->data)-((*root)->right->data=(*root)->data);
      }
   }
   else
   {
   	(*root)=(node*)malloc(sizeof(node));
      (*root)->data=data;
      (*root)->count=count;
      (*root)->left=null;
      (*root)->right=null;
      count++;
   }
}

/*void inorder(node *root)
{
	if(root->left!=null)
   	inorder(root->left);
   printf("%d ",root->data);
   if(root->right!=null)
   	inorder(root->right);
}*/

void search(node *root)
{
	int temp1,temp2=position;
   if(root->count==position)
   {
   	start->data=root->data+start->data;
      root->data=start->data-root->data;
      start->data=start->data-root->data;
   }
   else
   {
   	do
   	{
     		temp1=temp2%2;
      	temp2/=2;
   	}while(temp2!=root->count);
   	if(temp1==0)
      	search(root->left);
      else
      	search(root->right);
   }
}

void sort(node *root)
{
	node *temp;
   if(root->left!=null)
   {
		if(root->left->count<position)
   	{
      	if(root->right!=null)
         {
   			if(root->right->count<position)
      		{
            	if(root->left->data>root->right->data)
               	temp=root->left;
               else
                 	temp=root->right;
               if(root->data<temp->data)
               {
                 	root->data=(root->data+temp->data)-(temp->data=root->data);
                  sort(temp);
               }
            }
            else
            {
            	if(root->data<root->left->data)
               	root->data^=root->left->data^=root->data^=root->left->data;
            }
         }
         else
         {
    			temp=root->left;
            if(root->data<temp->data)
            {
             	root->data=(root->data+temp->data)-(temp->data=root->data);
            }
         }
   	}
   }
}

void display(node *root)
{
	int temp1,temp2=position;
	if(root->count!=position)
   {
   	do
   	{
     		temp1=temp2%2;
      	temp2/=2;
   	}while(temp2!=root->count);
   	if(temp1==0)
      	display(root->left);
      else
      	display(root->right);
   }
   else
   	printf("%d  ",root->data);
}

void display_tree(node *root,int r,int cl,int cr)
{
	int c,temp,i;
   if(r>maxr)
   	maxr=r;
   c=(cr-cl)/2+cl;
   gotoxy(c,r);
   if(root!=null)
   {
   	printf("%d--%d",root->data,root->count);
      temp=((c-cl)/2+cl);
      gotoxy(c,r+1);
      printf("|");
      gotoxy(c,r+2);
      printf("|");
      for(i=c-1;i>=temp;i--)
      {
      	gotoxy(i,r+2);
         printf(".");
      }
      gotoxy(temp,r+3);
      printf("|");
      gotoxy(temp,r+4);
      printf("|");
      if(r!=1)
      	display_tree(root->left,r+5,cl,c);
      else
      	display_tree(root->left,r+4,cl,c);
      temp=((cr-c)/2+c);
      for(i=c+1;i<=temp;i++)
      {
      	gotoxy(i,r+2);
         printf(".");
      }
      gotoxy(temp,r+3);
      printf("|");
      gotoxy(temp,r+4);
      printf("|");
      if(r!=1)
      	display_tree(root->right,r+5,c,cr);
      else
         display_tree(root->right,r+4,c,cr);
   }
   else
   	printf("NULL");
}

