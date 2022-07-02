#include<stdio.h>

void crop(int image[][100], int l, int r, int u, int d){
    for(int i = 0; i <= d - u; i++){
        for(int j = 0; j <= r - l; j++){
            image[i][j] = image[i + u -1][j + l -1];
        }
    }
}

void v_filp(int image[][100], int m, int n){
    int mediate;
    for(int i = 0; 2*i < m; i++){
        for(int j = 0; j < n; j++){
            mediate = image[i][j];
            image[i][j] = image[m - i - 1][j];
            image[m - i - 1][j] = mediate;
        }
    }
}

void h_filp(int image[][100], int m, int n){
    int mediate;
    for(int i = 0; i < m; i++){
        for(int j = 0; 2*j < n; j++){
            mediate = image[i][j];
            image[i][j] = image[i][n - j - 1];
            image[i][n - j - 1] = mediate;
        }
    }
}

void diagonal_filp(int image[][100], int max){
    int med;
    for(int i = 0; i < max; i++){
        for(int j = i; j < max; j++){
            med = image[i][j];
            image[i][j] = image[j][i];
            image[j][i] = med;
        }
    }
}

int main () {
    char mode;
    int image[100][100] = {0};
    int n, m, max, change = 0, l, r, d, u, med, r_number;
    scanf("%d %d", &m, &n);
    max = m;
    if(n > m)
        max = n;
    for(int i = 0; i < m; i++){
       for(int j = 0; j < n; j++){
           scanf("%d", &image[i][j]);
       }
    }
    scanf("%d", &change);
    for(int k = 0; k < change; k++){
        getchar();
        mode = getchar();
        switch(mode){
            case 'r':
                scanf(" %c %d", &mode, &r_number);
                if(mode == 'r'){
                    r_number %= 4;
                    r_number = 4 - r_number;
                }
                r_number %= 4;
                if(r_number > 1){
                    h_filp(image, m, n);
                    v_filp(image, m, n);
                    r_number -= 2;
                }
                if(r_number > 0){
                    diagonal_filp(image, max);
                    med = m;
                    m = n;
                    n = med;
                    v_filp(image, m, n);
                }                
                break;
            case 'c':
                scanf("%d %d %d %d", &l, &r, &u, &d);
                m = d - u + 1;
                n = r - l + 1;
                max = m;
                if(n > m)
                    max = n;
                crop(image, l, r, u, d);
                break;
            case 'h':
                h_filp(image, m, n);
                break;
            case 'v':
                v_filp(image, m, n);
                break;                
            case 'p':
            	for(int i = 0; i < m; i++){
					for(int j = 0; j < n; j++){
						printf("%d ", image[i][j]);
				}
				printf("\n");
				}
                printf("\n");
                break;
        }
    }
    return 0;
}
