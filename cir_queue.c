
										 /*CIRCULAR QUEUE*/

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
   node *point=null;
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
           	point=insert(point);
      }
   	else
      {
      	if(point!=null)
         {
           	point->next=del(point->next);
            if(point->next==null)
            	point=null;
         }
         else
         	printf("\n\n\t\tERROR!UNDERFLOW");
      }
   }while(data!=-999);
}

node *insert(node *point)
{
	node *temp;
	if(point!=null)
   {
   	temp=(node*)malloc(sizeof(node));
   	temp->next=point->next;
      point->next=temp;
      temp->data=data;
   }
   else
   {
   	point=(node*)malloc(sizeof(node));
      point->next=point;
   	point->data=data;
   }
   return(point->next);
}

node *del(node *point)
{
	node *temp;
	printf("\n\n\t\tThe data=%d",point->data);
   if(point->next!=point)
   	temp=point->next;
   else
   	temp=null;
   return(temp);
}