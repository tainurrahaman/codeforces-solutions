#include<stdio.h>
#include <stdlib.h>

long long int factorial(int a){
    if(a <= 1) return 1;
    return (long long int)a * factorial(a-1);
}

int main(){
    int n;
    scanf("%d",&n);

    long long int result = factorial(n);
    printf("%lld\n",result);
    return 0;
}
