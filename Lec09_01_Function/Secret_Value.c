//leader code
#include <stdio.h>
#define MODULUS 10007
int getSecret(int n);
int gcd(int a, int b);

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", getSecret(n));
	return 0;
}

//my code
int gcd(int a, int b){
    b=b%a;
    if(b==0)
        return a;
    else
        return gcd(b,a);
}

int getSecret(int n){
    long int k=0,m=n,digit=1;
    if(n/10==0)
        return n;
    else{
        while(n!=0){
            n/=10;
            k++;}
        while(k>0){
            digit*=10;
            k-=2;}
        int k=(m+getSecret(gcd(m/digit,m%digit)))%10007;
        return k;}
}