#include<stdio.h>
void cor(long num){
    /*紀錄位數的變數i*/
    int i = 0;
    long first = 0, second = 0, number = num, odd, even;
    /*判斷得來的數字來自第幾個字元,單數次(不可被16^2整除的位置)讀取到的數字加到"first", 雙數次(可被16^2整除的位置)的加到"second"*/
    while(number != 0){
        if(i % 2)
            second += number % 16;
        else
            first += number % 16;
        i++;
        number /= 16;
    }
    /*將上述結果轉換成題目規定的index*/
    if(i % 2){
        even = first;
        odd = second;}
    else{
        even = second;
        odd = first;
    }
    /*如果變數值小於16印出變數值本身*/
    if(i < 2)
        printf("%lx",first);
    /*先執行奇數的部分,再執行偶數的部分(符合題目要求的方式)*/
    else{
        cor(odd);
        cor(even);
    }
}
int main () {
    /*初始化變數,"i"用來存讀取的字元的位置*/
    int i = 0;
    /*"odd"和"even"用來記錄總和*/
    long odd = 0, even = 0, term;
    char ch;
    /*連續讀取字元*/
    ch = getchar();
    while(ch != '\n'){
        term = 0;
        /*把字元"ch"換成等值數字"term"*/
        switch(ch){
            case 'f':
            case 'F':term++;
            case 'e':
            case 'E':term++;
            case 'd':
            case 'D':term++;
            case 'c':
            case 'C':term++;
            case 'b':
            case 'B':term++;
            case 'a':
            case 'A':term++;
            case '9':term++;
            case '8':term++;
            case '7':term++;
            case '6':term++;
            case '5':term++;
            case '4':term++;
            case '3':term++;
            case '2':term++;
            case '1':term++;
            case '0':break;
        }
        /*判斷得來的數字來自第幾個字元,單數次位置讀取到的數字加到"odd", 雙數次位置的加到"even"*/
        if(i % 2)
            odd += term;
        else
            even += term;
        /*繼續讀取*/
        ch = getchar();
        i++;
    }
    /*cor是我定義的函數*/
    cor(odd);
    cor(even);
    return 0;
}
