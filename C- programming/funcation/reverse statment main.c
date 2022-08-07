#include <stdio.h>
#include <stdlib.h>
void rev ( );
int main()
{
   printf("enter the ststment \n");
   rev ();
    return 0;
}
void rev ( )
{
    char c=0;
    scanf("%c" ,&c);
    if (c!= '\n')
    {
        rev();
        printf("%c",c);
    }

}

