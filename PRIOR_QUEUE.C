
											/*PRIORITY QUEUE*/

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
void maxdel(node *first);
void mindel(node *first);

node *front=null,*rear=null,*min,*max;
int data;

void main()
{
   char ch;
   do
   {
   	printf("\n\n\tTo insert press '1'");
   	printf("\n\n\tTo delete minimum press '2'");
      printf("\n\n\tTo delete maximum press '3'");
   	printf("\n\n\tIf over insert '-999'");
   	ch=getch();
      fflush(stdin);
   	switch(ch)
   	{
      	case '1':
   			printf("\n\n\t\tEnter data=");
     			scanf("%d",&data);
         	if(data!=-999)
           		rear=insert(rear);
         	if(front==null)
      			front=rear;
            break;
      	case '2':
         	if(front!=null)
            {
            	min=null;
         		mindel(front);
               if(min!=null)
               {
               	printf("\n\n\tThe minimum no.=%d",min->next->data);
                  min->next=min->next->next;
                  if(min->next==null)
            			rear=min;
               }
               else
               {
               	printf("\n\n\tThe minimum no.=%d",front->data);
                  front=front->next;
               }
               if(front==null)
            		rear=null;
               break;
            }
            else
            	printf("\n\n\tERROR!'UNDERFLOW'");
            break;
         case '3':
         	if(front!=null)
            {
            	max=null;
         		maxdel(front);
               if(max!=null)
               {
               	printf("\n\n\tThe minimum no.=%d",max->next->data);
                  max->next=max->next->next;
                  if(max->next==null)
            			rear=max;
               }
               else
               {
               	printf("\n\n\tThe minimum no.=%d",front->data);
                  front=front->next;
               }
               if(front==null)
            		rear=null;
            }
            else
            	printf("\n\n\tERROR!'UNDERFLOW'");
            break;
   	}
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

void maxdel(node *first)
{
	if(first->next!=null)
   {
   	if(max!=null)
      {
      	if(max->next->data<first->next->data)
         	max=first;
      }
      else
      {
      	if(first->next->data>front->data)
         	max=first;
      }
      maxdel(first->next);
   }
}

void mindel(node *first)
{
	if(first->next!=null)
   {
   	if(min!=null)
      {
      	if(min->next->data>first->next->data)
         	min=first;
      }
      else
      {
      	if(first->next->data<front->data)
         	min=first;
      }
      mindel(first->next);
   }
}
