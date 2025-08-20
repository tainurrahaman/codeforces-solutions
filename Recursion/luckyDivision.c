#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n,i;
    scanf("%d",&n);

    int lucky_numbers[] = {4,7,44,47,74,77,444,447,474,477,744,747,774,777};
    int result = 0;

    for(i = 0; i <sizeof(lucky_numbers) / sizeof(lucky_numbers[0]); i++){
        if(n % lucky_numbers[i] == 0){
            result = 1;
            break;
        }
    }
    if(result){
        printf("YES\n");
    }else{
        printf("NO\n");
    }

    return 0;
}
