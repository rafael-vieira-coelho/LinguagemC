#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Total de argumentos (argc): %d\n\n", argc);
    
    // Um loop simples para varrer o vetor de strings argv
    for (int i = 0; i < argc; i++) {
        printf("Posicao %d (argv[%d]): %s\n", i, i, argv[i]);
    }
    
    return 0;
}