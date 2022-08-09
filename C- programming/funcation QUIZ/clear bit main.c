#include <stdio.h>
#include <stdlib.h>
int cle (int a,int b);
int main()
{ int a=0;
printf("enter the number");
scanf("%d",&a);
int b=0;
printf("enter bit posiation");
scanf("%d",&b);
int y=cle (a,b);
printf("%d",y);

return 0;

}
int cle (int a,int b)
{
return a&=~(1<<b);
}
