# include <stdio.h>
# include <conio.h>
# include <dos.h>

int sear(int a[],int l,int h,int no);

void main()
{
	int a[10],i,p,no;
   for(i=0;i<10;i++)
   	scanf("%d",&a[i]);
   printf("\n\n\tEnter the no. for search=");
   scanf("%d",&no);
   p=sear(a,0,9,no);
   delay();
   if(p!=-1)
   	printf("\n\n\tThe position of the no. %d =%d",no,(p+1));
   else
   	printf("\n\n\tThe no. is not found in the list.");
   getch();
}

int sear(int a[],int l,int h,int no)
{
	int m;
   m=l+((h-l)/2);
   if(a[m]==no)
   	return(m);
   if((a[m]>no)&&(a[m-1]<no))
   	return(-1);
   if(a[m]>no)
   	m=sear(a,l,m-1,no);
   else
   	m=sear(a,m+1,h,no);
   return(m);
}