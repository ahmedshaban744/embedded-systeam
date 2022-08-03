#include <stdio.h>
#include <stdlib.h>

int main()
{ int num =0;
   char x=0;
   char st[1000];
   printf(" enter  the string \n");
    fgets(st, sizeof(st), stdin);
        printf(" enter  the caracter \n");
   scanf( "%c" ,&x);

   for ( int i=0; i<1000;i++)
   {
       if ( st[i]==x)

       num+=1;
   }

   printf ("tne freq %d" ,num);
    return 0;
}
