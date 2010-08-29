#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct nodetype
{
	char data;
	struct nodetype *next;
}node;

void create(node *a)
{
	printf("\n Enter the string <Press " " if you want to exit>:");
	fflush(stdin);
	scanf("%c",&(a->data));

	if(a->data==' ')
		a->next='\0';
	else
		{
		a->next=(node*)malloc(sizeof(node));
		create(a->next);
		}
}

void show(node *b)
{
	if(b!='\0')
	{
		printf("%c",b->data);
		show(b->next);
	}
}

node *reverse(node *a)
 {
 node *p,*t,*y;
 p=a;
 t=a->next;
 y=a->next->next;

 while(t!='\0')
  {
	t->next=p;
	p=t;
	t=y;
	y=y->next;
  }
  a->next='\0';
  return(p);
 }

/*void zigzag(node *a,node *b)
{
	node *temp1,*temp2;
	if(temp1->next!='\0')
	{
		temp1=a->next;
		a->next=b->next;
		temp2=b->next->next;
		b->next->next=temp1->next;
		zigzag(temp1->next,temp2->next);
	}

	show(a);
}*/

void main()
{
	node *a,*b,*c;
	int ch,data;

	clrscr();

	printf("\n Press 1 to create 1st data structure:");
	printf("\n Press 2 to print the data structure:");
	printf("\n Press 3 to reverse the data structure:");
	printf("\n Press 4 to exit:");

	while(1)
	{
		printf("\n\n Enter your choice:");
		scanf("%d",&ch);

	switch(ch)
	{
		case 1:

		{
			a=(node*)malloc(sizeof(node));
			create(a);
			break;
		}
		case 2:
		{
			printf("\n The data structure is:\n");
			printf("\n");
			show(a);
			break;
		}
		case 3:
		{
			c=reverse(a);
			show(c);
			break;
		}
		default:
			exit(0);
	}
 }

	getch();
 }

