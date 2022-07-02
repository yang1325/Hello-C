//loader code
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 1024

void convert_to_polar(int *coords, int N);

int main()
{
    int N, coords[MAX_N + 1][2];
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++)
        scanf("%d%d", &coords[i][0], &coords[i][1]);
    
    
    convert_to_polar((int *) coords, N);
    
    return 0;
}

//my code
void convert_to_polar(int *coords, int N)
{
    double degree_c = 180.0,degree = 0.0;
    for(int i = 0;i < N;i++){
        degree_c = 180.0;
        if(*(coords + 2 * i) >= 0){
            if(*(coords + 2 * i + 1) >= 0)
                degree_c -= 180.0;
            else
                degree_c += 180.0;
        }
        if(*(coords + 2 * i) == 0 && *(coords + 2 * i + 1) < 0)
            degree = -90.0;
        else if(*(coords + 2 * i) == 0)
            degree = 90.0;
        else
            degree = atan((*(coords + 2 * i + 1) * 1.0) / (*(coords + 2 * i) * 1.0))
            * 180.0 / acos(-1);
        printf("%.2f %.2f\n", degree + degree_c 
        , sqrt(*(coords + 2 * i + 1) * *(coords + 2 * i + 1) * 1.00 
               + *(coords + 2 * i) * *(coords + 2 * i) * 1.00));
    }
}

