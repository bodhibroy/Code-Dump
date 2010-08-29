
                        		/*SELECTION SORT*/

# include <stdio.h>
# include <conio.h>
# include <stdlib.h>

void main()
{
	int *x,n,i,j,temp;
   printf("\n\n\tEnter the no. element=");
   scanf("%d",&n);
   x=(int*)malloc(n*sizeof(int));
   printf("\n\n\tEnter the ele.=\n\n\t");
   for(i=0;i<n;i++)
   	scanf("%d",&x[i]);
   for(i=0;i<n-1;i++)
   {
   	temp=i;
   	for(j=i+1;j<n;j++)
      {
      	if(x[temp]>x[j])
         	temp=j;
      }
      if(temp!=i)
        	x[temp]=(x[i]+x[temp])-(x[i]=x[temp]);
   }
   printf("\n\n\tThe sorted array=\n\n\t");
   for(i=0;i<n;i++)
   	printf("%d  ",x[i]);
   getch();
}