#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    // Validação para garantir que o nome do ficheiro foi fornecido
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <arquivo_texto.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;
    ssize_t line_size;
    
    // Abre o ficheiro recebido em argv[1] para leitura
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "Erro ao abrir o ficheiro '%s'\n", argv[1]);
        return EXIT_FAILURE;
    }
    
    // Lê a primeira linha do ficheiro
    line_size = getline(&line_buf, &line_buf_size, fp);
    
    // Percorre o ficheiro até ao fim
    while (line_size >= 0) {
        line_count++;
        printf("linha[%06d]: chars=%06zd, buf size=%06zu, conteudo: %s", 
                line_count, line_size, line_buf_size, line_buf);
        
        line_size = getline(&line_buf, &line_buf_size, fp);
    }
    
    // Liberta a memória alocada para o buffer e fecha o ficheiro
    free(line_buf);
    line_buf = NULL;
    fclose(fp);
    
    return EXIT_SUCCESS;
}