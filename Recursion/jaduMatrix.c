#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n,m,i,j;
    scanf("%d%d",&n,&m);

     if (n != m) {
        printf("NO");
    }

    int arr[n][m];
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int flag = 1;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(i == j || (i+j) == n-1){
                if(arr[i][j] != 1){
                    flag = 0;
                }
            }
            else if(arr[i][j] != 0){
                flag = 0;
            }
        }
    }

    if (flag)
    {
        printf("YES");
    }else{
        printf("NO");
    }


    return 0;
}
