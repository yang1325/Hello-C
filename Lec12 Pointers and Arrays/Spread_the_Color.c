//loader code
#include <stdio.h>
#define M 5
#define N 8
char colors[4] = {'R', 'G', 'B', 'X'};   // Red, Green, Blue, Empty

void spread(char*, int, int);

int main(void) {
    char graph[M][N];
    int row, col;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            scanf("%c", &graph[i][j]);
        getchar();      // Ignore '\n'
    }
    scanf("%d %d", &row, &col);    // Starting position
    
    spread(&graph[0][0], row, col);
    
    // Print out the spreading result
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            printf("%c", graph[i][j]);
        printf("\n");
    }
    return 0;
}

//my code
void spread(char *graph, int row, int col) {
    char ch = *( graph + row*8 + col);
    for(int i = col;i < 8;i++){
        if(*( graph + row*8 + i) == ch || *( graph + row*8 + i) == 'X')
            *( graph + row*8 + i) = ch;
        else
            break;
    }
    for(int i = col;i >= 0;i--){
        if(*( graph + row*8 + i) == ch || *( graph + row*8 + i) == 'X')
            *( graph + row*8 + i) = ch;
        else
            break;
    }
    for(int i = row;i < 5;i++){
        if(*( graph + i*8 + col) == ch || *( graph + i*8 + col) == 'X')
            *( graph + i*8 + col) = ch;
        else
            break;
    }
    for(int i = row;i >= 0;i--){
        if(*( graph + i*8 + col) == ch || *( graph + i*8 + col) == 'X')
            *( graph + i*8 + col) = ch;
        else
            break;
    }
}