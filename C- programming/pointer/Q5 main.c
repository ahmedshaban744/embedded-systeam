#include <stdio.h>
#include <stdlib.h>
struct employ{
 char *em_name;
 int em_id;
};
int main()
{
    struct employ emp1={ "ahmed",1001};
     struct employ emp2={ "alex",1002};
     struct employ emp3={ "mohamed",1003};
     struct employ (*array[])={&emp1,&emp2,&emp3};;
     struct employ(*(*p)[3])=&array;

    printf("name \t%s \n",(**(*p+1)).em_name);
      printf("id \t %d",(*(*p+1))->em_id);
    return 0;
}
