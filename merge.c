# include <stdio.h>
# include <conio.h>
# include <stdlib.h>

void main()
{
	int *a,*b,*c;
   int n1,n2,i,j,temp,flag,count;
   printf("\n\n\tEnter the no. of ele. of first list=");
   scanf("%d",&n1);
   a=(int*)malloc(n1*sizeof(int));
   printf("\n\n\tEnter the elements of 1st list=");
   for(i=0;i<n1;i++)
   	scanf("%d",&a[i]);
   printf("\n\n\tEnter the no. of ele. of second list=");
   scanf("%d",&n2);
   b=(int*)malloc(n2*sizeof(int));
   printf("\n\n\tEnter the elements of 2nd list=");
   for(i=0;i<n2;i++)
   	scanf("%d",&b[i]);
   c=(int*)malloc((n1+n2)*sizeof(int));
   for(i=0,count=0;i<n1;i++)
   {
   	for(j=0,flag=0;j<count;j++)
      	if(c[j]==a[i])
         	flag=1;
      if(flag!=1)
      {
      	c[count]=a[i];
         count++;
      }
   }
   for(i=0;i<n2;i++)
   {
   	for(j=0,flag=0;j<count;j++)
      	if(c[j]==b[i])
         	flag=1;
      if(flag!=1)
      {
      	c[count]=b[i];
         count++;
      }
   }
   for(i=0;i<count;i++)
   {
   	for(j=(i+1);j<count;j++)
      {
      	if(c[i]>c[j])
         {
         	temp=c[i];
            c[i]=c[j];
            c[j]=temp;
         }
      }
   }
   printf("\n\n\tAscending order sorting=");
   for(i=0;i<count;i++)
   	printf("\n\n\t\t%d",c[i]);
   getch();
}
