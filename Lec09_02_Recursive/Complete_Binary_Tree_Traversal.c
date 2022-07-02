#include<stdio.h>

void findnode(int node[], int layer, int n,int mode, int number){
    if(mode == 0)
        printf("%d ", node[number - 1]);
    if(n >= 2*number)
        findnode(node, layer * 2, n, mode, 2*number);
    if(mode == 1)
        printf("%d ", node[number - 1]);    
    if(n >= 2*number + 1)
        findnode(node, layer * 2, n, mode, 2*number + 1);
    if(mode == 2)
        printf("%d ", node[number - 1]);    
}
int main () {
    int mode,n;
    scanf("%d",&mode);
    scanf("%d",&n);
    int node[n];
    for(int i = 0;i < n; i++)
        scanf("%d", &node[i]);
    findnode(node, 1, n, mode, 1);
    return 0;
}
