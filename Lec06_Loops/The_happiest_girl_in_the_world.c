#include<stdio.h>

int main () {
    int h,t=0;
    scanf("%d",&h);
    h=h*10;
    while(h>49*t*t){
        printf("%.1f\n",(h-49*t*t)/10.0);
        t++;}
    return 0;
}