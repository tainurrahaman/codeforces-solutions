#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long log2_recursive(int n){
    if(n == 1){
        return 0;
    }else{
        return 1 + log2_recursive(n/2);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Using the built-in log2 function from <math.h> for an accurate result
    long long result = log2(n);
    printf("%lld\n",result);

    return 0;
}

