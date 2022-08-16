#include <stdio.h>
#include <stdlib.h>
struct comp
{float real;
float imag;
};
struct comp read ( char type[ 30]);
struct comp add (struct comp x, struct comp y );
void print( struct comp z);
int main()
{
struct comp x,y,z;
x=read(" enter 1st complex number");
y=read("enter 2st complex number");
z= add(x,y);
print(z);
    return 0;
}
struct comp read ( char type[ 30])
{
struct comp x;
printf("%s \n",type);
printf( "enter the real part");
scanf("%f",&x.real);
printf( "enter the imagnary part");
scanf("%f",&x.imag);
return x;
}
struct comp add (struct comp x, struct comp y )
{ struct comp z;
z.real=x.real+y.real;
z.imag=x.imag+y.imag;
return z;
}
void print( struct comp z)
{
    printf("%f +j %f",z.real,z.imag);
}



