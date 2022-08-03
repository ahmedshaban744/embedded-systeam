#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x, y ,tem =0;

    printf( "enter two number");
    scanf( "%f",&x);
    printf( "enter two number");
     scanf( "%f",&y);
     tem=x;
    x=y;
    y=tem;
    printf( "%f",x);
     printf( "%f",y);


    return 0;
}
