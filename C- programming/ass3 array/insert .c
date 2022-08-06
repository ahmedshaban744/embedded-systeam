#include <stdio.h>
#include <stdlib.h>

int main()
{int x ,y ,z=0;
printf( "enter the no of element\n");
scanf( "%d",&x);
int arr[x];
for( int i=0; i<x ;i++)
scanf( "%d" ,&arr[i]);
for( int i=0; i<x ;i++)
printf( "%d \t" ,arr[i]);

printf( " \n enter the  element to insert \n");
scanf( "%d",&y);

printf( " \n enter the location\n");
scanf( "%d",&z);

  for (int i = x; i >= z ;i--)
  {

        arr[i] = arr[i-1 ];
  }
  x++;

 arr[z-1]=y;


 for( int i=0; i<x ;i++)
printf( "%d \t" ,arr[i]);




        return 0;
}
