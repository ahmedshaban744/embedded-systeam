#include <stdio.h>
#include "a.h"
#include "b.h"

int main()
{
   s_c r;
   af(r);
   bf(r);
   return 0;
}
void  af(s_c p)
{
    printf("af");
}
void  bf(s_c p)
{
    printf("bf");
}

