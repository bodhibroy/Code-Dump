
                        		/*INSERTION SORT*/

# include <stdio.h>
# include <conio.h>
# include <stdlib.h>

void main()
{
	int *x,n,i,j,k,temp;
   printf("\n\n\tEnter the no. element=");
   scanf("%d",&n);
   x=(int*)malloc(n*sizeof(int));
   printf("\n\n\tEnter the ele.=\n\n\t");
   for(i=0;i<n;i++)
   	scanf("%d",&x[i]);
   for(i=1;i<n;i++)
   {
   	for(j=0;j<i;j++)
      {
      	if(x[j]>x[i])
         {
         	temp=x[i];
         	for(k=i;k>=j+1;k--)
            	x[k]=x[k-1];
            x[j]=temp;
            break;
         }
      }
   }
   printf("\n\n\tThe sorted array=\n\n\t");
   for(i=0;i<n;i++)
   	printf("%d  ",x[i]);
   getch();
}