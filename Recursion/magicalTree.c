#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n,k,i,j;
    scanf("%d",&n);

    k = ceil((double) n / 2);
    int spacePlus = n /2;
    int space = 5 + spacePlus;
    int star = 1;

    for (i = 0; i < 5+k; i++)
    {
        // Space print
        for(j = 0; j < space; j++){
                printf(" ");
            }
        // star print
        for(j = 0; j < star; j++){
                printf("*");
            }
        space--;
        star+=2;
        printf("\n");
    }
    for(i = 0; i < 5;i++){
           // Space print
        for(j = 0; j < 5; j++){
                printf(" ");
            }
        // star print
        for(j = 0; j < n; j++){
                printf("*");
            }
            printf("\n");
    }

    return 0;
}
