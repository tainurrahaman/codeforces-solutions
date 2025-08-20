#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void moveZeros(int a[], int n){
    int i;
    int count = 0;
    for(i = 0; i < n; i++){
        if(a[i] != 0){
            a[count++] = a[i];
        }
    }
    while (count < n)
    {
        a[count++] = 0;
    }

}

int main() {
    int n,i;
    scanf("%d",&n);

    int a[n];
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    moveZeros(a,n);
    for(i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}
