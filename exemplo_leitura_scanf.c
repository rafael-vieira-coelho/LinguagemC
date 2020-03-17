#include <stdio.h>

int main() {
	char str2[50];

	printf("Digite um texto: ");
	scanf("%[^\n]", str2); fflush(stdin);
	printf("Texto 2: %s \n", str2);
	return 0;
}