#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x=0;
  int factrial =1 ;
  printf( "enter an positive number only");
  scanf("%d",&x);
  if(x>0)
  {

  for (int i=1; i<=x;i++)
  {


    factrial =factrial*i;

  }
   printf( "the factrial is %d:",factrial);
  }
  else
    printf ( "please inter an positive number") ;

    return 0;
}
