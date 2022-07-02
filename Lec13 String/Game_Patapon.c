#include<stdio.h>
#include <string.h>

int read_command(int *hp, int *dis, int *i,int *move){
    int j = 0,defence = 0;
    char string[4][6] = {0},play[5] = "", ch;
    scanf("%s %s %s", string[0], string[1], string[2]);
    getchar();
    ch = getchar();
    while(ch != ',' && ch != '.' && ch != '\n'){
        string[3][j] = ch;
        ch = getchar();
        j++;
    }
    for(j = 0;j < 4;j++){
        if(strcmp(string[j],"PON") == 0)
            play[j] = '1';
        else if(strcmp(string[j],"PATA") == 0)
            play[j] = '2';
        else if(strcmp(string[j],"CHAKA") == 0)
            play[j] = '3';
        else
            play[j] = '0';
    }
    play[4] = 0;
    if(strcmp(play,"2221") == 0){
        *dis -= 1;
        *move += 1;
    }
    else if(strcmp(play,"1121") == 0){
        if(*dis < 4)
            *hp -= 1;
        *move += 1;
    }
    else if(strcmp(play,"3321") == 0){
        *dis += 1;
        defence = 1;
        *move += 1;
    }
    if(*hp == 0 || ch == '\n' || *dis == 0)
        return 0;
    else if(*i % 10 == 0 && defence == 0)
        return 0;
    else
        return 1;
}

int main () {
    int i = 0, dis, hp, ok = 1, move = 0;
    scanf("%d %d\n", &dis, &hp);
    while(ok){
        i++;
        ok = read_command(&hp, &dis, &i, &move);
    }
    if(hp == 0)
        printf("YES %d", move);
    else
        printf("NO %d", hp);
    return 0;
}
