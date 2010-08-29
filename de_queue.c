
									     /*DE-QUEUE*/

# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# define null 0

struct nodetype
{
	int data;
   struct nodetype *left;
   struct nodetype *right;
};

typedef struct nodetype node;

char choice();
node *insleft(node *left);
node *insright(node *right);
node *delleft(node *left);
node *delright(node *right);

int data;

void main()
{
	node *right=null,*left=null;
   char c;
   do
   {
      c=choice();
   	switch(c)
      {
      	case '1':
         	printf("\n\n\tEnter the data(if over press -999)=");
         	scanf("%d",&data);
         	if(data!=-999)
           		left=insleft(left);
            if(right==null)
            	right=left;
            break;
         case '2':
         	printf("\n\n\tEnter the data(if over press -999)=");
         	scanf("%d",&data);
         	if(data!=-999)
           		right=insright(right);
            if(left==null)
            	left=right;
            break;
         case '3':
         	left=delleft(left);
            if(left==null)
            	right=null;
         	break;
         case '4':
         	right=delright(right);
            if(right==null)
            	left=null;
         	break;
      }
   }while(data!=-999);
   getch();
}

char choice()
{
	printf("\n\n\tTo insert at left press '1'");
   printf("\n\n\tTo insert at right press '2'");
   printf("\n\n\tTo delete the left press '3'");
   printf("\n\n\tTo delete the right press '4'");
   return(getch());
}

node *insleft(node *left)
{
	if(left!=null)
   {
   	left->left=(node*)malloc(sizeof(node));
      left->left->left=null;
      left->left->right=left;
      left->left->data=data;
      return(left->left);
   }
   else
   {
   	left=(node*)malloc(sizeof(node));
      left->left=null;
      left->right=null;
      left->data=data;
      return(left);
   }
}

node *insright(node *right)
{
	if(right!=null)
   {
   	right->right=(node*)malloc(sizeof(node));
      right->right->right=null;
      right->right->left=right;
      right->right->data=data;
      return(right->right);
   }
   else
   {
   	right=(node*)malloc(sizeof(node));
      right->left=null;
      right->right=null;
      right->data=data;
      return(right);
   }
}

node *delleft(node *left)
{
	node *temp;
	if(left!=null)
   {
   	temp=left->right;
      printf("\n\n\t\tThe data=%d",left->data);
      if(left->right!=null)
      	left->right->left=null;
      return(temp);
   }
   else
   {
   	printf("\n\n\tERROR!'UNDERFLOW'");
      return(left);
   }
}

node *delright(node *right)
{
	node *temp;
	if(right!=null)
   {
   	temp=right->left;
      printf("\n\n\t\tThe data=%d",right->data);
      if(right->left!=null)
      	right->left->right=null;
      return(temp);
   }
   else
   {
   	printf("\n\n\tERROR!'UNDERFLOW'");
      return(right);
   }
}