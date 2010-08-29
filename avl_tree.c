
										     /*AVL TREE*/

# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <ctype.h>
# define null 0

struct nodetype
{
	int data;
   int level;
   struct nodetype *left;
   struct nodetype *right;
   struct nodetype *father;
};

typedef struct nodetype node;

int data,maxr;
node *head=null;

char choice();
void create(node *root);
void assign(node *root,node *present,int level);
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);
void insert(node *root);
void del(node **root);
void search(node *root);
void display(node *root,int r,int cl,int cr);
void balance(node **root);
int max_height(node *root);
node *left_rotate(node *root);
node *right_rotate(node *root);
void subtract_level(node **root);
void add_level(node **root);

void main(int argv,char *argc[])
{
	do
   {
   	maxr=0;
   	system("cls");
		switch(choice())
   	{
   		case '1':
      		printf("\n\n\tEnter the data (if over press '-999')=");
         	scanf("%d",&data);
         	if(head==null)
         	{
         		head=(node*)malloc(sizeof(node));
            	assign(null,head,0);
         	}
         	while(data!=-999)
   			{
   				printf("\n\n\tEnter the data(if over press '-999')=");
   				scanf("%d",&data);
   				if(data!=-999)
      	  			create(head);
         	}
         	system("cls");
         	display(head,1,0,80);
         	gotoxy(8,maxr);
         	break;
         case '2':
         	printf("\n\n\t");
           	preorder(head);
            break;
         case '3':
         	printf("\n\n\t");
         	inorder(head);
            break;
         case '4':
         	printf("\n\n\t");
         	postorder(head);
            break;
         case '5':
         	printf("\n\n\tEnter the new data=");
            scanf("%d",&data);
            create(head);
            system("cls");
            display(head,1,0,80);
            gotoxy(8,maxr);
            break;
         case '6':
         	printf("\n\n\tEnter the data to delete=");
            scanf("%d",&data);
            del(&head);
            system("cls");
            display(head,1,0,80);
            gotoxy(8,maxr);
            break;
         case '7':
         	printf("\n\n\tEnter the no. for searching=");
            scanf("%d",&data);
            search(head);
            break;
         case '8':
         	system("cls");
         	if(head!=null)
            {
            	display(head,1,0,80);
             	gotoxy(8,maxr);
            }
            else
            	printf("\n\n\tThere is no item for display");
            break;
         case '9':
         	balance(&head);
            system("cls");
            display(head,1,0,80);
            gotoxy(8,maxr);
            break;
   	}
      fflush(stdin);
      printf("\n\n\tWant to continue(Y/N)");
   }while(toupper(getch())=='Y');
}

char choice()
{
	printf("\n\n\tTo create the tree press '1'");
   printf("\n\n\tTo display the tree in preorder press '2'");
   printf("\n\n\tTo display the tree in inorder press '3'");
   printf("\n\n\tTo display the tree in postorder press '4'");
   printf("\n\n\tTo insert a new data press '5'");
   printf("\n\n\tTo delete a data press '6'");
   printf("\n\n\tTo search an element press '7'");
   printf("\n\n\tT0 display the tree structure press '8'");
   printf("\n\n\tTo balance the tree press '9'");
   return(getch());
}

void create(node *root)
{

	if(root->data<=data)
   {
   	if(root->right==null)
      {
         root->right=(node*)malloc(sizeof(node));
      	assign(root,root->right,root->level+1);
      }
      else
      	create(root->right);
   }
   else
   {
   	if(root->left==null)
      {
      	root->left=(node*)malloc(sizeof(node));
        	assign(root,root->left,root->level+1);
      }
      else
      	create(root->left);
   }
}

void assign(node *root,node *present,int level)
{
	present->data=data;
   present->right=null;
   present->left=null;
   present->father=root;
   present->level=level;
}

void preorder(node *root)
{
	printf("%d ",root->data);
   if(root->left!=null)
   	preorder(root->left);
   if(root->right!=null)
   	preorder(root->right);
}

void inorder(node *root)
{
	if(root->left!=null)
   	inorder(root->left);
   printf("%d ",root->data);
   if(root->right!=null)
   	inorder(root->right);
}

void postorder(node *root)
{
	if(root->left!=null)
   	postorder(root->left);
   if(root->right!=null)
   	postorder(root->right);
   printf("%d ",root->data);
}

