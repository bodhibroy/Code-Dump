
							       /*DOUBLE LINK LIST*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define null 0

struct lin
{
	char item[20];
   struct lin *before,*next;
};

typedef struct lin lis;

int menu(void);
lis *create(lis *first);
void display(lis *first,char ch);
lis *in_first(lis *first);
void insert(lis *first,char data[20]);
lis *rem(lis *first,char data[20]);

void main()
{
	int c;
   char ch,data[20];
   lis *first,*end;
   do
   {
   	clrscr();
   	c=menu();
      if (c<1 ||c>5)
      {
      	printf("\n\tChoice wrong. Please check it.\n");
      }
      switch(c)
   	{
   		case 1:
      		first=(lis*) malloc(sizeof(lis));
         	first->before=null;
         	end=create(first);
         	break;

         case 2:
         	printf("\n\n\t\tDisplay forward or reverse link list. Press (f/r). ");
      		ch=tolower(getch());
      		if (ch=='f')
          		display(first,ch);
            else
            	display(end,ch);
            getch();
            break;

         case 3:
         	first=in_first(first);
            break;

         case 4:
         	printf("\n\n\tEnter the data before you want to insert.If at the end type end. ");
            scanf("%s",data);
            insert(first,data);
            break;

         case 5:
         	printf("\n\n\tEnter the item want to delete. ");
            scanf("%s",data);
            first=rem(first,data);
            break;
      }
      printf("\n\n\tWant to continue. Press (Y/N). ");
      ch=toupper(getch());
   }
   while (ch=='Y');
}
int menu()
{
	int c;
   printf("\n\n\tTo creat a list press '1'");
   printf("\n\n\tTo display the list press '2'");
   printf("\n\n\tto insert at begin press '3'");
   printf("\n\n\tTo insert a new item press between nodes '4'");
   printf("\n\n\tTo delete a item press '5'");
   printf("\n\n\tEnter choice=");
   scanf("%d",&c);
   return(c);
}

lis *create(lis *first)
{
	lis *end;
   printf("\n\n\tEnter item (if complete type (end))");
   scanf("%s",first->item);
   if(strcmp(first->item,"end")==0)
   {
   	first->next=null;
      end=first;
   }
   else
   {
   	first->next=(lis*) malloc(sizeof(lis));
      first->next->before=first;
      end=create(first->next);
   }
   return(end);
}

void display(lis *first,char ch)
{
	if(strcmp(first->item,"end")!=0)
   	printf("\n\n\t\t%s",first->item);
	if(ch=='f')
   {
   	if(first->next!=null)
      	display(first->next,ch);
   }
   else
   {
   	if(first->before!=null)
      	display(first->before,ch);
   }
}

lis *in_first(lis *first)
{
	lis *temp;
   temp=(lis*)malloc(sizeof(lis));
	printf("\n\n\tEnter the new item. ");
   scanf("%s",temp->item);
   temp->before=null;
   temp->next=first;
   first->before=temp;
   return(temp);
}

void insert(lis *first,char data[20])
{
	lis *temp;
   temp=(lis*)malloc(sizeof(lis));
   if(strcmp(data,first->next->item)==0)
   {
   	printf("\n\n\t\tEnter the new item.");
      scanf("%s",temp->item);
      temp->before=first;
      temp->next=first->next;
      first->next->before=temp;
      first->next=temp;
   }
   else
   {
   	if(first->next->next!=0)
      	insert(first->next,data);
      else
      	printf("\n\n\tThe data before you want to insert the new item is not in the list");
   }
}

lis *rem(lis *first,char data[20])
{
	if(strcmp(first->item,data)==0)
   {
   	first->next->before=first->before;
      return(first->next);
   }
   else
   {
   	if(first->next!=null)
      {
      	first->next=rem(first->next,data);
      	return(first);
      }
      else
      {
      	printf("\n\n\tThe data is not found .Please check it.");
         return(first);
      }
   }
}


