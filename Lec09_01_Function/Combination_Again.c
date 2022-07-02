#include <stdio.h>

int main(void){
    unsigned long long i=1,c=1,m,n;
    scanf("%lld %lld",&m,&n);
    while(m>n)
        c=(c*m--)/i++;
    printf("%lld",c);
    return 0;
}