#include <stdio.h>
#include <stdlib.h>

int main()
{
   int m=29;
   int*p= &m;
   printf(" the address of m=%p \t the value of m=%d",p,*p );
   int **pp=&p;
   *p=29;
     printf("  \n the address of ab=%p \t the value of ab=%d",p,*p );
 *p=34;
     printf("  \n the address of ab=%p \t the value of ab=%d",p,*p );
    *p=7;
       printf("  \n the address of ab=%p \t the value of m=%d",p,*p );
    return 0;
}
