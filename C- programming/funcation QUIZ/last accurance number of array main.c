#include <stdio.h>
#include <stdlib.h>
int acc ( int arr [],int a);
int main()
{
    int arr [100];
 int a=0;
printf("enter the size of the array");
scanf("%d",&a);
for(int i =0;i<a;i++)
{
    printf("enter the array index %d \t",i+1);

    scanf("%d",&arr[i]);
}
    int y =acc( arr,a);
    printf("%d",y);
 return 0;
}



int acc ( int arr [],int a)
{ int x =0;
int i;
printf("enter the number you want to accurance ");
scanf("%d",&x);
   for( i =a;i>0;i--)
   {
    if (arr[i]==x)
       return i+1;

}
    return -i;
}


