#include <stdio.h>

int main(void){
    int k;
    char ch=' ';
    scanf("%d\n",&k);
    k=k%26;
    ch= getchar();
    while(ch!='\n'){
        if ('a' <= ch && ch <= 'z' ){
            ch = ch - 'a' + k +26;
            ch=(ch%26) + 'a';}
        if ('A' <= ch && ch <= 'Z' ){
            ch = ch -'A' + k + 26;
            ch=(ch%26) + 'A';}
        printf("%c",ch);
        ch= getchar();}
    return 0;
}
