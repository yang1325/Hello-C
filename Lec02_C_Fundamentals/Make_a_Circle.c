#include <stdio.h>

#define PI 3.14f

int main(void){
    int r;
    float circum,area;
    scanf("%d",&r);
    circum=2*PI*r;
    area=PI*r*r;
    printf("%.2f %.2f",area,circum);
    return 0;
}