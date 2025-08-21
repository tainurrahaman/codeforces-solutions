#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int testCase;
    scanf("%d",&testCase);
    while ((testCase--))
    {
       int n,i;
    scanf("%d",&n);

    char str[n];
    scanf("%s",&str);
    int countT = 0, countP = 0;
    int len = strlen(str);

    for(i = 0; i < len; i++){
        if(str[i] == 'T'){
            countT++;
        }else if(str[i] == 'P'){
            countP++;
        }
    }

    if(countP > countT){
        printf("Pathaan\n");
    }
    else if(countT > countP){
        printf("Tiger\n");
    }else{
        printf("Draw\n");
    }
    }

    return 0;
}
