//loader code
#include <stdio.h>
#define NUM 9

void check_sudoku(int grid_p[][NUM]);

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}

//mycode
#include <stdio.h>
#define NUM 9
void check_sudoku(int grid_p[][NUM]){
    int determine = 0, r, c;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            determine = 0;
            for(int k=0; k<9; k++){
                if( k == i)
                    continue;
                if( grid_p[k][j] == grid_p[i][j])
                    determine = 1;}
            for(int k=0; k<9; k++){
                if( k == j)
                    continue;
                if( grid_p[i][k] == grid_p[i][j]){
                    determine = 1;}}
            r = i / 3;
            c = j / 3;
            for(int k = 3*r ; k <3*r + 3; k++){
                for(int l = 3*c ; l <3*c + 3; l++){
                    if( k == i && l == j)
                        continue;
                    if( grid_p[k][l] == grid_p[i][j])
                         determine = 1;}}
            if(determine == 1)
                printf("(%d,%d)\n",i,j);
        }}
}