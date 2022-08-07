#include <stdio.h>
#include <stdlib.h>
 int powe(int x,int y);
int main()
{ int a=0;
int b=0;
   int y=0;

    printf("enter the  base and the number \n:");

    scanf("%d  %d",&a,&b);
printf("the power is:");

      y=powe(a ,b );
    printf("%d",y);
    return 0;
}
 int powe (int x, int y)
 { if ( y!=0)
 return (x*powe( x,y-1));
 else
    return 1;
 }


