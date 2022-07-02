//loader code
#include<stdio.h>

void addition();

void print_binary(void *n){
    for(int i = 31; i >= 0; --i){
        printf("%d", (*(int *)n >> i) & 1);
        if (i && !(i % 8)) printf(" ");
    }
}

int main(){
    addition();
    return 0;
}

//mycode
void addition(){
    long long a, b, A , Af = 0, B = 0, Bf = 0, S, d = 256, ff, fa, fb;
    ff = d * d * d / 2;
    A = ff * 127;
    B = ff * 127;
    scanf("%lld %lld", &a, &b);
    fa = a;
    fb = b;
    if(a < 0){
        A += d * ff;
        a = -a;
    }
    if(b < 0){
        B += d * ff;
        b = -b;
    }
    if(a == 0)
        A = 0;
    if(b == 0)
        B = 0;    
    while(a > 1){
        A += ff;
        Af /= 2;
        Af += (a % 2) * ff / 2;
        a /= 2;
    }
    while(b > 1){
        B += ff;
        Bf /= 2;
        Bf += (b % 2) * ff / 2;
        b /= 2;
    }
    A = A + Af;
    B = B + Bf;
    S = A + B;
    S %= d * ff*2;
    if(S >= d * ff)
        S = S - d * ff * 2 ;
    printf("   ");    
    print_binary(&A);
    printf("\n+) ");
    print_binary(&B);
    printf("\n---------------------------------------\n   ");
    print_binary(&S);
    printf("\n%lld + %lld = %lld", fa, fb, S);
}