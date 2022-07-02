#include<stdio.h>

int main () {
    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    A=A+B+C;
    B=A/7;
    C=A%7;
    printf("%d %d",B,C);
    return 0;
}