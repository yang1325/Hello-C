//loadercode
#include <stdio.h>
#define N 500
#define swap(x, y) {int tmp = x; x = y; y = tmp;}

void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);

int size;

int main(void)
{
    int array[N];
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    quicksort(array, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}

//mycode
void swaped(int a[],int c,int b){
    int d = a[c];
    a[c] = a[b];
    a[b] = d;
}
void quicksort2(int a[], int low, int high,int n) {
    int middle;
    if (low >= high) return;
    middle = partition(a, low, high);
    for(int i = 0;i <= n;i++){
        if(i == low)
            printf("[ ");
        if(i == middle)
            printf("*");
        printf("%d ", a[i]);
        if(i == high )
            printf("] ");
    }
    printf("\n");
    quicksort2(a, low, middle - 1, n);
    quicksort2(a, middle + 1, high, n);
}

void quicksort(int a[], int low, int high) {
    quicksort2(a, low, high, high);
}

int partition(int a[], int low, int high){
    int status = 0,i = 0,comparing = a[high];
    for(i = 0;i < high;i++){
        if(comparing >= a[i]){
            swaped(a,status,i);
            status++;
        }
    }
    swaped(a,status,high);
    return status;
}