#include<stdio.h>

int main () {
    int a,b,c;
    float d;
    scanf("%d %d",&a,&b);
    c=(100-a)*b;
    d=c/100.0;
    printf("\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\n");
    printf("\\%7d%%off!    \\\n",a);
    printf("\\ Before  $%5d \\\n",b);
    printf("\\ After   $%5.2f \\\n",d);
    printf("\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"");
    return 0;
}
