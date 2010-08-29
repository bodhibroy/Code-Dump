#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


int roll[5];
char temp[6];

FILE *fp;


//Structure definition for  trie containing roll number, names and YGPA
typedef struct nodetype
{
	int join[10][2];
	float ygpa[10];
	char name[10][15],surname[10][20],r_db[10][6];
	struct nodetype *next[10];
}node;

void print(node* p,int level)
{
	int i,flag=0;
	if(p!=NULL)
	{
		for(i=0;i<10;i++)
		{
			if(level==0 && p->next[i]!=NULL)
			{
				if(i==0)
					printf("CSE\n\n");
				else if(i==1)
					printf("ECE\n\n");
				else printf("IT\n\n");
			}
			print(p->next[i],level+1);

			if(level==6 && flag==0)
			{
				printf("  Name:%s   Surname: %s   Year: %d%d",p->name[0],p->surname[0],p->join[0][0],p->join[0][1],p->r_db[0][0],p->r_db[0][1]);
				printf("  Roll:");
				for(int k=0;k<3;k++)
					printf("%c",p->r_db[0][k+2]);

				printf("   YGPA: %f\n\n",p->ygpa[0]);
				flag=1;

			}   // end of if
		}        // end of for
	}           // end of if
}

node* create(node *p,int level)
{
	int i;
	float y;
	if(level<6)
	{

		if(p==NULL)
		{
			p=(node*)malloc(sizeof(node));
			for(i=0;i<10;i++)
			{
				p->next[i]=NULL;
			}
		}

		p->next[roll[level-1]]=create(p->next[roll[level-1]],level+1);
	}
	if(level==6)
	{
		fp=fopen("data.txt","ab+");

		p=(node*)malloc(sizeof(node));
		printf("\n Enter YGPA:");
		scanf("%f",&(p->ygpa[0]));

		printf("\n Enter name:");
		scanf("%s",&(p->name[0]));

		printf("\n Enter surname:");
		scanf("%s",&(p->surname[0]));
		// Year of Joining

		p->join[0][0]=roll[0];
		p->join[0][1]=roll[1];

		//Roll Number
		strcpy(p->r_db[0],temp);

		for(i=0;i<10;i++)
			p->next[i]=NULL;

		fwrite(&p,sizeof(p),1,fp);
		fclose(fp);

	}
	return p;
}



int main()
{
	int j,stream;
	float roll_int,val;
	char r1[5];
	node *p,*c,*e,*i;   // structure type defining trie
	p=c=e=i=NULL;
	//clrscr();

	p=(node*)malloc(sizeof(node));


	for(j=0;j<10;j++)
	{
		p->next[j]=NULL;
		p->ygpa[j]=0;
	}


	for(int k=0;k<1;k++)
	{
		val=10000;


		printf("\n Enter your roll number:");
		scanf("%s",&temp);

		stream=temp[0];

		strcpy(r1,temp+1);

		roll_int=atof(r1);

		j=0;
		while(roll_int!=0)
		{
			roll[j]=roll_int/val;
			roll_int=roll_int-(val*roll[j]);
			val/=10;
			j++;
		}

		if(stream=='c' || stream=='C')
		{
			c=create(c,1);
			if(p->next[0]==NULL)
				p->next[0]=c;
		}
		else if(stream=='e' || stream=='E')
		{
			e=create(e,1);
			if(p->next[1]==NULL)
				p->next[1]=e;
		}
		else if(stream=='i' || stream=='I')
		{
			i=create(i,1);
			if(p->next[2]==NULL)
				p->next[2]=i;
		}
	}

	print(p,0);
	fp=fopen("data.txt","rb");
	while(fread(&p,sizeof(p),1,fp)>=1)
		printf(" \n\n  %f  %s  %s %s ",p->ygpa[0],p->name[0],p->surname[0],p->r_db[0]);
	getch();
	return 0;
}


