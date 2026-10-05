#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct jogador {
    int   identificador;
    char  nome[30];
    float pontos;
    int   ranking;
} Jogador;

int main(int argc, char *argv[]) {
    // Validação dos argumentos necessários (Nome do programa + 5 parâmetros)
    if (argc != 6) {
        fprintf(stderr, "Uso: %s <arquivo.bin> <id> <nome> <pontos> <ranking>\n", argv[0]);
        return EXIT_FAILURE;
    }
    // Abre o ficheiro para escrita e leitura binária ("w+b" cria ou sobrescreve)
    FILE *arquivo = fopen(argv[1], "w+b");
    if (arquivo != NULL) {        
        Jogador player;
        // Atribuição dos dados passados via linha de comandos
        player.identificador = atoi(argv[2]);
        strncpy(player.nome, argv[3], sizeof(player.nome) - 1);
        player.nome[sizeof(player.nome) - 1] = '\0'; // Garante terminação nula
        player.pontos = atof(argv[4]);
        player.ranking = atoi(argv[5]);
        
        // Escrita da struct Jogador no ficheiro
        fwrite(&player, sizeof(Jogador), 1, arquivo);
        
        // Reposiciona o cursor no início do ficheiro para poder ler logo de seguida
        rewind(arquivo);
        
        // Leitura e verificação das structs Jogador gravadas
        while (fread(&player, sizeof(Jogador), 1, arquivo) == 1) {
            printf("ID: %d | NOME: %s | Pontos: %.2f | Ranking: %d\n", 
                    player.identificador, 
                    player.nome,
                    player.pontos,
                    player.ranking);
        }
        
        fclose(arquivo);
    } else {
        perror(argv[1]);
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}