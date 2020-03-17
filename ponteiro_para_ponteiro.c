#include <stdio.h>

int main(void) {
    int a, b, *p1, **p;

    p1 = &b;
    p = &p1;
    p = &p1;
    *p = &a;
    **p = 100;
    printf("&a = %p, a = %d \n", &a, a);
    printf("&b = %p, b = %d \n", &b, b);
    printf("&p1 = %p, p1 = %p, *p1 = %d \n", &p1, (void *) p1, *p1);
    printf("p = %p , **p = %d \n", (void *) p, **p);
    return 0;
}