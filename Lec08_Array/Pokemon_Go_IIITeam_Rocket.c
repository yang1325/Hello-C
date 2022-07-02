#include<stdio.h>

int main () {
    int box,n,plans[26]={0};
    char plan,a='A',alpherbet[26];
    for(int i=0;i<26;i++)
        alpherbet[i]=a+i;
    scanf("%d",&n);
    while(n-->0){
        scanf("\n%d %c",&box,&plan);
        if ('A' <= plan && plan <= 'Z' )
            plans[plan-'A']=box;
        }
    for(int i=0;i<26;i++){
        if(plans[i]==0)
            printf("Not found plan %c.\n",alpherbet[i]);
        else
            printf("Plan %c is in box %d.\n",alpherbet[i],plans[i]);}
    return 0;
}
