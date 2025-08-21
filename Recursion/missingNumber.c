#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int testCase;
    scanf("%d", &testCase);

    while (testCase--) {
        long long m, a, b, c; // Use long long for a, b, c to avoid overflow when multiplying
        scanf("%lld %lld %lld %lld", &m, &a, &b, &c);

        if (m == 0) {
            printf("0\n");
            continue;
        }

        long long product_abc = a * b * c;
        if (product_abc == 0) {
            printf("-1\n"); // Or handle as a special case if needed. Based on constraints, a,b,c are >= 1.
            continue;
        }

        if (m % product_abc == 0) {
            long long x = m / product_abc;
            printf("%lld\n", x);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
