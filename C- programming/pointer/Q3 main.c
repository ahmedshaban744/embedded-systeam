#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
  char str[100];
  printf(" enter string:");
  gets( str);
  char *p;
 int y=  strlen(str);
  p=str+y;
 for( int i=y ;i>=0;i--)
 {
     printf("%c",*p);
     p--;
 }
    return 0;
}
