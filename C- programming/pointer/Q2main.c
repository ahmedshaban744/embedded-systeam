#include <stdio.h>
#include <stdlib.h>

int main()
{
char alph[27];
int x;
char *ptr;
ptr=alph;
for ( int i=0;i<26;i++)
{
    *ptr=i+'A';
    ptr++;
}
ptr=alph;
for ( int i=0;i<26;i++)
{

    printf("%c\t",*ptr);
    ptr++;

}
    return 0;
}
