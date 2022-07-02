#include<stdio.h>

int main () {
    int i,j=0,a,b,n;
    float status,win;
    scanf("%d",&n);
    while(j<n){
        i=0;
        status=0;
        while(i<3){
            scanf("%d %d",&a,&b);
            if(a>b)
                status+=1;
            else if(b>a)
                status-=1;
            i++;}
        if(status>0){
            printf("Win\n");
            win+=1.0;}
        else if(status<0)
            printf("Lose\n");
        else
            printf("Tie\n");
        j++;}
    printf("%.2f%%",(win/n)*100.0);
    return 0;
}
