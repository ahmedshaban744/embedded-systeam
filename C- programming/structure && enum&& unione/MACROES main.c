#include <stdio.h>
#include <stdlib.h>
#define pi 3.1415
#define area(r)(pi*(r)*(r))
int main()

{
    int red;
    float area;
    printf(" enter reduic");
    scanf("%d",&red);
    area=area(red);
    printf("area =%f", area);
    return 0;
}
