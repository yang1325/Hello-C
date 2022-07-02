#include <stdio.h>

int main () {
    int h,i,j;
    scanf("%d",&h);
    for(i=1;i<h;i++){
        for(j=0;j<h-i;j++)
            printf(" ");
        for(j=1;j<i;j++)
            printf("OX");
        printf("O\n");}
    for(i=0;i<2*h-1;i++)
        printf("O");
    return 0;
}
