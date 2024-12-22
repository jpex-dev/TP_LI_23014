#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "operations.h"

void listarRefeicoesPorDia(const char* dia, Funcionario funcionarios[], int totalFuncionarios, Escolha escolhas[], int totalEscolhas) {
    printf("Refeições para o dia %s:\n", dia);
    for (int i = 0; i < totalEscolhas; i++) {
        if (strcmp(escolhas[i].dia, dia) == 0) {
            for (int j = 0; j < totalFuncionarios; j++) {
                if (funcionarios[j].numero == escolhas[i].numeroFuncionario) {
                    printf("%d - %s, Prato: %c\n", funcionarios[j].numero, funcionarios[j].nome, escolhas[i].tipoPrato);
                }
            }
        }
    }
}
