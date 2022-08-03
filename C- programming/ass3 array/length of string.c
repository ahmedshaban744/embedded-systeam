
    #include <stdio.h>
#include <stdlib.h>

int main()
{


   char st[1000];
   printf(" enter  the string \n");
    fgets(st, sizeof(st), stdin);


   int num =strlen(st);

  printf("Name length: %u", num-1);

    return 0;
}


