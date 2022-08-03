#include <stdio.h>
#include <stdlib.h>

int main()
{float x=0;
float y=0;
float z=0;



printf ("enter the numbers ");
scanf("%f %f %f" ,&x,&y,&z);
if( x>=y&&x>=z)
    printf ("the largest number is :%f" ,x );
else if ( y>=x&&y>=z)
    printf ("the largest number is :%f" ,y );
 else
    printf ("the largest number is :%f" ,z );

    return 0;
}
