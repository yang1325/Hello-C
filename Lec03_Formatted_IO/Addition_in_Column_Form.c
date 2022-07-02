#include <stdio.h>

int main(void){
    int A,B;
    scanf("%d %d",&A,&B);
    printf("%6.4d\n",A);
    printf("+)%.4d\n",B);
    printf("------\n");
    printf("%.6d",A+B);
    return 0;
}