#include<stdio.h>
#include<conio.h>
void main()
{
int i=3,*x;
float j=1.5,*y;
char k='c',*z;
clrscr();


printf("\nValue of i=%d",i);
printf("\nValue of j=%d",j);
printf("\nValue of k=%c",k);
x=&i;
y=&j;
z=&k;


printf("\nOriginal address in x=%u",x);
printf("\nOriginal address in y=%u",y);
printf("\nOriginal address in z=%u",z);
x++;
y++;
z++;



printf("\nNew address in x=%u",x);
printf("\nNew address in y=%u",y);
printf("\nNew address in z=%u",z);


getch();




}

