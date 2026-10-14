
#include <stdio.h>
#include <string.h>

#define MAX_ATIVOS 3

typedef struct {
    char nome[30];
    char categoria[20];
    float quantidade;
    float precoCompra;
    float precoAtual;
} Ativo;

/* Prototipos das funcoes */
void cadastrarAtivo(Ativo ativos[], int *quantidade);
void listarAtivos(Ativo ativos[], int quantidade);
double calcularValorTotal(Ativo ativos[], int quantidade);

int main(void) {
    Ativo ativos[MAX_ATIVOS];
    int quantidade = 0;
    int opcao;

    do {
        printf("\n=== Controle de Carteira ===\n");
        printf("1 - Cadastrar ativo\n");
        printf("2 - Listar ativos\n");
        printf("3 - Valor total da carteira\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida.\n");

            int caractere;
            while ((caractere = getchar()) != '\n' &&
                   caractere != EOF) {
                /* Limpa a entrada */
            }

            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1:
                cadastrarAtivo(ativos, &quantidade);
                break;

            case 2:
                listarAtivos(ativos, quantidade);
                break;

            case 3:
                printf("Valor atual total: %.2f\n",
                       calcularValorTotal(ativos, quantidade));
                break;

            case 0:
                printf("Encerrando.\n");
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}

void cadastrarAtivo(Ativo ativos[], int *quantidade) {
    if (*quantidade >= MAX_ATIVOS) {
        printf("Carteira cheia.\n");
        return;
    }

    printf("Digite nome categoria quantidade precoCompra precoAtual: ");

    if (scanf("%29s %19s %f %f %f",
              ativos[*quantidade].nome,
              ativos[*quantidade].categoria,
              &ativos[*quantidade].quantidade,
              &ativos[*quantidade].precoCompra,
              &ativos[*quantidade].precoAtual) != 5) {

        printf("Dados invalidos. Cadastro cancelado.\n");

        int caractere;
        while ((caractere = getchar()) != '\n' &&
               caractere != EOF) {
            /* Limpa a entrada */
        }

        return;
    }

    (*quantidade)++;

    printf("Ativo cadastrado.\n");
}

void listarAtivos(Ativo ativos[], int quantidade) {
    int i;

    if (quantidade == 0) {
        printf("Nenhum ativo cadastrado.\n");
        return;
    }

    printf("\n=== Ativos cadastrados ===\n");

    for (i = 0; i < quantidade; i++) {
        printf("\nAtivo %d\n", i + 1);
        printf("Nome: %s\n", ativos[i].nome);
        printf("Categoria: %s\n", ativos[i].categoria);
        printf("Quantidade: %.2f\n", ativos[i].quantidade);
        printf("Preco de compra: %.2f\n", ativos[i].precoCompra);
        printf("Preco atual: %.2f\n", ativos[i].precoAtual);
    }
}

double calcularValorTotal(Ativo ativos[], int quantidade) {
    double total = 0.0;
    int i;

    for (i = 0; i < quantidade; i++) {
        total += (double)ativos[i].quantidade
                 * ativos[i].precoAtual;
    }

    return total;
}
