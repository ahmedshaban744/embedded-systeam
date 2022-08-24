#include <stdio.h>
#include <stdlib.h>
int main()
{  int *p;
    int size =0;
printf("enter array size \t");
scanf("%d",&size);
int array[size];
for( int i=0 ;i<size;i++)
 {
     printf("enter array index%d \t",i+1);
     scanf("%d",&array[i]);
     *p++;
 }


  p=array+size-1;
 for( int i=size;i>0;i--)
 {
     printf(" index number%d =%d \n",i,*p);
     p--;
 }
    return 0;
}
