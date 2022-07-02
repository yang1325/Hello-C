//loader code
#include <stdio.h>
#define MAX_LEN 20000

void swap(int *, int *);

int main() {
  int n, A[MAX_LEN], B[MAX_LEN];

  // read input
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &A[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &B[i]);

  // swapping
  for (int i = 0; i < n; ++i)
    swap(&A[i], &B[i]);

  // output
  for (int i = 0; i < n; ++i)
    printf("%d ", A[i]);
  putchar('\n');
  for (int i = 0; i < n; ++i)
    printf("%d ", B[i]);

  return 0;
}

//mycode
void swap(int *a, int *b) {
    int c = *a;
    if(*b > *a){
       *a = *b;
       *b = c;
    }        
}