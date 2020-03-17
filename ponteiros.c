#include <stdio.h>

int main(void) {
    int *pointer;
    int value = 1;

    *pointer += 1;
    printf("*pointer = %d \n", *pointer);
    printf("value    = %d \n", value);
    return 0;
}