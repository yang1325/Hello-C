//loader code
#include<stdio.h>

int *poly(int*, int*, int*);

int main() {
    int a, b, c;
    int *A, *B, *C;
    scanf("%d %d %d", &a, &b, &c);
    A = &a;
    B = &b;
    C = &c;
    if (a < 0) A = NULL;
    if (b < 0) B = NULL;
    if (c < 0) C = NULL;

    int *result = poly(A, B, C);
    printf("%d", *result);
    return 0;
}

//mycode
int* poly(int* A, int* B, int* C) {
    int sum = 0;
    if(A != NULL)
        sum += (*A) * (*A) * (*A);
    if(B != NULL)
        sum += (*B) * (*B);
    if(C != NULL)
        sum += *C;
    if(A != NULL){
        *A =  sum;
        return A;
    }
    if(B != NULL){
        *B =  sum;
        return B;
    }
    else{
        C = &sum;
        return C;
    }
}