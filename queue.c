
												/*QUEUE*/

# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <ctype.h>
# define null 0

struct list_element
{

	int data;
   struct list_element *next;
};

typedef struct list_element node;

node *insert(node *rear);
node *del(node *front);

int data;

void main()
{
   node *front=null,*rear=null;
   char ch;
   do
   {
   	printf("\n\n\tTo insert press '1'");
   	printf("\n\n\tTo delete press '2'");
   	printf("\n\n\tIf over insert '-999'");
   	ch=getch();
      fflush(stdin);
   	if(ch=='1')
   	{
   		printf("\n\n\t\tEnter data=");
     		scanf("%d",&data);
         if(data!=-999)
           	rear=insert(rear);
         if(front==null)
      		front=rear;
      }
   	else
   	  	front=del(front);
   }while(data!=-999);
}

node *insert(node *rear)
{
	if(rear!=null)
   {
   	rear->next=(node*)malloc(sizeof(node));
      rear=rear->next;
   }
   else
   	rear=(node*)malloc(sizeof(node));
   rear->data=data;
   rear->next=null;
   return(rear);
}

node *del(node *front)
{
	node *temp=null;
	if(front!=null)
   {
   	printf("\n\n\t\tThe data=%d",front->data);
      temp=front->next;
      free(front);
   }
   else
   	printf("\n\n\t\tERROR!UNDERFLOW");
   return(temp);
}
