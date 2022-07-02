//loader code
#include <stdio.h>
#define SIZE 201

void modify_array(int *);

int main(void) {
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    modify_array(&arr[SIZE/2]);
    for (int i = 1; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

//mycode
void modify_array(int *p) {
    for(int i = 1;i < 201;i++){
        if(i % 2 == 1 && *(p - 100) == 1)
            *(p - 100 + i) += 10;
        if(i % 3 == 1 && *(p - 100) == 2)
            *(p - 100 + i) *= 8;
        if(i % 5 == 1 && *(p - 100) == 3)
            *(p - 100 + i) -= 2;
    }
}