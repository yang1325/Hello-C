#include <stdio.h>

int main(void){
    int s,max=1,n=1;
    scanf("%d",&s);
    while(s!=1){
        if(s>max)
            max=s;
        if(s%2==0)
            s=s/2;
        else
            s=3*s+1;
        n++;}
    printf("%d %d",n,max);
    return 0;
}
