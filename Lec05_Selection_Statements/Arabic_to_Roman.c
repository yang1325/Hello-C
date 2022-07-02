#include <stdio.h>

int main(void){
    int x;
    scanf("%d",&x);
    if(x>=3000)
        printf("MMM");
    else if(x>=2000)
        printf("MM");
    else if(x>=1000)
        printf("M");
    x=x%1000;
    if(x>=900){
        x=x%100;
        printf("CM");}
    else if(x>=500)
        printf("D");
    else if(x>=400){
        x=x%100;
        printf("CD");}
    x=x%500;
    if(x>=300)
        printf("CCC");
    else if(x>=200)
        printf("CC");
    else if(x>=100)
        printf("C");
    x=x%100;
    if(x>=90){
        x=x%10;
        printf("XC");}
    else if(x>=50)
        printf("L");
    else if(x>=40){
        x=x%10;
        printf("XL");}
    x=x%50;
    if(x>=30)
        printf("XXX");
    else if(x>=20)
        printf("XX");
    else if(x>=10)
        printf("X");
    x=x%10;
    if(x>=9){
        x=0;
        printf("IX");}
    else if(x>=5)
        printf("V");
    else if(x>=4){
        x=0;
        printf("IV");}
    x=x%5;
    if(x>=3)
        printf("III");
    else if(x>=2)
        printf("II");
    else if(x>=1)
        printf("I");
    return 0;
}
