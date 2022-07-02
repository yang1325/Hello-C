#include <stdio.h>

int count(int n){
    if(n==1)
        return 1;
    else if (n%2==0)
        return count(n/2);
    else
        return count(n+1)+count(n-1);}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",count(n));
	return 0;
}