#include<stdio.h>

int main () {
    unsigned long long sum=0;
    unsigned long K,Y=1;
    int i=0,S,N;
    scanf("%d\n",&N);
    while(i<N){
        scanf("%d",&S);
        if(S==16){
            scanf(" %lx",&K);
            sum+=K;}
        else if(S==8){
            scanf(" %lo",&K);
            sum+=K;}
        else if(S==10){
            scanf(" %lu",&K);
            sum+=K;}
        else{
            scanf(" %lu",&K);
            while(K>0){
                sum+=(K%10)*Y;
                Y*=6;
                K/=10;}
            Y=1;}
        i++;}
    printf("%lld",sum%1000000007);
    return 0;
}
