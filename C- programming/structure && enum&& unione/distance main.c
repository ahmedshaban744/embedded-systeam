#include <stdio.h>
#include <stdlib.h>
struct dist
{
int feet;
float inch;
};
struct dist reed_data( char name[50]);
struct dist add ( struct dist x ,struct dist y);
void print ( struct dist z);
int main()
{
  struct dist x ,y ,z;
 x=  reed_data("enter information for  1st distant" );
 y=reed_data("enter information for  2st distant");
 z= add(x,y);
 print(z);
    return 0;
}
struct dist reed_data( char name[10])
{struct dist x;
printf("%s \n",name);
printf("enter feet \t");
scanf("%d",&x.feet);
printf("enter inche \t");
scanf("%f",&x.inch);
return x;
}
struct dist add ( struct dist x ,struct dist y)
{struct dist z;
z.feet=x.feet+y.feet;
z.inch=x.inch+y.inch;
if(z.inch>12.00)
{
    z.inch-=12.00;
    z.feet++;
}
return z;
}
void print ( struct dist z)

{
    printf(" sum of distant is \t %d -  %f",z.feet,z.inch);

}



