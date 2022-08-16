#include <stdio.h>
#include <stdlib.h>
struct student {
 char name [50];
 int rall;
 float mark;
};
struct student read_data( char st[50]);
void print ( struct student);
int main()
{ struct student x;
x= read_data(" enter student data");
 print(x);

    return 0;
}
struct student read_data( char st[50])
{
 struct student y;
 printf( "%s\n ",st);
 printf("enter name:\t");
 scanf("%s",y.name);
 printf("enter rall:\t");
 scanf("%d",&y.rall);
 printf("enter mark:\t");
 scanf("%f",&y.mark);
  return y;
}
void print ( struct student y)
{     printf(" name %s\n rall %d\n  mark %f",y.name,y.rall,y.mark);

}

