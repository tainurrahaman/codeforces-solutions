#include<stdio.h>
#include <stdlib.h>
#include<limits.h>

int fun(int a[],int n,int i){
    if(i == n){
        return INT_MIN;
    }
   int max = fun(a,n,i+1);
    if(max > a[i]){
        return max;
    }else{
        return a[i];
    }
}

int main(){
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    int max = fun(a,n,0);
    printf("%d\n",max);
    return 0;
}
