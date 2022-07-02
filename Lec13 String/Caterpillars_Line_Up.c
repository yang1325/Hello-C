//loader code
#include<stdio.h>
#include<stdbool.h>

void lineup_again(char line[]);
void swap(char *a, char *b);
void reverse_caterpillar(char *l, char *r);

int main() {
    char line[1000000];
    scanf("%s", line);
    lineup_again(line);
    printf("%s", line);
}

//my code
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

void lineup_again(char line[]) {
    char *s = line, *e = line + 1;
    while(*e != 0){
        while(*e != 'A' && *e != 'Z')
            e++;
        if(*s != 'A')
            reverse_caterpillar(s, e);
        s = e + 1;
        e = e + 2;
    }
}