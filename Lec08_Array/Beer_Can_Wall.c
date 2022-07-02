#include <stdio.h>

int main () {
    unsigned long long v,c=1,sum=1,h=0;
    scanf("%lld",&v);
    v=v/10;
    while(v-2*h>1){
        c=((c*(v-2*h)*(v-2*h-1))/(h+1))/(v-h);
        h++;
        sum+=c;}
    printf("%lld",sum);
    return 0;
}