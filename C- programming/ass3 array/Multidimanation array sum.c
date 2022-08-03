#include <stdio.h>
#include <stdlib.h>

int main()
{
    float arr1 [2][2];
    float arr2 [2][2];
float sum [2][2];
printf("enter the elements of 1st matrix \n");
  for (int r=0;r<=1;r++)
  {
      for ( int c=0; c<=1;c++)
      {
          printf("enter arr1 %d ,%d \t" ,r,c );
          scanf("%f" ,&arr1[r][c]);

      }
  }
  printf("enter the elements of 2st matrix \n");
  for (int r=0;r<=1;r++)
  {
      for ( int c=0; c<=1;c++)
      {
          printf("enter arr1 %d ,%d \t" ,r,c );
          scanf("%f" ,&arr2[r][c]);

      }
  }

  for (int r=0;r<=1;r++)
  {
      for ( int c=0; c<=1;c++)
      {
         sum[r][c]=arr1[r][c]+arr2[r][c];

      }

  }
  printf(" the sum is \n");
  for (int r=0;r<=1;r++)
  {
      for ( int c=0; c<=1;c++)
      {
        printf("%f \t" ,sum[r][c]);

      }
printf ("\r\n");
  }




    return 0;
}
