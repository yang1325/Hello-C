//loader code
#include <stdio.h>
int *report_card (int *s) ;

int main () {
    int score[1001];
    int *show;
    int count = 0;

    do {
        scanf("%d", &score[count++]);
    } while (score[count - 1] != -1);

    show = report_card(score);

    count = 0;
    while (*(show + count) != -1) {
        printf("%d ", *(show + count));
        count++;
    }
}

//my code
int *report_card (int *s) {
    int i = 0, count = 0 , max_count = 0, score = 0, max_score = 0;
    int index = 0, max_index = 0;
    while(*(s + i) != -1){
        while(*(s + i) >= 60){
            if(count == 0)
                index = i;
            count += 1;
            score += *(s + i);
            if(*(s + i + 1) < 60)
                break;
            i++;
        }
        if(count > max_count){
            max_score = score;
            max_count = count;
            max_index = index;
        }
        else if(count == max_count && score > max_score){
            max_score = score;
            max_count = count;
            max_index = index;
        }
        score = 0;
        count = 0;
        i++;
    }
    for(int i = 0;i < max_count;i++)
        *(s + i) = *(s + max_index + i);
    *(s + max_count) = -1;
    return s;
}