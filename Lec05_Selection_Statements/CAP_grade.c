#include<stdio.h>

int main () {
    int CH,SO,SC,score=10,points=5,A=0,B=0;
    float EN,MA;
    scanf("%d %f %f %d %d",&CH,&EN,&MA,&SO,&SC);
    if(CH>=41){
        A+=1;
        score+=4;
        if(CH>=45)
            points+=6;
        else if(CH>=43)
            points+=5;
        else
            points+=4;}
    else if(CH>=19){
        B+=1;
        score+=2;
        if(CH>=36)
            points+=3;
        else if(CH>=31)
            points+=2;
        else
            points+=1;}
    if(EN>=90.24){
        A+=1;
        score+=4;
        if(EN>=98.05)
            points+=6;
        else if(EN>=95.15)
            points+=5;
        else
            points+=4;}
    else if(EN>=38.75){
        B+=1;
        score+=2;
        if(EN>=81.58)
            points+=3;
        else if(EN>=69.83)
            points+=2;
        else
            points+=1;}
    if(MA>=81.73){
        A+=1;
        score+=4;
        if(MA>=94.23)
            points+=6;
        else if(MA>=90.19)
            points+=5;
        else
            points+=4;}
    else if(MA>=40.96){
        B+=1;
        score+=2;
        if(MA>=72.12)
            points+=3;
        else if(MA>=63.08)
            points+=2;
        else
            points+=1;}
    if(SO>=56){
        A+=1;
        score+=4;
        if(SO>=61)
            points+=6;
        else if(SO>=59)
            points+=5;
        else
            points+=4;}
    else if(SO>=23){
        B+=1;
        score+=2;
        if(SO>=48)
            points+=3;
        else if(SO>=39)
            points+=2;
        else
            points+=1;}
    if(SC>=46){
        A+=1;
        score+=4;
        if(SC>=52)
            points+=6;
        else if(SC>=50)
            points+=5;
        else
            points+=4;}
    else if(SC>=20){
        B+=1;
        score+=2;
        if(SC>=38)
            points+=3;
        else if(SC>=31)
            points+=2;
        else
            points+=1;}
    printf("%d/%d(",score,points);
    if(A!=0)
        printf("%dA",A);
    if(B!=0)
        printf("%dB",B);
    if(5-A-B!=0)
        printf("%dC",5-A-B);
    printf(")");
    return 0;
}
