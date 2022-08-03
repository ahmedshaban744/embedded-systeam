#include <stdio.h>
#include <stdlib.h>

int main()
{int x ,y =0;
printf( "enter the no of element\n");
scanf( "%d",&x);
int arr[x];
for( int i=0; i<x ;i++)
scanf( "%d" ,&arr[i]);
for( int i=0; i<x ;i++)
printf( "%d \t" ,arr[i]);

printf( " \n enter the  number  to search \n");
scanf( "%d",&y);

 for( int i=0; i<=x ;i++)

{

    if (y==arr[i])
    {


        printf( "  the number is found %d  \n " );
          printf( "  %d  "  ,i+1);
         return 0;

    }
}


          printf( " \n the number not found \n");



        return 0;
}
