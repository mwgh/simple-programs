#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Save in array
int *threefib(int a0, int a1, int a2, int n, int *result) {
    int *T = NULL;
    if (n < 3) {
        switch (n) {
            case 0:
                *result = a0;
                return T;
            case 1:
                *result = a1;
                return T;
            case 2:
                *result = a2;
                return T;
            default:
                assert(0); // should never get here
        }
    }
    assert(n >= 3);
    T = malloc((n + 1) * sizeof(int));

    T[0] = a0;
    T[1] = a1;
    T[2] = a2;

    for (int i = 3; i < n + 1; i++) {
        T[i] = T[i - 1] + T[i - 2] - T[i - 3];
    }
    
    *result = T[n];
    return T;
}

int main() {
    int a0, a1, a2, n, tn;

    #ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif

    scanf("%d%d%d%d", &a0, &a1, &a2, &n);

    int *array = threefib(a0, a1, a2, n, &tn);
    printf("%d\n", tn);

    free(array);

    return 0;
}
