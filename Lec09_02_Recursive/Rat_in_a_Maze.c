//loader code
#include <stdio.h>
#include <stdbool.h>
#define n 5

bool visit(char [][n], int [][n], int, int);
int main(void) {
    char maze[n][n];
    int route[n][n];
    // initialize maze and route matrices
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
	        route[i][j]=0;
	        scanf("%c", &maze[i][j]);
	        getchar();
	    }
    }
    if (visit(maze, route, 0, 0)) { // (0,0) is a starting point
        for (int i=0; i<n; i++) {
	        for (int j=0; j<n; j++)
	            printf("%d ", route[i][j]);
	        printf("\n");
        }
    } else {
	    printf("Can't find the exit!");
    }
    return 0;
}

//mycode
// TODO: fill the route matrix with 0's or 1‘s.
// If there isn't any route, return false; otherwise, return true.

//這裡是定義一個比原函數多一個紀錄行走方向'direction'的變數的函數"visited",再讓原函數visit呼叫這個函數
bool visited(char maze[][n], int route[][n], int originX, int originY,char direction) {
    //如果超出邊界就判定是不可走的路,回傳false
    if(originX <= -1 || originX >= 5)
        return false;
    else if(originY <= -1 || originY >= 5)
        return false;
    //如果是牆壁'w'就判定是不可走的路,回傳false
    else if(maze[originX][originY] == 'w')
        return false;
    //如果是(4,4)就判定是可以走的路,將(4,4)改為1,回傳true
    else if(originX == 4 && originY == 4){
        route[4][4] = 1;
        return true;
    }
    //定義一個布林代數a來儲存四個方向的結果,如果其中一個回傳的值為真,則a為真
    bool a = false;
    //先排除drection的反方向,以避免如:走上去又走下來的無限循環
    //然後查看剩下的三個方向能不能通往(4,4)
    if(direction != 'u')
        a = a || visited(maze, route, originX, originY + 1, 'd');
    if(direction != 'l')
        a = a || visited(maze, route, originX + 1, originY, 'r');
    if(direction != 'd')
        a = a || visited(maze, route, originX, originY - 1, 'u');
    if(direction != 'r')
        a = a || visited(maze, route, originX - 1, originY, 'l');
    //如果a為真,則標記這是可走的路(route[originX][originY] = 1;),然後把'真'的值傳給來時的方向
    if(a){
        route[originX][originY] = 1;
        return true;
    }
    //否則則回傳false
    return false;
}

//原函數'visit'呼叫'visited'函數
bool visit(char maze[][n], int route[][n], int originX, int originY){
    return visited(maze, route, originX, originY, 'd');
}
