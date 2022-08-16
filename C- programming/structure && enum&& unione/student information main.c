#include <stdio.h>
#include <stdlib.h>
struct student {
 char name [50];
 int rall;
 float mark;
};
int main()
{
  struct student x[10];
  for ( int i=0;i<10;i++)
  {

 printf("enter student %d rall \t",i+1);
 scanf("%d",&x[i].rall);
 printf("enter name\t");
 scanf("%s",x[i].name) ;
  printf("enter mark \t");
 scanf("%f",&x[i].mark);
  printf("\r\n");
  }
  for ( int i=0;i<10;i++)
  {
    printf(" Rall%d \n name %s \n  mark%f ",x[i].rall,x[i].name,x[i].mark)  ;
     printf("\r\n");
  }


}




