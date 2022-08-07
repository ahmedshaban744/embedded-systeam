#include <stdio.h>
#include <stdlib.h>
int fact ( int a);
int main()

{ int x=0;
printf ("enter the number to cal thr factoral \n");
scanf("%d" ,&x);
 int y=fact (x);
 printf("%d" ,y);

    return 0;
}
int fact ( int a)
{
    if (a!=1)
return a*fact(a-1) ;
}
