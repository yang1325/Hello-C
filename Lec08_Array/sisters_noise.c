#include <stdio.h>

int main(void){
    const int c=10;
    int a[c];
    int max=0;
    for(int r=0;r<c;r++)
        scanf(" %d",&a[r]);
    for(int i=0;i<c;i++)
        for(int j=i;j<c;j++)
            if((a[i]+a[j])*(j-i)>max)
                max=(a[i]+a[j])*(j-i);
    printf("%d",max);
    return 0;
}
