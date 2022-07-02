#include <stdio.h>
//把數字換成字元的函數
char num(int x){
    switch(x){
        case 0:return '0';break;
        case 1:return '1';break;
        case 2:return '2';break;
        case 3:return '3';break;
        case 4:return '4';break;
        case 5:return '5';break;
        case 6:return '6';break;
        case 7:return '7';break;
        case 8:return '8';break;
        case 9:return '9';break;
        default:return ' ';break;
    }
}
//印出字串中的字元,直到字元為零的函數
void str_print(char str[]){
    int i = 0;
    while(str[i] != 0){
        printf("%c", str[i]);
        i++;
    }
    printf("\n");
}
//壓縮字串的函數
void compress(char str[]){
    int i = 0, j = 0, digit = 0;
    char word[1026] = {0}, ch = ' ';
    int count[1026] = {0};
    j = 0;
    //用兩個array來分別存取字串中的每個連續字元和出現的頻率
    while(str[i] != 0){
        word[j] = str[i];
        while(str[i] == str[i + count[j]] && str[i] != 0)
            count[j] = count[j] + 1;
        i += count[j];
        j++;
    }
    i = 0;
    j = 0;
    while(word[j] != 0){
        //用前面的array存取到的資料,用"-'c'"來個別取代原字串
        str[i] = '-';
        str[i + 1] = word[j];
        i += 2;
        digit = 1;
        //在原字串中根據數字的大小填入數字
        if(count[j] >= 1000){
            str[i + 3] = num(count[j] % 10);
            count[j] /= 10;
            digit++;
        }
        if(count[j] >= 100){
            str[i + 2] = num(count[j] % 10);
            count[j] /= 10;
            digit++;
        }
        if(count[j] >= 10){
            str[i + 1] = num(count[j] % 10);
            count[j] /= 10;
            digit++;
        }
        str[i] = num(count[j]);
        i += digit;
        j++;
    }
    //在字串末尾添上0,然後將字串印出
    str[i] = 0;
    str_print(str);
}

//換大小寫的函數
void change(char str[],char direction){
    int i = 0;
    //換成小寫
    if(direction == 'L'){
        while(str[i] != 0){
            if('A' <= str[i] && str[i] <= 'Z')
                str[i] = str[i] - 'A' + 'a';
            i++;
        }
    //換成大寫
    }else{
        while(str[i] != 0){
            if('a' <= str[i] && str[i] <= 'z')
                str[i] = str[i] - 'a' + 'A';
            i++;
        }        
    }
    //印出字串
    str_print(str);
}
//移除字元的函數
void removed(char str[],char del){
    char med;
    int indicator = 0, i = 0;
    while(str[i] != 0){
        //如果發現字元需要被刪除,就令該字元為零
        if(str[i] == del){
            str[i] = 0;
            i++;
        }
        //否則將該字元置換到前面
        else{
            med = str[i];
            str[i] = 0;
            str[indicator] = med;
            i++;
            indicator++;
        }
    }
    //印出字串
    str_print(str);
}

void reverse(char str[]){
    char med;
    int n = 0;
    //找出字串長度
    while(str[n] != 0)
        n++;
    //由前至後置換字元
    for(int i = 0; 2*i < n; i++){
        med = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = med;
    }
    str_print(str);
}

int main () {
    char ch = ' ';
    char str[1026] = {0}, command[9] = {0};
    int i = 0,n = 0;
    ch = getchar();
    //讀取字串
    while(ch != '\n'){
        str[i] = ch;
        i++;
        ch = getchar();
    }
    //讀取指令並執行
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        getchar();
        scanf("%s", command);
        switch(command[0]){
            case 'C':
                compress(str);
                break;
            case 'T':
                change(str, command[3]);
                break;
            case 'P':
                str_print(str);
                break;
            case 'R':
                if(command[2] == 'V')
                    reverse(str);
                else{
                    getchar();
                    ch = getchar();
                    removed(str, ch);
                    }
                break;
        }
    }
    return 0;
}