#include <stdio.h>

int main() {
    int i, n, t0 = 0, t1 = 1, ti;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci series: ");
    for (i = 1; i <= n; ++i){
        printf("%d ", t0);
        ti = t0 + t1;
        t0 = t1;
        t1 = ti;
    }

    return 0;
