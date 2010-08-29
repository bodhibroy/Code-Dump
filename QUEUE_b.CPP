#include<stdio.h>
#include<alloc.h>
#include<conio.h>

typedef struct nodetype
{
	int data;
	struct nodetype *next;
}node;

node* init_queue(node *head)
{
	head=NULL;
	return head;
}

void print(node *head)
{
	if(head!=NULL)
	{
		printf("  %d",head->data);
		print(head->next);
	}
}

void menu()
{
	printf("\n\n1.Insert\n\n2.Remove\n\n3.Exit\n\n");
}

node* insert(node* head)
{
	if(head!=NULL)
		head->next=insert(head->next);
	else
	{
		int data;
		printf("\n\n\nEnter data:");
		scanf("%d",&data);
		head=(node*)malloc(sizeof(node));
		head->data=data;
		head->next=NULL;
	}
	return head;
}

node* remove(node *head)
{
	node* temp;
	temp=head;
	head=head->next;
	free(temp);
	return head;
}

void main()
{
	node *head;
	clrscr();
	head=init_queue(head);
	int ch;
	menu();
	printf("Enter choice:");
	scanf("%d",&ch);
	while(ch!=3)
	{
		if(ch==1)
		{
			head=insert(head);
			print(head);
		}
		else if(ch==2)
		{
			head=remove(head);
			print(head);
		}
		menu();
		printf("\n\n\n\nEnter choice:");
		scanf("%d",&ch);
	}
}
