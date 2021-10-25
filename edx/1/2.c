#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long long a, b;

    #ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif

    scanf("%lld%lld", &a, &b);
    printf("%lld\n", a + b*b);

    return 0;
}

