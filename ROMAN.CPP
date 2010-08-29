#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
 int i,a,b,c,d,x;
 char val[15],post[15];
 val[0]=post[0]='\0';

 //clrscr();

 printf("\nEnter the number<The number must be a two digit number>:");
 scanf("%d",&x);

 if(x>=50)
   {
	strcat(val,"L");
	a=x-50;
   }
 else
	a=x;

 b=a/10;
 for(i=0;i<b;i++)
	strcat(val,"X");

 c=a%10;
 if(c>=5 && c<=9)
   {
	strcat(post,"V");
	d=c-5;
   }
  else
	d=c;
  for(i=0;i<d;i++)
	strcat(post,"I");

 strcat(val,post);
 printf("\n\nThe number in roman digit is:");
 puts(val);

 getch();
 return(0);
}
