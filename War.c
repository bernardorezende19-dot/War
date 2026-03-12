#include <stdio.h>   // biblioteca para entrada e saída (printf, scanf, fgets, etc.)
#include <string.h>  // biblioteca para funções de manipulação de strings

// Definição de constantes para facilitar manutenção do código
#define N_TERR   5    // quantidade de territórios que serão cadastrados
#define NOME_SZ  30   // tamanho máximo do nome do território
#define COR_SZ   10   // tamanho máximo da cor do exército

/*
    Criação da estrutura Territorio.
    Essa struct representa um território do sistema,
    armazenando nome, cor do exército e número de tropas.
*/
struct Territorio {
    char nome[NOME_SZ]; // string para guardar o nome do território
    char cor[COR_SZ];   // string para guardar a cor do exército
    int  tropas;        // número de tropas no território
};

/*
    Função auxiliar para remover o caractere de quebra de linha (\n)
    que o fgets adiciona ao final da string quando o usuário pressiona ENTER.
*/
static void trim_nl(char *s)
{
    // procura a posição do primeiro \r ou \n e substitui por fim de string
    s[strcspn(s, "\r\n")] = '\0';
}

int main(void)
{
    /*
        Declaração de um vetor que armazena 5 estruturas do tipo Territorio.
        Cada posição do vetor representa um território cadastrado.
    */
    struct Territorio territorios[N_TERR];

    // Mensagem inicial do programa
    puts("=== Cadastro de Territorios ===");

    /*
        Laço para cadastrar os territórios.
        O loop se repete N_TERR vezes (5 vezes).
    */
    for (int i = 0; i < N_TERR; ++i) {

        // Mostra qual território está sendo cadastrado
        printf("\nTerritorio %d\n", i + 1);

        // Solicita o nome do território
        printf("Digite o nome do território: ");

        // fgets lê uma linha inteira digitada pelo usuário
        if (fgets(territorios[i].nome, sizeof territorios[i].nome, stdin) == NULL)
            return 1; // encerra o programa se ocorrer erro

        // remove o \n que o fgets pode adicionar
        trim_nl(territorios[i].nome);

        // Solicita a cor do exército
        printf("Digite a cor do exército: ");

        // lê a cor usando fgets
        if (fgets(territorios[i].cor, sizeof territorios[i].cor, stdin) == NULL)
            return 1;

        // remove o \n da string
        trim_nl(territorios[i].cor);

        // Solicita o número de tropas
        printf("Digite o número de tropas: ");

        // scanf lê um número inteiro digitado pelo usuário
        if (scanf("%d", &territorios[i].tropas) != 1) {
            fprintf(stderr, "entrada inválida\n"); // mostra erro
            return 1;
        }

        /*
            Limpa o buffer de entrada após o scanf.
            Isso evita que o ENTER digitado fique preso no buffer
            e interfira no próximo fgets.
        */
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }

    /*
        Após o cadastro, o programa percorre o vetor
        e exibe os dados de todos os territórios registrados.
    */
    puts("\n=== Territorios Cadastrados ===");

    for (int i = 0; i < N_TERR; ++i) {

        printf("\nTerritorio %d\n", i + 1);

        // Exibe o nome armazenado
        printf("Nome: %s\n", territorios[i].nome);

        // Exibe a cor do exército
        printf("Cor do Exército: %s\n", territorios[i].cor);

        // Exibe a quantidade de tropas
        printf("Número de Tropas: %d\n", territorios[i].tropas);
    }

    // Finaliza o programa indicando execução correta
    return 0;
}
