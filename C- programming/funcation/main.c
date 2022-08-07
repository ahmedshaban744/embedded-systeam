#include <stdio.h>
#include <stdlib.h>
int num (int a );
int main()
{
    int x =0;
    int y=0;

    printf( "enter the numders ");
    scanf ("%d %d",&x,&y);
  printf( "the prime number between %d and %d is \n",x,y);
    for ( int i=x; i<=y;i++)
    {
        int z= num(i);
    if (z==0)
        printf("%d \n",i);
    }

    return 0;
}
int num (int a )
{ int z=0;
for( int j=2; j<=a/2 ;j++)
{
    if ( a%j==0)
    {

z=1;
break;
    }
}

return z;


}


