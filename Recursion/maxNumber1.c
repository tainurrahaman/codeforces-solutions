#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int find_max(int a[],int n,int i){
    if(i == n-1){
        return a[i];
    }
    int max = find_max(a,n,i+1);
    if(a[i] > max){
       return a[i];
    }else{
    return max;
    }
}


int main() {
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    int result = find_max(a,n,0);
    printf("%d\n",result);

    return 0;
}

