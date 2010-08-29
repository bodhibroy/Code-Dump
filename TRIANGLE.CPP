#include<stdio.h>
#include<conio.h>

void main()
 {
 int i,j,n,flag=0;
 clrscr();
 printf("\n Enter the no of lines:");
 scanf("%d",&n);

 printf("%d",1);
 for(i=2;i<=n;i++)
  {
  printf("\n");
  for(j=0;j<i;j++)
    {
       if(i%2!=0 && j==0)
		{
		if(flag==0)
				flag=1;
		else
				flag=0;
		}
	if(flag==0)
		{
		   printf("%d",0);
		   flag=1;
		}
	else
		{
		   printf("%d",1);
		   flag=0;
		}
    }
   }
 getch();
 }

