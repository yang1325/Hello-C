#include<stdio.h>

void rail_fence(char str[], int key[], int length, int min){
    char string[8] = {0};
    for(int i = min;i < 64;i = i + length){
        for(int j = 0;j < length;j++)
            string[key[j] - 1] = str[i + j];
        for(int j = 0;j < length;j++)
            str[i + j] = string[j];
    }
}
   
void rotate_right(char str[], int number,int min, int max){
    char ch = str[max - 1];
    for(int i = max - 1; i > min; i--)
        str[i] = str[i-1];
    str[min] = ch;
    if(number > 1)
        rotate_right(str, number - 1, min, max);
}

void tretimus(char str[], int k, int max,int mode){
    int i, place, count = 0;
    char ch;
    k = k%26;
    for(i = 0;i < max;i++){
        ch = str[i];
        if ('a' <= ch && ch <= 'z' ){
            place = k + (260 + mode * count);
            place = place % 26;
            ch = ch - 'a' + place;
            str[i] = ( ch % 26 ) + 'a';
            count++;
        }
        if ('A' <= ch && ch <= 'Z' ){
            place = k + (260 + mode * count);
            place = place % 26;
            ch = ch - 'A' + place;
            str[i] = ( ch % 26 ) + 'A';
            count++;
        }
    }
}

void vigenere(char str[], char key[], int length, int min, int max){
    int k = 0, place;
    char ch;
    for(int i = min;i < max;i++){
        k = k % length;
        place = (key[k] - 'a') % 26;
        if ('a' <= str[i] && str[i] <= 'z' ){
            ch = str[i] - 'a' + place;
            str[i] = ( ch % 26 ) + 'a';
            k++;
        }
        if ('A' <= str[i] && str[i] <= 'Z' ){
            ch = str[i] - 'A' + place;
            str[i] = ( ch % 26 ) + 'A';
            k++;
        }
    }
}

void swapped(char str[], int mid){
    char ch;
    for(int i = 0;i < mid;i++){
        ch = str[i];
        str[i] = str[i + mid];
        str[i + mid] = ch;
    }
}

int main () {
    int i,mode;
    int pkey2[8] = {4, 3, 1, 2, 7, 6, 5, 8}, pkey31[4] = {3, 2, 4, 1};
    int pkey32[8] = {1, 8, 4, 3, 6, 5, 7, 2}, pkey52[4] = {2, 4, 1, 3};
    int pkey51[8] = {3, 1, 7, 6, 4, 5, 2, 8};
    char ch = ' ', str[64] = {0}, key4[4] = {'m', 'e', 'o', 'w'};
    char key8[8] = {'v', 'i', 'g', 'e', 'n', 'e', 'r', 'e'};
    scanf("%d", &mode);
    getchar();
    for(i = 0;i < 64;i++)
        str[i] = getchar();
    switch(mode){
        case 1:
            swapped(str, 32);
            tretimus(str, 13, 32, 0);
            vigenere(str, key4, 4, 32, 64);
            rotate_right(str, 61, 0, 64);
            break;
        case 2:
            rotate_right(str, 11, 0, 64);
            tretimus(str, 74, 64, 1);
            rotate_right(str, 1, 0, 32);
            rotate_right(str, 3, 32, 64);
            rail_fence(str, pkey2, 8, 0);
            break;
        case 3:
            rail_fence(str, pkey31, 4, 0);
            tretimus(str, 8, 32, 0);
            rail_fence(str, pkey32, 8, 32);
            swapped(str, 32);
            tretimus(str, 602, 64, -1);
            rotate_right(str, 7, 0, 64);
            break;
        case 4:
            vigenere(str, key8, 8, 0, 32);
            rotate_right(str, 40, 32, 64);
            swapped(str, 16);
            tretimus(str, 3, 32, 1);
            rotate_right(str, 19, 0, 64);
            break;
        case 5:
            rail_fence(str, pkey51, 8, 0);
            tretimus(str, 10, 32, 0);
            rail_fence(str, pkey52, 4, 32);
            swapped(str, 32);
            tretimus(str, 52, 64, 1);
            rotate_right(str, 7, 0, 64);
    }
    for(i = 0;i < 64;i++)
        printf("%c",str[i]); 
    return 0;
}
