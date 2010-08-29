#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
//#include<string.h>

// Structure definition  for differrent Streams
typedef struct pre
{
	struct nodetype *next[3];
}first;

//Structure definition for  trie containing roll number, names and YGPA
typedef struct nodetype
{
	//char *name[10];
	int ygpa[10];
	struct nodetype *next[10];
}node;

node* create(node *x,int roll[3],int count)
{
	int i,y;
	//char *n;
	if(count<3)
	{
		if(x==NULL)
			x=(node*)malloc(sizeof(node));


		for(i=0;i<10;i++)
		{
			x->ygpa[i]=0;
			//x->name[i]=NULL;

		}
		x->next[roll[count+1]]=create(x->next[roll[count+1]],roll,count+1);
	}
	if(count==2)
	{
	  //	printf("Enter Name:");
	    //	gets(n);
	   //	strcpy(*(x->name[i]),*n);
		printf("\n\n\nEnter YGPA:");
		scanf("%d",&y);
		x->ygpa[i]=y;
	}
	return x;
}

void main()
{
	int j,f,r[3],roll,m;
	char stream,choice;
	first *p;  // structure type defining streams
	node *c,*e,*i,*temp;   // structure type defining trie

	//clrscr();

	p=(first*)malloc(sizeof(first));


	for(j=0;j<3;j++)
		p->next[j]='\0';

	choice='y';

	while(choice=='y' || choice=='Y')
	{
		printf("\n Enter your stream(C/E/I):");
		scanf("%c",&stream);
		printf("\n Enter your roll number:");
		scanf("%d",&roll);
		//Extracting roll numbers
		f=roll%100;
		r[0]=roll/100;
		r[1]=f/10;
		r[2]=f%10;
		if(stream=='c' || stream=='C')
		{
			c=create(c,r,0);
			if(p->next[0]==NULL)
				p->next[0]=c;
		}
		else if(stream=='e'|| stream=='E')
		{
			e=create(e,r,0);
			if(p->next[1]==NULL)
				p->next[1]=e;
		}
		else if(stream=='i' || stream=='I')
		{
			i=create(i,r,0);
			if(p->next[2]==NULL)
				p->next[2]=i;
		}
		printf("\n Do you want to continue?(y/n):");
		scanf("%c",&choice);
	}
	getch();
}
