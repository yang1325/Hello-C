//loader code
#include <stdio.h>

void star(int*, int*);

int main()
{
    int arr[5], result;
    for(int i=0; i<5; i++)
        scanf("%d", &arr[i]);
    
    star(arr, &result);

    printf("%d", result);

    return 0;
}

//my code
void star(int *arr, int *result) {
    *result = *(arr + 0) + *(arr + 1) + *(arr + 2) + *(arr + 3) + *(arr + 4); 
}