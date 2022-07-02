#include<stdio.h>

int main () {
    long long A,B;
    scanf("%llx-%llx",&A,&B);
    printf("%lx %lx",A,B);
    if(A+B>=65536)
        printf("OVERFLOW!");
    else
        printf("%ld",A+B);
    return 0;
}
