#include <stdio.h>

int main(void){
    int x;
    scanf("%d",&x);
    printf("%d %d %d",(x/100),((x/10)%10),(x%10)*1);
    return 0;
}