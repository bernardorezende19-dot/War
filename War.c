#include <stdio.h>
#include <string.h>

#define N_TERR   5
#define NOME_SZ  30
#define COR_SZ   10

struct Territorio {
    char nome[NOME_SZ];
    char cor[COR_SZ];
    int  tropas;
};

static void trim_nl(char *s)
{
    s[strcspn(s, "\r\n")] = '\0';
}

int main(void)
{
    struct Territorio territorios[N_TERR];

    puts("=== Cadastro de Territorios ===");

    for (int i = 0; i < N_TERR; ++i) {
        printf("\nTerritorio %d\n", i + 1);

        printf("Digite o nome do território: ");
        if (fgets(territorios[i].nome, sizeof territorios[i].nome, stdin) == NULL)
            return 1;
        trim_nl(territorios[i].nome);

        printf("Digite a cor do exército: ");
        if (fgets(territorios[i].cor, sizeof territorios[i].cor, stdin) == NULL)
            return 1;
        trim_nl(territorios[i].cor);

        printf("Digite o número de tropas: ");
        if (scanf("%d", &territorios[i].tropas) != 1) {
            fprintf(stderr, "entrada inválida\n");
            return 1;
        }
        /* descarta o '\n' que ficou no buffer */
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }

    puts("\n=== Territorios Cadastrados ===");
    for (int i = 0; i < N_TERR; ++i) {
        printf("\nTerritorio %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do Exército: %s\n", territorios[i].cor);
        printf("Número de Tropas: %d\n", territorios[i].tropas);
    }

    return 0;
}