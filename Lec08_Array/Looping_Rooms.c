#include<stdio.h>

int main () {
    int n,i,j,k,initial=-1,room=0;
    scanf("%d",&n);
    int a[n+1],b[n+1],c[n+1][n+1];
    for(i=0;i<n;i++)
        scanf("\n%d",&a[i]);
    for(i=0;i<=n;i++){
        b[i]=0;
        for(j=0;j<=n;j++)
            c[i][j]=-1;}
    i=0;
    j=0;
    while(1){
        k=0;
        i=0;
        while(b[i]==1)
            i++;
        if(i==n)
            break;
        while(b[i]==0){
            b[i]=1;
            c[j][k]=i;
            i=a[i];
            k++;}
        j++;}
    printf("%d rings\n",j);
    j=0;
    while(c[j][0]>-1){
        i=1;
        printf("%d -> ",c[j][0]);
        while(c[j][i]>-1)
            printf("%d -> ",c[j][i++]);
        printf("%d\n",c[j][0]);
        j++;}
    return 0;
}
