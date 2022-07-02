#include<stdio.h>
#include <string.h>

int comparing(char a[], char b[]){
    int i = 0, a_value = 0, b_value = 0;
    while(1){
        if(a[i] == 0)
            return -1;
        if(b[i] == 0)
            return 1;
        if('a'<= a[i] && a[i] <= 'z')
            a_value = a[i] - 'a';
        else if('A'<= a[i] && a[i] <= 'Z')
            a_value = a[i] - 'A';
        if('a'<= b[i] && b[i] <= 'z')
            b_value = b[i] - 'a';
        else if('A'<= b[i] && b[i] <= 'Z')
            b_value = b[i] - 'A';
        if(a_value != b_value)
            return a_value - b_value;
        i++;
    }
}

void sort_pointers(char *ptr_arr[], int size)
{
    char *p;
    if(size <= 1)
        return;
    for(int i = 0;i < size;i++){
        for(int j = 0;j < size- 1;j++){
            if(comparing(ptr_arr[j], ptr_arr[j + 1]) > 0){
                p = ptr_arr[j];
                ptr_arr[j] = ptr_arr[j + 1];
                ptr_arr[j + 1] = p;
            }
        }
    }
}

int main () {
    char name_list[100][100] = {0};
    char *name[100];
    int N;
    scanf("%d", &N);
    for(int i = 0;i < N;i++){
        scanf("\n%s", name_list[i]);
    }
    for(int i = 0;i < N;i++){
        name[i] = name_list[i];
    }
    sort_pointers(name, N);
    for(int i = 0;i < N;i++){
        printf("%s\n", name[i]);
    }
    return 0;
}
