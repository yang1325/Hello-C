#include<stdio.h>

int pairing(int number[], int max){
    int i = max, j, lonely = 0, one = number[0], target;
    int small[16] = {0};
    for(i = max; i > 1; i--){
        target = 0;
        j = 1;
        while(number[i] - target > 0){
            if(2*j > i)
                break;            
            else if(i == 2*j && number[j] > 1){
                number[j] = number[j] - 2;
                small[target] = j;
                target++;
                j = 1;
            }
            else if(number[j] > 0 && number[i-j] > 0){
                number[j] = number[j] - 1;
                number[i-j] = number[i-j] - 1;
                small[target] = j;
                target++;
                j = 1;
            }
            j++;
        }
        for(int k = 0; k < target; k++){
            number[small[k]] = number[ small[k]] + 1;
            number[i - small[k]] = number[i - small[k]] + 1;
        }
        for(int k = 0; k < target; k++){
            number[small[k]] = number[small[k]] - 1;
            number[i - small[k]] = number[i - small[k]] - 1;
            number[i] = number[i] - 1;
            if(pairing(number, max)){
                number[small[k]] = number[small[k]] + 1;
                number[i - small[k]] = number[i - small[k]] + 1;
                number[i] = number[i] + 1;
            }
        }
    }
    one = number[0];
    for(i = max; i >= 1; i--){
        if(number[i] > 0){
            lonely += number[i];
            one = i;
        }
    }
    
    if(lonely > 1){
        return 1;
    }
    number[0] = one;
    return 0;
}

int main () {
    int n, ans = 0, num, j, max = 0;
    int number[101] = {0};
    number[0] = 0;
    scanf("%d \n",&n);
    for(int i=1; i<=n; i++){
        scanf(" %d",&num);
        if(num > max){
            max = num;
        }
        number[num] = number[num] + 1;
    }
    pairing(number, max);
    printf("%d", number[0]);
    return 0;
}
