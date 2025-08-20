#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() {
    int n,i,j;
    scanf("%d",&n);
    int a[n];
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    int min = a[0];

    for(i = 1; i < n; i++){
        if(a[i] < min){
            min = a[i];
        }
    }
    int count = 0;
    for(i = 0; i < n; i++){
        if(a[i] == min){
            count++;
        }
    }

    if(count % 2 == 1){
        printf("Lucky");
    }else{
        printf("Unlucky");
    }

    return 0;
}
