#include<stdio.h>
#include <stdlib.h>

void fun(int n){
    if(n == 0) return;
    int x = n % 10;
    fun(n/10);
    printf("%d ",x);
}

int main(){
    int test;
    scanf("%d",&test);
    while (test--)
    {
        int n;
        scanf("%d",&n);

        if(n==0){
            printf("0\n");
        }else{
            fun(n);
            printf("\n");
        }

    }

    return 0;
}
