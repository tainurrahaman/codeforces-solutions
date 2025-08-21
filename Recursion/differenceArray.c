#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int test;
    scanf("%d",&test);
    while (test--)
    {
       int n,i,j;
    scanf("%d",&n);

    int arr[n],cpy[n],diff[n];
    for(i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    int size = sizeof(int) * n;
    memcpy(cpy,arr,size);

     for (i = 0; i < n-1; i++) {
        for(j = i; j < n; j++){
            if(cpy[i] > cpy[j]){
                int tmp = cpy[i];
                cpy[i] = cpy[j];
                cpy[j] = tmp;
            }
        }
    }

    for ( i = 0; i < n; i++) {
       diff[i] = abs(arr[i] - cpy[i]);
    }
    for (i = 0; i < n; i++) {
        printf("%d ", diff[i]);
    }
        printf("\n");
    }

    return 0;
}
