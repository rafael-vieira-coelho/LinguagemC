#include <stdio.h>

int my_function(int a, int b) {
    return 2 * a + 3 * b;
}

/* Using the function pointer as an argument to another function */
void another_function(int (*another_pointer)(int, int)) {
    int a = 4;
    int b = 2;
    int result = (*another_pointer)(a, b);
    printf("Result: %d \n", result);
}

int main(void) {
    int (*my_pointer)(int, int);

    my_pointer = &my_function;

    /* Calling the pointed function */
    int result = (*my_pointer)(4, 2);

    printf("Result: %d \n", result);
    another_function(my_pointer);
    return 0;
}