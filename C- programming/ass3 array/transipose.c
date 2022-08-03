#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x=0;
  int y=0;
  int a[10][10];


   printf("Enter rows and columns: ");
  scanf("%d %d", &x, &y);

  for (int r=0 ; r<x;r++)
  {
       for (int c=0 ;c<y;c++)
       {
           printf( "enter the number (%d , % d):",r,c);
           scanf ( "%d" ,&a[r][c]);

       }
  }
  printf(" the matrix is\n");
  for (int r=0 ; r<x;r++)
  {
       for (int c=0 ;c<y;c++)
       {
           printf( " %d \t",a[r][c]);

       }
        printf(" \r\n");

  }
    printf(" the inverse is\n");

   for (int r=0 ; r<y;r++)
  {
       for (int c=0 ;c<x;c++)
       {
           printf( " %d \t",a[c][r]);

       }
        printf(" \r\n");


}
}
