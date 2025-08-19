#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() {
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    int a[n];
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    if(n > 1){
        for(i = 0; i < n-1;i++){
        for(j = i+1; j < n; j++){
            if(a[i] < a[j]){
                int tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
        }
    }
    }
    long long sum = 0;
    for(i = 0; i < k; i++){
        if(a[i] > 0){
        sum+=a[i];
        }
    }

    printf("%lld\n",sum);
    return 0;
}
