#include <stdio.h>
#include <stdlib.h>

int main()
{
  int  a=0;
  int  c=0;
  int i;
   printf( "enter the decimal number");
   scanf("%d",&a);
   for(  i=32; i>=0;i--)
   {
       c=a>>i;
       if (c&1)
        printf("1");
       else
    printf("0");
   }
   printf("\r\n");
  c=a>>3;
if (c&1)
        printf(" 4th 1ast significant bit is 1");
       else
    printf("4th 1ast significant bit is 0");

    return 0;
}
