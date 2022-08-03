#include <stdio.h>
#include <stdlib.h>

int main()
{
int sum=0;
    int x=0;
    printf ( "enter the number of data %d \n",x);
    scanf("%d",&x);
float arr[x];
for ( int i=0; i<x ;i++)
{
   printf ( "enter the number %d \n",i);
    scanf("%f",&arr[i]);

}
for ( int i=0; i<x ;i++)
{
  sum=sum+arr[i];

}
 printf ( "the average is %f\t", (float )sum/x);
// explicet casting becouse sum is decleration in integar
    return 0;
}
