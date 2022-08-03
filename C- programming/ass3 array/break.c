#include <stdio.h>
#include <stdlib.h>

int main()
{
int n= 0;
int y=0;
int  sum=0;
printf("enter the number of numbers \t");
scanf( "%d",&n);
for (int i=0 ;i<n;i++)
{
  printf("enter the number\r\n ");
scanf( "%d",&y);
sum =sum+y;
if ( y<0)
    break;
//printf( "the average is %f",sum/n);
}
printf( "the average is % .2f", (float)sum/n);

    return 0;
}
