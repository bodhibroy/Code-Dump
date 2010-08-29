# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <ctype.h>
# define null 0

struct nodetype
{
	int data;
   struct nodetype *next;
};

typedef struct nodetype node;

char menu();
void create(node *first);
void display(node *first,node *temp);
void insert(node *first);
void del(node *first);

node *head=null;
int data;

void main()
{
	char c;
   node *temp;
   do
   {
   	printf("\n\n\tEnter your choice");
   	c=menu();
   	switch(c)
   	{
   		case '1':
         	printf("\n\n\tEnter te data(if over press -999)");
   			scanf("%d",&data);
         	if(data!=-999)
            {
         		head=(node*)malloc(sizeof(node));
         		head->data=data;
         		head->next=head;
      			create(head);
            }
         	break;
      	case '2':
      		printf("\n\n\tEnter the data from where want to display=");
         	scanf("%d",&data);
         	temp=head;
         	do
         	{
            	if(temp->data==data)
            		break;
            	temp=temp->next;
            	if(temp==head)
            		temp=null;
            }while(temp!=null);
         	if(temp!=null)
      			display(temp,temp);
         	else
         		printf("\n\n\tThe data is not found in the list.");
         	break;
         case '3':
         	printf("\n\n\tEnter the data after wich want to insert(if at begin enter last data)=");
				scanf("%d",&data);
            insert(head);
            break;
         case '4':
         	printf("\n\n\tEnter the data to delete=");
            scanf("%d",&data);
            del(head);
            break;
      }
   	printf("\n\n\tWant to continue(Y/N)");
   }while(toupper(getch())=='Y');
}

char menu()
{
	printf("\n\n\tTo create a circ. list press '1'");
 	printf("\n\n\tTo display a circ. list press '2'");
   printf("\n\n\tTo insert a new node press '3'");
   printf("\n\n\tTo delete a data press '4'");
   return(getch());
}

void create(node *first)
{
	printf("\n\n\tEnter te data(if over press -999)");
   scanf("%d",&data);
   if(data!=-999)
   {
   	first->next=(node*)malloc(sizeof(node));
   	first->next->data=data;
   	first->next->next=head;
   	create(first->next);
   }
}

void display(node *first,node *temp)
{
   printf("\n\n\tThe data=%d",first->data);
   if(first->next!=temp)
   	display(first->next,temp);
}

void insert(node *first)
{
	node *temp;
	if(first->data==data)
   {
   	printf("\n\n\tEnter the new data=");
      scanf("%d",&data);
      temp=first->next;
      first->next=(node*)malloc(sizeof(node));
      first->next->data=data;
      first->next->next=temp;
   }
   else
   	if(first->next!=head)
      	insert(first->next);
      else
      	printf("\n\n\tData is not found.");
}

void del(node *first)
{
	if(head->data!=data)
   {
   	if(first->next->data==data)
        	first->next=first->next->next;
      else
      	if(first->next!=head)
         	del(first->next);
         else
         	printf("\n\n\tTe data is not found");
   }
   else
   	if(first->next==head)
      {
      	first->next=head->next;
         head=head->next;
      }
      else
      	del(first->next);
}