void del(node **root)
{
	node *temp;
	if(*root!=null)
   {
   	if((*root)->data==data)
      {
      	if(!(*root)->left&&!(*root)->right)
         	*root=null;
         else
         {
         	if(!(*root)->left||!(*root)->right)
            {
            	if((*root)->left)
               {
               	subtract_level(&((*root)->left));
               	*root=(*root)->left;
               }
               else
               {
               	subtract_level(&((*root)->right));
               	*root=(*root)->right;
               }
            }
            else
            {
            	temp=(*root)->right;
            	while(temp->left)
               	temp=temp->left;
               temp->level=(*root)->level;
               temp->left=(*root)->left;
               if((*root)->right!=temp)
               {
               	temp->father->left=temp->right;
                  subtract_level(&(temp->father->left));
                  if(temp->right!=null)
                  	temp->right->father=temp->father;
               	temp->right=(*root)->right;
               }
               else
               	subtract_level(&(temp->right));
               temp->father=(*root)->father;
               temp->left->father=temp;
               if(temp->right!=null)
               	temp->right->father=temp;
               *root=temp;
            }
         }
      }
      else
      {
      	if((*root)->data>data)
         	del(&((*root)->left));
         else
         	del(&((*root)->right));
      }
   }
   else
   	printf("\n\n\tData is not found.");
}

void search(node *root)
{
	if(root!=null)
   {
   	if(root->data==data)
      	printf("\n\n\tElement is found at level %d",root->level);
      else
      {
      	if(root->data>data)
         	search(root->left);
         else
         	search(root->right);
      }
   }
   else
   	printf("\n\n\tElement is not found");
}

void display(node *root,int r,int cl,int cr)
{
	int c,temp,i;
   if(r>maxr)
   	maxr=r;
   c=(cr-cl)/2+cl;
   gotoxy(c,r);
   if(root!=null)
   {
   	printf("%d",root->data);
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
      	display(root->left,r+5,cl,c);
      else
      	display(root->left,r+4,cl,c);
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
      	display(root->right,r+5,c,cr);
      else
         display(root->right,r+4,c,cr);
   }
   else
   	printf("NULL");
}

void balance(node **root)
{
	int bl,br;
   if(*root!=null)
   {
   	do
      {
   		do
      	{
      		bl=max_height((*root)->left);
         	br=max_height((*root)->right);
         	if(bl==0)
         		bl=(*root)->level;
         	if(br==0)
         		br=(*root)->level;
         	if(bl-br<(-1))
         		*root=left_rotate(*root);
         	else
         		if(bl-br>1)
            		*root=right_rotate(*root);
         }while(bl-br<(-1)||bl-br>1);
         balance(&((*root)->left));
      	balance(&((*root)->right));
         bl=max_height((*root)->left);
         br=max_height((*root)->right);
         if(bl==0)
         	bl=(*root)->level;
         if(br==0)
         	br=(*root)->level;
      }while(bl-br<(-1)||bl-br>1);
   }
}

int max_height(node *root)
{
	int bl,br;
   if(root==null)
   	return(0);
   else
   {
   	bl=max_height(root->left);
      br=max_height(root->right);
      if(bl==0)
       	bl=root->level;
      if(br==0)
        	br=root->level;
      if(bl>br)
      	return(bl);
      else
      	return(br);
   }
}

node *right_rotate(node *root)
{
	node *temp=root->left;
   while(temp->right!=null)
   	temp=temp->right;
   temp->level=root->level;
   temp->right=root;
   subtract_level(&(temp->left));
   if(root->left!=temp)
   {
   	temp->father->right=temp->left;
      if(temp->left!=null)
      	temp->left->father=temp->father;
      temp->left=root->left;
   }
   temp->father=root->father;
   root->father=temp;
   root=temp;
   root->left->father=root;
   root->right->left=null;
   add_level(&(root->right));
   return(root);
}

node *left_rotate(node *root)
{
	node *temp=root->right;
   while(temp->left!=null)
   	temp=temp->left;
   temp->level=root->level;
   temp->left=root;
   subtract_level(&(temp->right));
   if(root->right!=temp)
   {
   	temp->father->left=temp->right;
      if(temp->right!=null)
      	temp->right->father=temp->father;
      temp->right=root->right;
   }
   temp->father=root->father;
   root->father=temp;
   root=temp;
   root->right->father=root;
   root->left->right=null;
   add_level(&(root->left));
   return(root);
}

void subtract_level(node **root)
{
	if(*root!=null)
   {
   	(*root)->level-=1;
      subtract_level(&((*root)->left));
      subtract_level(&((*root)->right));
   }
}

void add_level(node **root)
{
	if(*root!=null)
   {
   	(*root)->level+=1;
      add_level(&((*root)->left));
      add_level(&((*root)->right));
   }
}
