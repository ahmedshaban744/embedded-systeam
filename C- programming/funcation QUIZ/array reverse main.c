#include <stdio.h>
#include <stdlib.h>
void rev ( int arr1[],int arr2[],int n);
int main()
{
    int a=0;
    int arr1 [100];
int arr2[100];
 printf("enter the size of the array\n");
scanf("%d",&a);
   printf("enter the array \n");
for(int i =0;i<a;i++)
{
    printf("enter the array index %d \t",i+1);

    scanf("%d",&arr1[i]);
}
 printf("the reverse is\n");

 rev (  arr1,  arr2,  a);
 return 0;
}
void rev ( int arr1[],int arr2[],int n)
{
  for(int i =0;i<n;i++)
  {
      arr2[i]=arr1[n-i-1];
  }
  for(int i =0;i<n;i++)
    printf("%d \t",arr2[i]);

}


