
									    /*QUICK SORT*/

# include <stdio.h>
# include <conio.h>
# include <stdlib.h>

void sort(int *a,int start,int end,int n);

void main()
{
	int n,*a,i;
   printf("\n\n\tEnter the no of element=");
   scanf("%d",&n);
   a=(int*)malloc(n*sizeof(int));
   printf("\n\n\tEnter the no one after another=\n\n\t");
   for(i=0;i<n;i++)
   	scanf("%d",&a[i]);
   sort(a,0,n-1,n);
   printf("\n\n\tThe sorted array=\n\n\t");
   for(i=0;i<n;i++)
   	printf("%d  ",a[i]);
   getch();
}

void sort(int *a,int start,int end,int n)
{
	int up,down,temp,i,k;
   up=end;
   down=start;
   while(up>down)
   {
   	for(i=down;i<=end;i++)
      	if(a[i]>a[start])
          	break;
      down=i;
      for(i=up;i>=start;i--)
        	if(a[i]<=a[start])
        		break;
      up=i;
      if(up>down)
      {
      	temp=a[up];
         a[up]=a[down];
         a[down]=temp;
         for(k=0;k<n;k++)
   		printf("%d ",a[k]);
      	printf("\n");
   		getch();
      }
   }
   temp=a[up];
   a[up]=a[start];
   a[start]=temp;
   for(k=0;k<n;k++)
   	printf("%d ",a[k]);
   printf("\n");
   getch();
   if(up-start>1)
   	sort(a,start,up-1,n);
   if(end-up>1)
   	sort(a,up+1,end,n);
}