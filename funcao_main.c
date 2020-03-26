#include <stdio.h>

int main(int argc, char **argv) {
	printf("Nome do programa: %s \n\n", argv[0]);
	for (int i = 1; i < argc; i++) {
		printf("Argumento %i: %s\n", i, argv[i]);
	}
	return 0;
}