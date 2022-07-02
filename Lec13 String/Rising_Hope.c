//loader code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rising_hope(char *R);

int main(int argc, char *argv[])
{
    char in[1005];

    scanf("%s", in);
    int hope = rising_hope(in);
    printf("%d\n", hope);

    return 0;
}

//my code
int rising_hope(char *R) {
    int h = 0;
    char *r = R;
    while(*r != 0){
        if(*r == 'P')
            h++;
        if(*r == 'N')
            h--;
        r++;
    }
    return h;
}