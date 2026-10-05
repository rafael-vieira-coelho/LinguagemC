#include <stdio.h>
#include <stdlib.h> // Para a constante EXIT_FAILURE

int main(int argc, char *argv[]) {
    // 1. Validacao: garantir que o usuario passou um argumento
    if (argc != 2) {
        printf("Erro de sintaxe!\n");
        printf("Uso correto: %s <nome_do_arquivo>\n", argv[0]);
        return EXIT_FAILURE; // Finaliza o programa com erro
    }

    // 2. Abertura do arquivo usando o argumento 1
    // Aqui usamos argv[1] em vez de uma string fixa!
    FILE *arquivo = fopen(argv[1], "r");
    
    // Tratamento de erro (como vimos na Aula 10)
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // 3. Leitura e impressao na tela (Linha por Linha)
    char linha[256];
    printf("--- Conteudo do arquivo: %s ---\n", argv[1]);
    
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha); // Imprime a linha
    }

    // 4. Fechamento
    fclose(arquivo);
    return 0; // Sucesso
}