#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1 [10];
int arr2 [10];
int arr3 [10];
int a=0;
printf("enter the size of the arrays");
scanf("%d",&a);

for(int i =0;i<5;i++)
{
printf("enter the array1 index %d \t",i+1);
scanf("%d",&arr1[i]);
printf("\r\n");
}
for(int i =0;i<a;i++)
{
printf("enter the array2 index %d \t",i+1);
scanf("%d",&arr2[i]);
}
for(int i =0;i<a;i++)
{
   arr3[i]=arr1[i];
}
for(int i =0;i<a;i++)
{
   arr1[i]=arr2[i];
}
for(int i =0;i<a;i++)
{
   arr2[i]=arr3[i];
}
printf(" array 1 is");
for(int i =0;i<a;i++)

printf(" %d \t",arr1[i]);
printf("\r\n");
printf(" array 1 is");
for(int i =0;i<a;i++)

printf(" %d \t",arr2[i]);



    return 0;
}
