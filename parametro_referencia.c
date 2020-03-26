#include <stdio.h>

void imprimeValor(int *x) {
	(*x)++;
	printf("%d\n", *x);
}

int main() {
	int x = 10;
	printf("%d\n", x);    // 10
	imprimeValor(&x);  // 11
	printf("%d\n", x);    // 11
}