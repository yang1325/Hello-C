//loader code
#include<stdio.h>
#include<string.h>

void add(char a[], char b[], char res[]);

int main(){
    char a[100], b[100], res[105];
    scanf("%s %s", a, b);
    add(a, b, res);
    printf("%s", res);
    return 0;
}

//mycode
void swap(char *a, char *b) {
    char ch = *a;
    *a = *b;
    *b = ch;
}

void reverse_caterpillar(char *l, char *r) {
    char *R = r, *L = l;
    while(R > L){
        swap(R, L);
        R--;
        L++;
    }
}

void add(char a[], char b[], char res[]){
    char *A = a, *B = b;
    int decimal = 0, value = 0, a_value = 0, b_value = 0, i = 0;
    reverse_caterpillar(A , A + strlen(A) - 1);
    reverse_caterpillar(B , B + strlen(B) - 1);
    while(*A != 0 || *B != 0){
        a_value = 0;
        b_value = 0;
        if(*A != 0){
            a_value = *A - '0';
            A++;
        }
        if(*B != 0){
            b_value = *B - '0';
            B++;
        }
        value = a_value + b_value + decimal;
        decimal = 0;
        if(value > 9){
            decimal = 1;
            value -= 10;
        }
        *(res + i) = value + '0';
        i++;
    }
    if(decimal == 1){
        *(res + i) = '1';
        i++;
    }
    *(res + i) = 0;
    reverse_caterpillar(res , res + strlen(res) - 1);
}