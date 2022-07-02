#include <stdio.h>

int main () {
    int n;
    char beverage[2] = {0};
    long bt, wg, tt, gt, m, s, I, sugar, ice,sale = 0;
    scanf("%ld %ld %ld %ld %ld %ld %ld", &bt, &wg, &tt, &gt, &m, &s, &I);
    bt *= 1000;
    wg *= 1000;
    tt *= 1000;
    gt *= 1000;
    m *= 1000;
    s *= 1000;
    I *= 1000;
    scanf("%d",&n);
    for(int i = 0; i<n; i++){
        scanf("%s %ld/%ld", beverage, &sugar, &ice);
        switch(sugar){
            case 2: s -= 3;break;
            case 3: s -= 5;break;
            case 4: s -= 7;break;
            case 5: s -= 10;break;
        }
        switch(ice){
            case 2: I -= 30;break;
            case 3: I -= 50;break;
            case 4: I -= 70;break;
            case 5: I -= 100;break;
        }
        switch(beverage[0]){
            case 'B':
                if(beverage[1] == 'M'){
                    sale += 35;
                    bt -= 200;
                    m -= 300;
                }
                else{
                    sale += 20;
                    bt -= 500;
                }
                break;
            case 'G':
                if(beverage[1] == 'T'){
                    sale += 45;
                    gt -= 250;
                    tt -= 250;
                }
                else{
                    sale += 20;
                    gt -= 500;
                }
                break;
            case 'T':
                if(beverage[1] == 'M'){
                    sale += 45;
                    tt -= 200;
                    m -= 300;
                }
                else{
                    sale += 30;
                    tt -= 500;
                }
                break;
            case 'W':
                if(beverage[1] == 'T'){
                    sale += 40;
                    tt -= 350;
                    wg -= 150;
                }
                else if(beverage[1] == 'M'){
                    sale += 30;
                    wg -= 200;
                    m -= 300;
                }
                else{
                    sale += 15;
                    wg -= 500;
                }
                break;
        }
    }
    printf("%ld %ld %ld %ld %ld %ld %ld\n", bt, wg, tt, gt, m, s, I);
    printf("%ld", sale);
    return 0;
}
