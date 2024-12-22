// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "operations.h"

#define MAX_FUNCIONARIOS 200
#define MAX_EMENTAS 50
#define MAX_ESCOLHAS 1000

void exibirMenu() {
    printf("\nMenu de Opções:\n");
    printf("1. Carregar dados dos funcionários\n");
    printf("2. Carregar ementa semanal\n");
    printf("3. Carregar escolhas dos utentes\n");
    printf("4. Listar refeições por dia\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    Ementa ementas[MAX_EMENTAS];
    Escolha escolhas[MAX_ESCOLHAS];
    int totalFuncionarios = 0, totalEmentas = 0, totalEscolhas = 0;
    int opcao;
    char dia[10];

    do {
        exibirMenu();
        scanf_s("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
        case 1:
            carregarFuncionarios("utentes.txt", funcionarios, &totalFuncionarios);
            printf("Funcionários carregados: %d\n", totalFuncionarios);
            break;

        case 2:
            carregarEmenta("ementa.txt", ementas, &totalEmentas);
            printf("Ementas carregadas: %d\n", totalEmentas);
            break;

        case 3:
            carregarEscolhas("escolhas.txt", escolhas, &totalEscolhas);
            printf("Escolhas carregadas: %d\n", totalEscolhas);
            break;

        case 4:
            printf("Digite o dia para listar as refeições (ex.: 2feira): ");
            fgets(dia, sizeof(dia), stdin);
            dia[strcspn(dia, "\n")] = '\0'; // Remove o \n do final
            listarRefeicoesPorDia(dia, funcionarios, totalFuncionarios, escolhas, totalEscolhas);
            break;

        case 5:
            printf("Saindo do programa.\n");
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }

    } while (opcao != 5);

    return 0;
}
