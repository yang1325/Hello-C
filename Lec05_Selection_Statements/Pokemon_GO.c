#include<stdio.h>

int main () {
    int n,cp,hp,s,catch_number;
    scanf("%d \n%d %d\n %d",&n,&cp,&hp,&s);
    catch_number=1;
    if(cp>600){
        catch_number+=14;
        if(hp>200)
            catch_number+=10;}
    else if(cp>=100){
        catch_number+=4;
        if(hp>100)
            catch_number+=3;}
    if((s>4)&(catch_number>6))
        printf("NO");
    else if(catch_number>n)
        printf("NO");
    else{
        printf("YES\n");
        printf("%d",n-catch_number);}
    return 0;
}
