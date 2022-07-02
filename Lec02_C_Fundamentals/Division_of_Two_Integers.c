#include <stdio.h>

int main(void){
    int a,b;
    float c,d;
    scanf("%d %d",&a,&b);
    a=a*10000;
    c=a/b;
    c=c/10000;
    a=a*10;
    d=a/b;
    d=d/100000;
    printf("%.1f %.2f",c,d);
    return 0;
}