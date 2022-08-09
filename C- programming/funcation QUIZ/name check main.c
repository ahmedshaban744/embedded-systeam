#include <stdio.h>
#include <stdlib.h>
//void rev ( int a);
int main()
{
    char str1 [ 100];
     char str2 [ 100];

printf("enter the string \n");
gets(str1);

printf("enter your name\n");
gets(str2);
 int x=strcmp (str1,str2);
 if (x==0)
    printf( "pass");
 else
   printf( " not pass");

return 0;
}
