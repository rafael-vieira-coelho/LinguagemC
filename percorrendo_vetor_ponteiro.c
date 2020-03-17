#include <stdio.h>

#define SIZE (10)

int main() {
    size_t i = 0;
    int *p = NULL;
    int a[SIZE];

    /* Setting up the values to be i*i */
    for (i = 0; i < SIZE; ++i) {
        a[i] = i * i;
    }
    /* Reading the values using pointers */
    for (p = a; p < a + SIZE; ++p) {
        printf("%d\n", *p);
    }
    return 0;
}