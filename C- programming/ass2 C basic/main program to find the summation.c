#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x=0;
  int sum =0 ;
  printf( "enter the nature number");
  scanf("%d",&x);
  for (int i=0; i<=x;i++)
    sum=sum+i;
 printf( "the sum is %d:",sum);
    return 0;
}
