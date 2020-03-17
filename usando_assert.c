#include <stdio.h>
#include <assert.h>

int main() {
    int a, b;

    printf("Input an integer:\n");
    scanf("%d", &a);
    printf("Input an integer to divide:\n");
    scanf("%d", &b);

    assert(b != 0);

    printf("%d/%d = %.2f\n", a, b, a / (float) b);

    return 0;
}

